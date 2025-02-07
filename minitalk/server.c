/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:18:31 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/07 14:57:12 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "Funs/ft_printf.h"

int tag(void) {
    ft_printf("\n");
    ft_printf("\n");
    ft_printf("\t\t\t\t\t\t\t███╗   ███╗███╗   ██╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
    ft_printf("\t\t\t\t\t\t\t████╗ ████║████╗  ██║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
    ft_printf("\t\t\t\t\t\t\t██╔████╔██║██╔██╗ ██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n");
    ft_printf("\t\t\t\t\t\t\t██║╚██╔╝██║██║╚██╗██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n");
    ft_printf("\t\t\t\t\t\t\t██║ ╚═╝ ██║██║ ╚████║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
    ft_printf("\t\t\t\t\t\t\t╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
    ft_printf("\n");
    ft_printf("\t\t\t\t\t\t\t                            1 3 3 7\n");

    ft_printf("\n");
    return 0;
}

void signal_handler(int signum, siginfo_t *info, void *content)
{
    (void)*content;
    static int bit_count = 0;
    static char character = 0;
    static pid_t pid = 0;

    if (pid == 0)
        pid = info->si_pid;
    if (info->si_pid != pid)
    {
        pid = info->si_pid;
        bit_count = 0;
        character = 0;
    }
    character |= (signum == SIGUSR2) << (7 - bit_count);
    bit_count++;

    if (bit_count == 8)
    {
        if (character == '\0')
        {
            write(1, "\n", 1);
            bit_count = 0;
            character = 0;
            return;
        }
        write(1, &character, 1);
        bit_count = 0;
        character = 0;
    }
}


int main(void)
{
    struct sigaction sig;
    //printf("Server PID: %d\n", getpid());

    tag();
    ft_printf("\n   Server PID  →  \t%d\n", getpid());
	sig.sa_sigaction = signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}

