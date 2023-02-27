#include "main.h"

/**
 * puts2 - function should print only one character out of two
 * starting with the first one
 *@str: input
 *Return: print
 */

void puts2(char *str)
{
	int string;

	for (string = 0; str[string] != '\0'; string++)
	if (string % 2 == 0)
		_putchar(str[string]);
	_putchar('\n');
}
