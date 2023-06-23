#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define FILE_SIZE 4096

int main() {
    int fd;
    char *map;

    // Open a file for read and write
    fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Truncate the file to a specific size
    if (ftruncate(fd, FILE_SIZE) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // Map the file into memory
    map = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Write data to the memory-mapped file
    sprintf(map, "Hello, World!");

    // Sync the changes to the file
    if (msync(map, FILE_SIZE, MS_SYNC) == -1) {
        perror("msync");
        exit(1);
    }

    // Print the contents of the memory-mapped file
    printf("Contents: %s\n", map);

    // Unmap the file from memory
    if (munmap(map, FILE_SIZE) == -1) {
        perror("munmap");
        exit(1);
    }

    // Close the file
    close(fd);

    return 0;
}

