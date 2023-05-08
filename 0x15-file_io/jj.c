#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
ssize_t read_textfile(const char *filename, size_t letters) {
    ssize_t bytes_read;
    ssize_t bytes_written;
    int fd;
	char *buffer;
    if (filename == NULL) {
        return 0;
    }
    buffer = malloc(sizeof(char) *letters);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0;
    }

    
    bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1) {
        close(fd);
        return 0;
    }

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    close(fd);

    if (bytes_written == -1 || bytes_written != bytes_read) {
        return 0;
    }

    return bytes_written;
}

