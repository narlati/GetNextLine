/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:13:46 by narlati           #+#    #+#             */
/*   Updated: 2016/12/07 14:10:22 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(const char *str, int *i)
{
	(*i)++;
	if (str[*i] == '+')
		return (0);
	return (str[*i]);
}

static int	is_positive(const char *str, int *i)
{
	(*i)++;
	if (str[*i] == '-')
		return (0);
	return (str[*i]);
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
						|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		if (is_negative(str, &i) == 0)
			return (0);
	}
	if (str[i] == '+')
		is_positive(str, &i);
	while ((str[i] != '\0') && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (int)str[i] - 48;
		i++;
	}
	return (sign * result);
}
