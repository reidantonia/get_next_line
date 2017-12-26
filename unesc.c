#include <stdlib.h>
#include <stdio.h>

/*
 *      Converts simple C-style escape sequences. Treats single-letter
 *      escapes (\t, \n etc.) only. Does not treat \0 and the octal and
 *      hexadecimal escapes (\033, \x, \u).
 *
 *      Overwrites the string and returns the length of the unescaped
 *      string.
 */
int unescape(char *str)
{
		static const char escape[256] = {
				['a'] = '\a',        ['b'] = '\b',        ['f'] = '\f',
				['n'] = '\n',        ['r'] = '\r',        ['t'] = '\t',
				['v'] = '\v',        ['\\'] = '\\',       ['\''] = '\'',
				['"'] = '\"',        ['?'] = '\?',
		};

		char *p = str;      /* Pointer to original string */
		char *q = str;      /* Pointer to new string; q <= p */

		while (*p) {
				int c = *(unsigned char*) p++;

				if (c == '\\') {
						c = *(unsigned char*) p++;
						if (c == '\0') break;
						if (escape[c]) c = escape[c];
				}

				*q++ = c;    
		}
		*q = '\0';

		return q - str;
}

int main()
{
		char str[] = "\\\"Hello ->\\t\\\\Man\\\"\\n";

		printf("'%s'\n", str);
		unescape(str);
		printf("'%s'\n", str);

		return 0;
}
