#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int i = 0;
	char *line;

	while (i < argc)
		i++;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
		printf("line vaut :%s\net ret vaut :%d\n\n", line, ret);
	printf("ret vaut :%d\n", ret);
	close (fd);
	return (0);
}
