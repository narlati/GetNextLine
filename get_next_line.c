/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/24 14:25:24 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>  

void		init_list(t_buffer **tt, int const fd)
{
	if (*tt == NULL)
	{
		*tt = malloc(sizeof(tt));
		(*tt)->fd = fd;
		(*tt)->buffer = malloc(BUFF_SIZE);
		(*tt)->next = NULL;
	}
}

int			solver(t_buffer *tt, char **line, int ret)
{
	char string_buff[ret + 1];

	if (ft_memchr(tt->buffer, '\n', ret))
	{
		size_t asdfghj = ft_memchr(tt->buffer, '\n', ret) - (void*)tt->buffer;
		*line = ft_strjoin(*line, ft_strsub(tt->buffer, 0, asdfghj));
		ft_memmove(tt->buffer, ft_memchr(tt->buffer, '\n', ret) + 1, BUFF_SIZE - asdfghj + 1);
		return (1);
	}
	else
	{
		ft_memcpy(string_buff, tt->buffer, ret);
		string_buff[ret] = '\0';
		*line = ft_strjoin(*line, string_buff);
		if (ret == BUFF_SIZE)
			return (42);
		return (0);
	}
	return (42);
}

int				get_next_line(const int fd, char **line)
{
	static t_buffer *tt = NULL;
	int ret;
	int s;

	if (fd == -1)
		return (-1);
	*line = ft_strnew(0);
	init_list(&tt, fd);
	while ((ret = read(fd, tt->buffer, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		s = solver(tt, line, ret);
		if (s == 1)
			return (1);	
		else if (s == 0)
			return (0);
		else
			;
	}
//	free_and_del(&tt);
//	tt = NULL;
	return (0);
}


int main (int argc, char **argv)
{

	int fd;
	char *line;
	int i = 0;
	int s;

	while (i <argc)
		i++;
	fd = open(argv[1], O_RDWR);
	s = get_next_line(fd, &line);
	while (s > 0)
	{
		printf("line = %s\n", line);
		printf("GNL = %d\n", s);
		s = get_next_line(fd, &line);
	}
	free (line);
	close (fd);
	return (0);
}
