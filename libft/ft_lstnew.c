/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:58:50 by narlati           #+#    #+#             */
/*   Updated: 2016/11/21 11:19:56 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if(content == NULL)
		content_size = 0;
	if (!(new = malloc(sizeof(*new))))
			return (NULL);
	new->next = NULL;
	if (content != NULL)
		ft_memcpy(new->content, content, content_size);
	else
		new->content = NULL;
	new->content_size = content_size;	
	return (new);
}
