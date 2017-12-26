#include <stdio.h>

static int		ft_check_line(const char *str, char ch)
{
		int i;

		i = 0;
		while (str && str[i] != '\0')
		{
				printf("i is %d\n", i);
				if (str[i] == ch)
						return (i);
				i++;
		}
		return (-1);
}

int main()
{
		int i;
		i = 0;
		char str[12] = "aaa\nbbb\nccc\n";

		ft_check_line(str, '\n');
		return (0);
}
