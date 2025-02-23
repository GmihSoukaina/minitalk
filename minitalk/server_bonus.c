/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:19:08 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/20 13:00:28 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "Funs/ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

static void	reset_signal_data(unsigned char *current_char, int *bit_count,
								int *byte_index, char *g_buffer)
{
	*current_char = 0;
	*bit_count = 0;
	*byte_index = 0;
	ft_memset(g_buffer, 0, sizeof(g_buffer));
}

static void	handle_byte(unsigned char *current_char, char *g_buffer,
						int *byte_index, int pid)
{
	g_buffer[*byte_index] = *current_char;
	(*byte_index)++;
	if ((g_buffer[0] & 0x80) == 0x00)
	{
		write(1, g_buffer, 1);
		*byte_index = 0;
	}
	else if ((g_buffer[0] & 0xE0) == 0xC0 && *byte_index == 2)
	{
		write(1, g_buffer, 2);
		*byte_index = 0;
	}
	else if ((g_buffer[0] & 0xF0) == 0xE0 && *byte_index == 3)
	{
		write(1, g_buffer, 3);
		*byte_index = 0;
	}
	else if ((g_buffer[0] & 0xF8) == 0xF0 && *byte_index == 4)
	{
		write(1, g_buffer, 4);
		*byte_index = 0;
	}
	if (*byte_index == 0 && !g_buffer[0])
		(kill(pid, SIGUSR1), write(1, "\n", 1));
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_count;
	static int				pid;
	static char				g_buffer[5];
	static int				byte_index;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		reset_signal_data(&current_char, &bit_count, &byte_index, g_buffer);
	}
	if (sig == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		handle_byte(&current_char, g_buffer, &byte_index, pid);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = handle_signal;
	sig.sa_flags = SA_SIGINFO;
	ft_printf("\n   Server PID  →  \t%d\n", getpid());
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
