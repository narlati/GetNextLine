/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:49:07 by narlati           #+#    #+#             */
/*   Updated: 2016/11/20 15:12:14 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int ft_solve(char *buffer, char **line, size_t ret)
{
	size_t i;
	size_t j;
	char *s;
	char *transi;

	if(!(s = malloc(sizeof(char) * ret)))
		return (-1);
	transi = ft_strdup(*line);
	if (transi == NULL)
		return (-1);
	free(*line);
	ft_memcpy(s, buffer, ret);
	i = 0;
	j = 0;
	while (i < ret)
	{
		if (s[i] == '\n')
		{
			while (i < ret)
			{
				buffer[j] = s[i + 1];
				j++;
				i++;
			}
			*line = ft_strnjoin(transi, buffer, i);
			ft_putstr(*line);
			ft_putstr("\nau dessus c est line\n");
			ft_putstr(buffer);
			ft_putstr("\nau dessus c est buffer\n");
			return (1);
		}
		else if (s[i] == '\0')
		{
			*line = ft_strnjoin(transi, buffer, i);
			return (0);
		}
		else
			*line = ft_strjoin(transi, s);
		i++;	
	}
	free (s);
	free(transi);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char	buffer[BUFF_SIZE] = {0};
	int			ret;
	int 		i;
	int			p;

	i = 0;
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
	int i;
	char *line;

	i = argc;
	while (i > 0)
		i--;
	fd = open(argv[1], O_RDWR);
	printf("%d\n", get_next_line(fd, &line));
	free (line);
	close (fd);
	return (0);
}
