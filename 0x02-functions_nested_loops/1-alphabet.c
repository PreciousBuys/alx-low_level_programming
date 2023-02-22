#include "main.h"

/**
 * print_alphabet_x10 -print 10 time the alphabet, in lowecase
 * followed by a new line
 * Return: always 0
 */
void print_alphabet_x10(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);

	_putchar('\n');
}
