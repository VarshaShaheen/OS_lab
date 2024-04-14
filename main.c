#include <stdio.h>
#include <unistd.h>

struct process{
    int pid;
    int tat;
    int wt;
    int at;
    int bt;
};

void sort(struct process p[], int n, struct process temp){
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
        }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of processes:");
    scanf ("%d", &n);
    struct process p[n], temp;
    printf("\nEnter the arrival time and burst time of %d processes: ", n);

    for(int i=0;i<n;i++){
        scanf("%d", &p[i].at);
        scanf("%d", &p[i].bt);
        p[i].pid = i+1;
    }

    sort(p,n,temp);
    int current  = p[0].at;

    for(int i = 0;i<n;i++){
        p[i].wt = current - p[i].at;
        p[i].tat = p[i].wt + p[i].bt;
        printf("started execution of %d\n",p[i].pid);
        sleep(p[i].bt);
        printf("ended execution of %d\n",p[i].pid);
        current = current+p[i].bt;
    }
    printf("pid\tat\tbt\ttat\twt\t\n");
    for(int i =0;i<n;i++){
        printf("%d \t %d \t %d\t %d\t %d\t\n", p[i].pid,p[i].at, p[i].bt, p[i].tat, p[i].wt);
    }

}