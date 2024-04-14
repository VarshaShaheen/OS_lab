// One way pipe to pass array elements

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(){
    int arr[2],size_pipe[2];
    if(pipe(arr) == -1){
        printf("pipe creation failed");
        return -1;
    }
    if(pipe(size_pipe) == -1){
        printf("pipe creation failed");
        return -1;
    }

    int pid = fork();

    if(pid == -1){
        printf("process creation failed");
    }
    else if(pid == 0){
        close(arr[1]);
        close(size_pipe[1]);
        int size;
        read(size_pipe[0],&size, sizeof(size));
        int a[size];
        read(arr[0],&a,sizeof(a));
        for(int i=0;i<size;i++){
            printf("%d", a[i]);
        }
    }
    else{
        close(arr[0]);
        close(size_pipe[0]);
        int size;
        printf("Enter the size of array:");
        scanf("%d",&size);
        int a[size];
        printf("Enter the elements");
        for(int i=0;i<size;i++){
            scanf("%d", &a[i]);
        }
        write(arr[1],&a,sizeof(a));
        write(size_pipe[1],&size,sizeof(size));
    }
}
