/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narlati <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:45:47 by narlati           #+#    #+#             */
/*   Updated: 2016/12/07 14:25:13 by narlati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <unistd.h>

# define BUFF_SIZE 1
# define MAX_BUFF_SIZE 20000
# define MAX_FD 2064

int 			get_next_line(const int fd, char **line);

#endif
