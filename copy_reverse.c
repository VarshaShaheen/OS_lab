#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd1, fd2;
    fd1 = open("C:\\Users\\Varsha\\CLionProjects\\OS_lab\\file1.txt", O_RDONLY | O_CREAT, 0644);
    fd2 = open("C:\\Users\\Varsha\\CLionProjects\\OS_lab\\file2.txt", O_WRONLY | O_CREAT, 0644); // Ensure the file is created if it doesn't exist
    if (fd1 == -1 || fd2 == -1) {
        perror("Failed to open file");
        return 1;
    }

    char c;
    ssize_t read_count;
    int length=0, count = 0;
    while((read_count = read(fd1,&c,1)>0)){
        length ++;
    }
    lseek(fd1, -1, SEEK_END);
    while(count < length){
        read(fd1,&c,1);
        write(fd2,&c,1);
        lseek(fd1, -2, SEEK_CUR);
        count++;
    }
    close(fd1);
    close(fd2);
    return 0;
}
