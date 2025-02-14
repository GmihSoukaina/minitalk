/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:18:31 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/14 12:49:09 by sgmih            ###   ########.fr       */
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

void	reset(pid_t *pid, unsigned char *current_char, int *bit_count)
{
	*pid = 0;
	*current_char = 0;
	*bit_count = 0;
}

static void	handle_bit(int signum, unsigned char *current_char, int *bit_count)
{
	if (signum == SIGUSR2)
		*current_char |= 1 << (7 - *bit_count);
	else
		*current_char |= (0 << (7 - *bit_count));
	(*bit_count)++;
}

static void process_char(unsigned char *current_char, int *bit_count)
{
    if (*bit_count == 8)
    {
        if (*current_char == '\0')
        {
            write(1, "\n", 1);
            *bit_count = 0;
            *current_char = 0;
            return ;
        }
        write(1, current_char, 1);
        *current_char = 0;
        *bit_count = 0;
    }
}

void signal_handler(int signum, siginfo_t *info, void *context)
{
    (void)context;
    static pid_t pid;
	static unsigned char current_char ;
	static int bit_count ;

	pid = 0;
	current_char = 0;
	bit_count = 0;
    if (pid == 0)
        pid = info->si_pid;
    if (info->si_pid != pid)
		reset(&pid, &current_char, &bit_count);
	handle_bit(signum, &current_char, &bit_count);
    process_char(&current_char, &bit_count);
}


int main(void)
{
    struct sigaction sig;
    tag();
    ft_printf("\n   Server PID  →  \t%d\n", getpid());
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
