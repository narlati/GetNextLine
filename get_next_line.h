/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:45:47 by narlati           #+#    #+#             */
/*   Updated: 2016/11/21 15:27:39 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5

typedef struct		s_buffer
{
	char			*buffer;
	int				fd;
	struct s_buffer	*next;
}					t_buffer;

int 			get_next_line(const int fd, char **line);

#endif
