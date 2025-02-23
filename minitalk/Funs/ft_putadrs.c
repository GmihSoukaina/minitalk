/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:44:59 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/06 19:21:11 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadrs(unsigned long nbr, char hex, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_putadrs((nbr / 16), hex, len);
		ft_putadrs((nbr % 16), hex, len);
	}
	else
		ft_putchar(base[nbr], len);
}
