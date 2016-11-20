/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:24:43 by narlati           #+#    #+#             */
/*   Updated: 2016/11/11 14:15:44 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	if (ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	while (s1[i] != '\0' && ft_strlen(s2) <= len)
	{
		while (ft_memcmp(&s1[i], &s2[k], ft_strlen(s2)) == 0)
			return (&((char *)s1)[i]);
		k = 0;
		i++;
		len--;
	}
	return (NULL);
}
