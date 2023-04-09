#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write into file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;
	char *buf = NULL;

	if (filename == NULL)
	return (-1);

	if (text_content != NULL)
	len = strlen(text_content);

	buf = malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
	exit(EXIT_FAILURE);

	strncpy(buf, text_content, len);
	buf[len] = '\0';

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
	{
	free(buf);
	return (-1);
	}

	w = write(fd, buf, len);
	if (w == -1)
	{
	free(buf);
	close(fd);
	return (-1);
	}
	free(buf);
	close(fd);
	return (1);
}
