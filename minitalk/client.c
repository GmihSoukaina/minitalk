/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:12:15 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/12 17:31:09 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "Funs/ft_printf.h"

void	send_signal(int pid, char c)
{
	int	j;

	j = 0;
	while (j++ < 8)
	{
		if (((c >> (8 - j)) & 1) == 1)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(800);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

    i = 0;
	if (argc != 3 || atoi(argv[1]) == 0)
	{
		ft_printf ("\nInput no valid \tEnter:  ~ PID   MSG ~ \n");
		return (0);
	}
	pid = atoi(argv[1]);
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, '\0');
}