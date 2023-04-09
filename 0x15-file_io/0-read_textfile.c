#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char buf[letters];

	ssize_tnread, nwritten;

	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
	return (0);
	}

	nread = read(fd, buf, letters);

	if (nread == -1)
	{
	close(fd);
	return (0);
	}
	nwritten = write(STDOUT_FILENO, buf, nread);
	close(fd);
	return ((nwritten == nread) ? nwritten : 0);
	}
