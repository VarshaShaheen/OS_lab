// 2 way pipe to print palindromes in an array

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    int arr_pipe[2], size_pipe[2], number_pipe[2], palindrome_pipe[2];
    if(pipe(arr_pipe) == -1 || pipe(size_pipe) == -1 || pipe(number_pipe) == -1|| pipe(palindrome_pipe)==-1){
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
        close(palindrome_pipe[0]);
        close(number_pipe[0]);
        int size, pal_size=0;
        char palindromes[10][10];
        read(size_pipe[0], &size, sizeof(size));
        char a[size][15];
        read(arr_pipe[0],&a,sizeof(a));
        for(int i=0;i<size;i++){
            int len = strlen(a[i]);
            int flag = 0;
            for(int j=0;j<len/2;j++){
                if (a[i][j] != a[i][len - j - 1]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                pal_size ++ ;
                strcpy(palindromes[pal_size-1], a[i]);
            }
        }
        write(palindrome_pipe[1],&palindromes,sizeof(palindromes));
        write(number_pipe[1],&pal_size,sizeof(pal_size));
    }
    else{
        close(arr_pipe[0]);
        close(size_pipe[0]);
        close(palindrome_pipe[1]);
        close(number_pipe[1]);
        int size, pal_num;
        printf("Enter the size of array:");
        scanf("%d",&size);
        char a[size][15];
        char pal[10][10];
        printf("Enter the elements\n");
        for(int i=0;i<size;i++){
            scanf("%s", &a[i]);
        }
        write(arr_pipe[1],&a,sizeof(a));
        write(size_pipe[1],&size,sizeof(size));

        read(number_pipe[0],&pal_num, sizeof(pal_num));
        read(palindrome_pipe[0],&pal, sizeof(pal));
        printf("number of palindromes are: %d\n", pal_num);
        for(int i =0;i<pal_num;i++){
            printf("%s", pal[i]);
        }
    }

}