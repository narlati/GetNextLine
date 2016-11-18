/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/18 17:57:32 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int ft_solve(char *buffer, char **line, size_t max)
{
	size_t i;
	size_t j;
	char *s;
	char *transi;

	s = malloc(sizeof(char) * max);
	transi = ft_strdup(*line);
	free(*line);
	ft_memcpy((char *)s, (char *) buffer, max);
	i = 0;
	j = 0;
	while (i < max)
	{
		if (buffer[i] == '\n')
		{ 
			*buffer =  
			*line = ft_strjoin(transi, avantle\n);
			return (1);
		}
		else if (buffer[i] == '\0')
		{
			*line = ft_strjoin(transi, ce quil y a jusqua '\0');
			return (0);
		}
		else
			*line = ft_strjoin(transi, buffer);
		i++;	
	}
	free (s);
	free(transi);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buffer = NULL;
	int			ret;
	int 		i;
	int			p;

	i = 0;
	if (buffer == NULL)
		buffer = malloc(BUFF_SIZE);
	*line = malloc(BUFF_SIZE + 1);
	**line = '\0';
	ret = read(fd, buffer, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	while (ret >= 0)
	{
		p = ft_solve(buffer, line, ret);
		if (p == 1)
			return (1);
		else if (p == 0)
			return (0);
		ret = read(fd, buffer, BUFF_SIZE);
	}
	return (0);
}

int main (int argc, char **argv)
{
	int fd;
	char *line;

	fd = open(argv[1], O_RDWR);
	printf("%d\n", get_next_line(fd, &line));
	close (fd);
	return (0);
}
