#include "main.h"

/**
 * print_alphabet - print the alphabet in lowecase
 * followed by a new line
 * Return: always 0
 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);

	_putchar('\n');
}
