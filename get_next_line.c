/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/17 14:54:05 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

void			ft_print_buffer(char *s)
{
	int i;

	i = 0;
	ft_putstr("le buffer vaut : ");
	while (i < BUFF_SIZE)
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putstr("\n");
}

int ft_realloc(char *buffer, char **line, int max)
{
	int i;
	char *s;

	i = 0;
	s = malloc(max);

	printf("s vut %s\n", s);
	printf("line vut %s\n", *line);
	
	while (i < max)
	{
		ft_memccpy(*line, buffer, '\n', i);
		printf("line apres memccpy vut %s\n", *line);
		*line = ft_strjoin(s, *line);
		printf("line apres le join vut %s\n", *line);
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buffer = NULL;
	int			ret;
	int 		i;

	i = 0;
	if (buffer == NULL)
		buffer = malloc(BUFF_SIZE);
	line = malloc(BUFF_SIZE);
	ret = read(fd, buffer, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	while (ret != 0)
	{
		if (ft_realloc(buffer, line, ret) == 1)
			return (1);
		else
		{
			buffer = ft_strjoin(buffer, *line);
			ret = read(fd, buffer, BUFF_SIZE);
		}
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
