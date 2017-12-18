#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int fd;
	char *line;

	line = NULL;
	i = 0;
	argc = 0;


	fd = open(argv[1], O_RDONLY);
	if (!fd || fd == -1)
		return (0);

	get_next_line(fd, &line);
	//printf("%s\n", line);
	//	while ((i = get_next_line(fd, &line)) > 0)
	//printf("%s\n", line);
	return (0);
}
