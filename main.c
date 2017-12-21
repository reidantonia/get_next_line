#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/*int main(int argc, char **argv)
{
		int i;
		int fd;
		char *line;

		line = NULL;
		i = 0;
		argc = 0;


		if (!(fd = open(argv[1], O_RDONLY)))
				return (0);

		while ((i = get_next_line(fd, &line)) > 0)
		{
				printf("%s\n", line);
		}
		if (close(fd) == -1)
		{
				return (0);
		}
		return (0);
}*/

int			main(int argc, char **argv)
{
		char	*line;
		int		fd;
		int		code;
		int		len;
		int		i;

		i = 1;
		printf("BUFF_SIZE = %d\n", BUFF_SIZE);
		printf("___Premier FD___ \n\n");
		while (i < argc)
		{
				if ((fd = open(argv[i], O_RDONLY)) == -1)
						printf("Error: Can't open file");
				while ((code = get_next_line(fd, &line)) > 0)
				{
						len = ft_strlen(line);
						printf("%d - %d - |%s|\n", code, len, line);
						free(line);
				}
				i++;
				if (i < argc)
						printf("\n___Changement de FD___ \n\n");
		}
		printf("LAST %d - |%s|\n", code, line);
		return (0);
}
