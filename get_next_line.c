/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/21 16:09:00 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int				get_next_line(const int fd, char **line)
{
	static t_buffer *tt = NULL;
	int ret;
	int p;

	tt->buffer = &buffer[BUFF_SIZE];
	ret = read(fd, tt->buffer, BUFF_SIZE);
	if ((ret == -1) || (fd == -1))
		return (-1);
	while (ret >= 0)
	{
		p = ft_solve(tt->buffer, line, ret);
		if (p == 1)
			return (1);
		else if (p == 0)
			return (0);
		ret = read(fd, tt->buffer, BUFF_SIZE);
	}
	return (0);
}

int main (int argc, char **argv)
{

	int fd;
	char *line;

	fd = open(argv[1], O_RDWR);
	printf("%d\n", get_next_line(fd, &line));
	free (line);
	close (fd);
	return (0);
}
