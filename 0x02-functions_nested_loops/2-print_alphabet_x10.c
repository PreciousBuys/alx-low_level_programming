#include "main.h"

/**
 * print_alphabet_x10 - prints all alphabets in lowercase 10 times
 * Return: always 0
 */

void print_alphabet_x10(void)
{
	{
	int count = 0;
	char letter;

	while (count++ <= 9)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
		_putchar('\n');
	}
}
}
