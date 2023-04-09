#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd;
ssize_t bytes_written;
size_t len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
len = strlen(text_content);
}
fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);

if (fd == -1)
{
if (errno == EACCES || errno == EPERM)
{
fprintf(stderr, "Error: You lack write permission for %s\n", filename);
exit(EXIT_FAILURE);
}
else
{
perror("Error opening file");
exit(EXIT_FAILURE);
}
}
bytes_written = write(fd, text_content, len);

if (bytes_written == -1)
{
perror("Error writing to file");
exit(EXIT_FAILURE);
}
if (close(fd) == -1)
{
perror("Error closing file");
exit(EXIT_FAILURE);
}
return (1);
}
