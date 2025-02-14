/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:18:31 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/14 10:40:51 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "Funs/ft_printf.h"

int tag(void) {
    ft_printf("\n");
    ft_printf("\n");
    ft_printf("\t\t\t\t\t\t\t███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
    ft_printf("\t\t\t\t\t\t\t████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
    ft_printf("\t\t\t\t\t\t\t██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n");
    ft_printf("\t\t\t\t\t\t\t██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n");
    ft_printf("\t\t\t\t\t\t\t██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
    ft_printf("\t\t\t\t\t\t\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
    ft_printf("\n");
    ft_printf("\t\t\t\t\t\t\t                            1 3 3 7\n");

    ft_printf("\n");
    return 0;
}

static unsigned char current_char = 0; // Variable to store the current character
static int bit_count = 0; // Counter to track the number of bits received

void signal_handler(int signum, siginfo_t *info, void *context)
{
    (void)context;
    static pid_t pid = 0;

    if (pid == 0)
        pid = info->si_pid;
    if (info->si_pid != pid)
    {
        pid = info->si_pid;
        bit_count = 0;
        current_char = 0;
    }

    if (signum == SIGUSR2)
        current_char |= 1 << (7 - bit_count);  // Set the bit if SIGUSR2
    else
    current_char |= (0 << (7 - bit_count)); 

    // Increment the bit counter
    bit_count++;

    // If 8 bits have been received, process the character
    if (bit_count == 8)
    {
        // Check if the received character is the null character
        if (current_char == '\0') //?
        {
            // Print a newline to indicate the end of the message
            write(1, "\n", 1);
            // Reset for the next message
            bit_count = 0;
            current_char = 0;
            return;
        }
        write(1, &current_char, 1);
        current_char = 0;
        bit_count = 0;
    }
}


int main(void)
{
    struct sigaction sig;
    //printf("Server PID: %d\n", getpid());

    tag();
    ft_printf("\n   Server PID  →  \t%d\n", getpid());

    // Set up the sigaction structure
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;

    // Register the signal handler for SIGUSR1 and SIGUSR2
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
