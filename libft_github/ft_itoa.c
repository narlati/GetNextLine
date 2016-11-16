/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:04:29 by narlati           #+#    #+#             */
/*   Updated: 2016/11/13 10:56:45 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_negative(int *n, int *negative, int *lenght)
{
	if (*n < 0)
	{
		++*negative;
		*n = -*n;
		++*lenght;
	}
}

char		*ft_itoa(int n)
{
	char	*result;
	int		lenght;
	int		temp;
	int		negative;

	negative = 0;
	temp = n;
	lenght = 2;
	ft_negative(&n, &negative, &lenght);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (temp /= 10)
		lenght++;
	if (!(result = (char *)ft_memalloc(sizeof(char) * (lenght + negative))))
		return (NULL);
	result[lenght + negative] = '\0';
	lenght--;
	while (lenght--)
	{
		result[lenght] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		result[0] = '-';
	return (result);
}
