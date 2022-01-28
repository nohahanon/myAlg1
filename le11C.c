//BFS
//caution id has no zero!
#include<stdio.h>
#include<stdlib.h>
#define N 100
#define BLACK -1
#define GRAY 0
#define WHITE 1
#define INF 1000000000

struct node{
    int num;
    int *nodes;
    int color;//=WHITE;ここでの初期化並べて無理
}nd[N+1];
int d[N+1],q[INF],head=0,tail=0;//put tail take head

void bfs(int);
void enqueue(int);//take a id and enqueue nodes[]
int dequeue(void);

int main(){
    int n;
    //input
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int id,num;
        scanf("%d ",&id);
        scanf("%d ",&nd[id].num);
        if(nd[id].num==0)continue;
        nd[id].nodes=(int *)malloc(sizeof(int)*(nd[id].num));
        for(int j=0;j<nd[id].num;j++)scanf("%d",&nd[id].nodes[j]);
    }
    //process
    bfs(n);
    //output
    for(int i=1;i<=n;i++)printf("%d %d\n",i,d[i]);
    return 0;
}
void bfs(int n){
    int i;
    for(i=0;i<n+1;i++){nd[i].color=WHITE;d[i]=INF;}
    nd[1].color=GRAY;
    d[1]=0;
    head=tail=0;
    q[tail++]=1;
    enqueue(1);
    while(head!=tail){
        int id=dequeue();
        for(int i=0;i<nd[id].num;i++){
            if(nd[nd[id].nodes[i]].color==WHITE){
                nd[nd[id].nodes[i]].color=GRAY;
                d[nd[id].nodes[i]]=d[id]+1;
                enqueue(nd[id].nodes[i]);
            }
        }
        nd[id].color=BLACK;
    }
    for(i=0;i<n+1;i++)if(d[i]==INF)d[i]=-1;
}
void enqueue(int id){
    if(nd[id].num==0);
    else for(int i=0;i<nd[id].num;i++)q[tail++]=nd[id].nodes[i];
}
int dequeue(){return q[head++];}