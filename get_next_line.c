/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/23 17:14:03 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

void            free_and_del(t_buffer *tt)
{
	if (tt == NULL)
		return ;
//	printf("--%p--\n", tt);
//	printf("->%p--\n", tt->next);
	free_and_del(tt->next);
}

void		init_list(t_buffer **tt, int *fd)
{
	t_buffer init;
	init.fd = *fd;
	if (init.buffer == NULL)
		init.buffer= malloc(BUFF_SIZE);
	*tt = init;	
}

int			solver(t_buffer *tt, char **line, int ret)
{
	char string_buff[ret + 1];

	if (ft_memchr(tt->buffer, '\n', BUFF_SIZE))
	{
		size_t asdfghj = ft_memchr(tt->buffer, '\n', BUFF_SIZE) - (void*)tt->buffer;
		*line = ft_strjoin(*line, ft_strsub(tt->buffer, 0, asdfghj));
		tt->buffer = ft_memchr(tt->buffer, '\n', BUFF_SIZE) + 1;
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
	static t_buffer *tt;
	int ret;

	if (fd == -1)
		return (-1);
	*line = ft_strnew(0);
	init_list(*tt, &fd);
//	if (tt == NULL)
//		tt = ft_init_list(fd, tt);
	while ((ret = read(fd, tt->buffer, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		else
		{
			if (solver(tt, line, ret) == 1)
				return (1);
			else
				;
		}
	}
//	free_and_del(tt);
//	tt = NULL;
	return (0);
}

/*
int main (int argc, char **argv)
{

	int fd;
	char *line;
	int i = 0;

	while (i <argc)
		i++;
	fd = open(argv[1], O_RDWR);
	printf("%d\n", get_next_line(fd, &line));
	printf("line vaut %s\n", line);
	free (line);
	close (fd);
	return (0);
}*/
