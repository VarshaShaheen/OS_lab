#include <stdio.h>
#include <unistd.h>

struct process{
    int pid;
    int tat;
    int wt;
    int at;
    int bt;
    int bt_a;
};

int main(){
    int n, s_a = 1000;
    printf("Enter the number of processes:");
    scanf ("%d", &n);
    struct process p[n];
    printf("\nEnter the arrival time and burst time of %d processes: ", n);
    for(int i=0;i<n;i++){
        scanf("%d", &p[i].at);
        scanf("%d", &p[i].bt);
        p[i].pid = i+1;
        p[i].bt_a = p[i].bt;
        if(p[i].at < s_a){
            s_a = p[i].at;
        }
    }
    int count = 0;
    for(int current=s_a;count < n; current++){
        int index = 0;
        int value = 1000;
        for(int i=0;i<n;i++){
            if(p[i].bt < value && p[i].bt > 0 && p[i].at <= current){
                index = i;
                value = p[i].bt;
            }
        }
        p[index].bt -= 1;

        if(p[index].bt <= 0 ){
            p[index].tat = current + 1 - p[index].at ;
            p[index].wt = p[index].tat - p[index].bt_a;
            count ++;
        }

    }

    printf("pid\tat\tbt\ttat\twt\t\n");
    for(int i =0;i<n;i++){
        printf("%d \t %d \t %d\t %d\t %d\t\n", p[i].pid,p[i].at, p[i].bt_a, p[i].tat, p[i].wt);
    }

}