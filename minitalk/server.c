/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:18:31 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/20 11:40:34 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "Funs/ft_printf.h"

int	tag(void)
{
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n");
	ft_printf("████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n");
	ft_printf("██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n");
	ft_printf("██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n");
	ft_printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
	ft_printf("\n");
	ft_printf("\t\t\t   1 3 3 7\n");
	ft_printf("\n");
	return (0);
}

void	reset(unsigned char *current_char, int *bit_count)
{
	*current_char = 0;
	*bit_count = 0;
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t			pid;
	static unsigned char	current_char;
	static int				bit_count;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
		(reset(&current_char, &bit_count), pid = info->si_pid);
	if (signum == SIGUSR2)
		current_char |= 1 << (7 - bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
		{
			write(1, "\n", 1);
			reset(&current_char, &bit_count);
			return ;
		}
		write(1, &current_char, 1);
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	tag();
	ft_printf("\n   Server PID  →  \t%d\n", getpid());
	sig.sa_sigaction = signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
