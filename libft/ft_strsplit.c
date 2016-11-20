/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:50:06 by narlati           #+#    #+#             */
/*   Updated: 2016/11/13 11:45:12 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int		ft_word_count(char const *s, char c)
{
	int			word;
	int			i;

	i = 0;
	word = (s[0] == c) ? 0 : 1;
	while ((s[i] != '\0') && (s[i + 1] != '\0'))
	{
		if (s[i] == c && s[i + 1] != c)
			word++;
		i++;
	}
	return (word);
}

static char		*ft_strdup_c(const char *s, char c)
{
	char		*s1;
	char		*s1_return;

	if (!(s1 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	s1_return = s1;
	while (*s != '\0' && *s != c)
		*s1++ = *s++;
	*s1 = '\0';
	return (s1_return);
}

static void		ft_word_count_f(char **r, char const *s, char c)
{
	int			sw;
	int			nbw;

	sw = 1;
	nbw = 0;
	while (*s != '\0')
	{
		if (*s == c)
			sw = 1;
		else
		{
			if (sw == 1)
				r[nbw++] = ft_strdup_c(s, c);
			sw = 0;
		}
		s++;
	}
	r[nbw] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		nb;

	nb = ft_word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	ft_word_count_f(result, s, c);
	result[nb] = NULL;
	return (result);
}
