/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:41:47 by narlati           #+#    #+#             */
/*   Updated: 2016/11/10 14:48:25 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*s1;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!(s1 = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (NULL);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	while (j - i >= 0)
	{
		s1[k] = s[i];
		i++;
		k++;
	}
	s1[k] = '\0';
	return (s1);
}
