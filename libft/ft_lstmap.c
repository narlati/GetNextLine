/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:54:36 by narlati           #+#    #+#             */
/*   Updated: 2016/11/21 11:04:52 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list    *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *rett;
	t_list *tmp;

	ret = (*f)(lst);
   	rett = ret;
	lst = lst->next;
	while (lst != NULL && ret != NULL)
	{
		tmp = (*f)(lst);
		if (tmp == NULL)
			return (NULL);
		rett->next = tmp;
		rett = rett->next;
		lst = lst->next;
	}
	return (ret);
}
