/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsgned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:22:05 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/05 21:26:34 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsgned(unsigned int nbr, int *len)
{
	long	n;

	n = nbr;
	if (n <= 9)
		ft_putchar((n + 48), len);
	else
	{
		ft_putunsgned((n / 10), len);
		ft_putunsgned((n % 10), len);
	}
}
