#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd1, fd2;
    fd1 = open("C:\\Users\\Varsha\\CLionProjects\\OS_lab\\file1.txt", O_RDONLY | O_CREAT, 0644);
    fd2 = open("C:\\Users\\Varsha\\CLionProjects\\OS_lab\\file2.txt", O_WRONLY | O_CREAT, 0644); // Ensure the file is created if it doesn't exist
    if (fd1 == -1 || fd2 == -1) {
        perror("Failed to open file");
        return 1; // Exit if any file could not be opened
    }

    char c;
    ssize_t read_count;
    while ((read_count = read(fd1, &c, 1)) > 0) {
        if (write(fd2, &c, 1) == -1) {
            perror("Failed to write to file");
            return 1; // Handle possible write error
        }
    }

    if (read_count == -1) {
        perror("Failed to read from file");
        return 1; // Handle possible read error
    }

    close(fd1);
    close(fd2);
    return 0;
}
