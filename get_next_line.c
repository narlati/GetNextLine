/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/23 08:24:11 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

t_buffer	*ft_init_list(const int fd, t_buffer *yy)
{
	if (yy == NULL)
	{
		yy = malloc(sizeof(yy));
		yy->buffer = NULL;
		yy->fd = fd;
		yy->next = NULL;
	}
	else
	{
		while (yy != NULL && yy->fd != fd)
		{
			yy = yy->next;
			if (yy == NULL)
			{
				yy = malloc(sizeof(yy));
				yy->buffer = NULL;
				yy->fd = fd;
				yy->next = NULL;
			}	
		}
	}
	return (yy);
}	

int			test_retour_chariot(t_buffer *yy, char **line)
{
	char *tmp;
	if (yy->buffer != NULL && (tmp = ft_strchr(*line, '\n')))
	{	
		**line = *ft_strjoin(*line, ft_strsub(yy->buffer, 0, tmp - yy->buffer));
		yy->buffer = tmp + 1;
		return (1);
	}
	return (0);
	
}

int				get_next_line(const int fd, char **line)
{
	static t_buffer *tt = NULL;
	int ret;
	char buffer[BUFF_SIZE] = {0};

	ret = read(fd, buffer, BUFF_SIZE);
	if ((ret == -1) || (fd == -1))
		return (-1);
	*line = ft_strnew(0);
	tt = ft_init_list(fd, tt);
	if (test_retour_chariot(tt, line))
		return (1);
	prin

/*
	if (ret > 0)
	{
		return(4);
	}
	*line = malloc(BUFF_SIZE + 1);
*/
	return (0);
}

int main (int argc, char **argv)
{

	int fd;
	char *line;
	int i = 0;

	while (i <argc)
		i++;
	fd = open(argv[1], O_RDWR);
	printf("%d\n", get_next_line(fd, &line));
	free (line);
	close (fd);
	return (0);
}
