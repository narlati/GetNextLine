#include "get_next_line.h"
#include <stdlib.h>

static int		treat_no_current(char **line, char **current, int fd, char *buf)
{
	if (ft_strchr(buf, '\n'))
	{
		if (**line)
			*line = ft_strjoin(ft_strdup(*line),
					ft_strndup(buf, ft_strchr(buf, '\n') - buf));
		else
			*line = ft_strndup(buf, ft_strchr(buf, '\n') - buf);
		current[fd] = ft_strdup(ft_strchr(buf, '\n') + 1);
		return (*line && current[fd] ? 1 : -1);
	}
	if (**line)
		*line = ft_strjoin(ft_strdup(*line), buf);
	else
		*line = ft_strdup(buf);
	return (*line && !current ? 0 : -1);
}

static int		endl_in_current(char **line, char **current, int fd, char *buf)
{
	if (**line)
		*line = ft_strjoin(ft_strdup(*line), ft_strndup(current[fd],
					ft_strchr(current[fd], '\n') - current[fd]));
	else
		*line = ft_strndup(current[fd],
				ft_strchr(current[fd], '\n') - current[fd]);
	current[fd] = ft_strjoin(ft_strdup(ft_strchr(current[fd], '\n') + 1),
			ft_strdup(buf));
	return (*line && current[fd] ? 1 : -1);
}

static int		no_endl_in_current(char **line, char *current, char *buf, int ret)
{
	if (**line)
	{
		*line = ft_strjoin(ft_strdup(*line), current);
		if (ret > 0)
			current = ft_strdup(buf);
	}
	else
	{
		*line = ft_strdup(current);
		if (ret > 0)
			current = ft_strdup(buf);
	}
	if (ret < 1)
	{
		free(current);
		current = ft_strnew(0);
	}	
	return (**line && current ? ret : -1);
}

static int		stream_to_line(int const fd, char *buf,
		char **line, char **current)
{
	int			ret;

	ret = 0;
	if (!line || !current[fd])
		return (-1);
	while (*current[fd] != '\0' || ((int)ft_strlen(buf) < ret ? (0) :
				(ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		if (*current[fd] == '\0')
		{
			if (treat_no_current(line, current, fd, buf) == 1)
				return (1);
		}
		else if (ft_strchr(current[fd], '\n'))
			return (endl_in_current(line, current, fd, buf));
		else
		{
			if (no_endl_in_current(line, current[fd], buf, ret) == -1)
				return (-1);
		}
	}
	if (ret > 0 || *current[fd] != '\0' || **line != '\0')
		return (1);
	return (ret < 0 ? -1 : 0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*current[MAX_FD];
	int			current_ret;
	char		buf[BUFF_SIZE];

	current_ret = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1 ||
			BUFF_SIZE > MAX_BUFF_SIZE)
		return (-1);
	*line = ft_strnew(0);
	if (!current[fd])
		current[fd] = ft_strnew(0);
	current_ret = stream_to_line(fd, buf, line, current);
	if (current_ret > 0)
		return (1);
	if (*current[fd])
		ft_strdel(&current[fd]);
	ft_strdel(line);
	return (current_ret);
}
