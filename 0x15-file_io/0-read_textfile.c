#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: The name of the text file being read.
 * @letters: The number of letters to be read.
 *
 * Return: The actual number of bytes read and printed to STDOUT.
 *         Returns 0 when the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd, w, t;

fd = open(filename, O_RDONLY);
if (fd == -1)
{
perror("Error: Can't open file");
exit(1);
}
buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
perror("Error: Can't allocate memory for buffer");
exit(1);
}
t = read(fd, buf, letters);
if (t == -1)
{
perror("Error: Can't read from file");
free(buf);
close(fd);
exit(1);
}
w = write(STDOUT_FILENO, buf, t);
if (w == -1) {
perror("Error: Can't write to STDOUT");
free(buf);
close(fd);
exit(1);
}
free(buf);
close(fd);
return (w);
}
