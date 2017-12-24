#include <stdio.h>

int main()
{
		int i;
		i = 0;
		char str[12] = "aaa\nbbb\nccc\n";

		while (str)
		{
				if (str[i] == '\n')
						printf("IT's \n!");
				i++;
		}
		return (0);
}
