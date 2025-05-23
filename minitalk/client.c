/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:12:15 by sgmih             #+#    #+#             */
/*   Updated: 2025/02/20 10:12:17 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "Funs/ft_printf.h"

static int	check(int s)
{
	if (s == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	c;
	int		signe;
	long	tmp;

	i = 0;
	c = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = c;
		c = c * 10 + (str[i] - '0');
		if (c / 10 != tmp)
			return (check(signe));
		i++;
	}
	return (signe * c);
}

static void	send_signal(int pid, char c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (((c >> (7 - j)) & 1) == 1)
		{
			if (kill (pid, SIGUSR2) == -1)
			{
				write (1, "Sending Error!", 14);
				exit(1);
			}
		}
		else
		{
			if (kill (pid, SIGUSR1) == -1)
			{
				write (1, "Sending Error!", 14);
				exit(1);
			}
		}
		usleep(600);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc != 3 || ft_atoi(argv[1]) == 0)
	{
		ft_printf ("\nInput no valid \tEnter:  ~ PID   MSG ~ \n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0 || pid > PID_MAX_LIMIT)
		return (write (1, "invalid Pid!", 12));
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, '\0');
}
