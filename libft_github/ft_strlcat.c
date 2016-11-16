/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:45:24 by narlati           #+#    #+#             */
/*   Updated: 2016/11/11 09:04:04 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t final_i;

	i = 0;
	while (dest[i] != '\0' && i < n)
		i++;
	final_i = i;
	while (src[i - final_i] != '\0' && i < n - 1)
	{
		dest[i] = src[i - final_i];
		i++;
	}
	if (final_i < n)
		dest[i] = '\0';
	return (ft_strlen(src) + final_i);
}
