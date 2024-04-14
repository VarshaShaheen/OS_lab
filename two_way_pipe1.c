// 2 way pipe to print sum - parent reads input - child calculates sum - parent prints sum

#include <stdio.h>
#include <unistd.h>

int main(){
    int arr_pipe[2], size_pipe[2], sum_pipe[2];
    if(pipe(arr_pipe) == -1 || pipe(size_pipe) == -1 || pipe(sum_pipe) == -1){
        printf("pipe creation failed");
        return -1;
    }
    int pid =  fork();
    if(pid == -1){
        printf("process creation failed.");
        return -1;
    }
    else if(pid == 0){
        close(arr_pipe[1]);
        close(size_pipe[1]);
        close(sum_pipe[0]);
        int size, sum =0;
        read(size_pipe[0], &size, sizeof(size));
        int a[size];
        read(arr_pipe[0],&a,sizeof(a));
        for(int i=0;i<size;i++){
            sum+=a[i];
        }
        write(sum_pipe[1],&sum,sizeof(sum));
    }
    else{
        close(arr_pipe[0]);
        close(size_pipe[0]);
        close(sum_pipe[1]);
        int size, result;
        printf("Enter the size of array:");
        scanf("%d",&size);
        int a[size];
        printf("Enter the elements");
        for(int i=0;i<size;i++){
            scanf("%d", &a[i]);
        }
        write(arr_pipe[1],&a,sizeof(a));
        write(size_pipe[1],&size,sizeof(size));
        read(sum_pipe[0],&result,sizeof(result));
        printf("The sum is: %d", result);
    }

}