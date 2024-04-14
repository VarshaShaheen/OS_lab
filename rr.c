#include <stdio.h>

struct process{
    int pid;
    int tat;
    int wt;
    int at;
    int bt;
    int bt_a;
};

int main(){
    int n, s_a = 1000, time_q;
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
    printf("Enter the time quantum");
    scanf("%d", &time_q);
    int count = 0;
    int current = s_a;
    while(count < n){
        for(int i=0;i<n;i++){
            if(p[i].bt > time_q && p[i].bt != 0){
                p[i].bt -= time_q;
                current += time_q;
            }
            else if(p[i].bt <= time_q && p[i].bt !=0){
                current += p[i].bt;
                p[i].bt = 0;
                p[i].tat = current - p[i].at;
                p[i].wt = p[i].tat - p[i].bt_a;
                count ++;
            }
        }
    }

    printf("pid\tat\tbt\ttat\twt\t\n");
    for(int i =0;i<n;i++){
        printf("%d \t %d \t %d\t %d\t %d\t\n", p[i].pid,p[i].at, p[i].bt_a, p[i].tat, p[i].wt);
    }

}