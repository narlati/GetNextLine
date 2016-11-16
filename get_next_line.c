/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/16 20:09:14 by narlati          ###   ########.fr       */
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
	while (i < BUFF_SIZE)
	{
		ft_putchar(s[i]);
		i++;
	}
}


char			*new_alloc(char *s)
{
	int i;
	char *s1;

	i = 0;
	while (s[i] != '\0' || s[i] != '\n')
		i++;
	s1 = ft_memalloc(sizeof(i) * i);
	ft_memccpy(s1, s, '\n', i - 1);
	return (s1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buffer = NULL;
	int			ret;

	if (buffer == NULL)
		buffer = malloc(BUFF_SIZE);
	ret = read(fd, buffer, BUFF_SIZE);
	ft_print_buffer(buffer);
	if (ret == -1)
		return (-1);
	else if (ret > 0)
	{
		buffer = new_alloc(buffer);
		ft_print_buffer(buffer);
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
