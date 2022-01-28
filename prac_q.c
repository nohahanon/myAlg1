#include<stdio.h>
#include<stdlib.h>
void enqueue(int);
int dequeue(void);
int head=0,tail=0,q[10000];
int main(){
    int n;
    while(1){
        printf("999-exit/9999-dequeue/else-enqueue-> ");
        scanf("%d",&n);
        if(n==999)exit(8);
        else if(n==9999)printf("dequeue-> %d\n",dequeue());
        else enqueue(n);
        for(int i=head;i<tail;i++)printf("-%d",q[i]);
        printf("\n");
    }
    return 0;
}
void enqueue(int n){q[tail++]=n;}
int dequeue(){return q[head++];}