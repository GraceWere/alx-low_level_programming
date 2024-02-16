#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void check_arg_count(int argc);
void copy_content(const char *file_from, const char *file_to);

/**
 * main - entry point, copies the content of one file to another
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, exits with different codes on failure
 */
int main(int argc, char *argv[])
{
    check_arg_count(argc);
    copy_content(argv[1], argv[2]);
    return (0);
}

void check_arg_count(int argc)
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }
}

void copy_content(const char *file_from, const char *file_to)
{
    int fd_from, fd_to, read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from < 0)
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from), exit(98);

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to < 0)
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to), exit(99);

    while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes)
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to), exit(99);
    }

    if (read_bytes < 0)
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from), exit(98);

    if (close(fd_from) < 0)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);

    if (close(fd_to) < 0)
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);
}


