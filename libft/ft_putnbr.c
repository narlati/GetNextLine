/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:33:19 by narlati           #+#    #+#             */
/*   Updated: 2016/11/10 13:01:40 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	positive(int n)
{
	if (n >= 10)
		positive(n / 10);
	ft_putchar(n % 10 + '0');
}

void		ft_putnbr(int n)
{
	if (n >= 0)
		positive(n);
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		n = -n;
		ft_putchar('-');
		positive(n);
	}
}
