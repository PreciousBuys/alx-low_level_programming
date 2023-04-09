#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
char *buffer = malloc(1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
exit(99);
}
return (buffer);
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist, cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
char *buffer = create_buffer(argv[2]);
int from = open(argv[1], O_RDONLY), to = open(argv[2],
	O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (from == -1 || to == -1)
{
if (from == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
else
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(98 + (from == -1));
}
ssize_t r, w;
while ((r = read(from, buffer, 1024)) > 0)
{
w = write(to, buffer, r);
if (w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
}
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
free(buffer);
close(from);
close(to);
return (0);
}
