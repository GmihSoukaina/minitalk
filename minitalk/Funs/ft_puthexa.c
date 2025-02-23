/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmih <sgmih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:34:41 by sgmih             #+#    #+#             */
/*   Updated: 2024/12/06 11:44:09 by sgmih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nbr, char hex, int *len)
{
	char	*base;

	if (hex == 'x')
		base = "0123456789abcdef";
	else if (hex == 'X')
		base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ft_puthexa((nbr / 16), hex, len);
		ft_puthexa((nbr % 16), hex, len);
	}
	else
		ft_putchar(base[nbr], len);
}
