/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:40:19 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/06 10:53:51 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *len)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		ft_putchar('-', len);
		n = n * -1;
	}
	if (n <= 9)
		ft_putchar((n + 48), len);
	else
	{
		ft_putnbr((n / 10), len);
		ft_putnbr((n % 10), len);
	}
}
