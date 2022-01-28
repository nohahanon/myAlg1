//DFS
//caution id has no zero!
#include<stdio.h>
#include<stdlib.h>
#define N 100
#define BLACK -1
#define GRAY 0
#define WHITE 1

struct node{
    int num;
    int *nodes;
    int color;//=WHITE;ここでの初期化並べて無理
}nd[N+1];
int d[N+1],f[N+1];
int time=0;

void dfs(int);
void visit(int);

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
    dfs(n);
    //output
    for(int i=1;i<=n;i++)printf("%d %d %d\n",i,d[i],f[i]);
    return 0;
}
void dfs(int n){
    int i;
    //init
    for(i=1;i<=n;i++)nd[i].color=WHITE;
    for(i=0;i<=n;i++){d[i]=0;f[i]=0;}
    //process
    for(i=1;i<=n;i++)if(nd[i].color==WHITE)visit(i);
}
void visit(int id){
    nd[id].color=GRAY;
    d[id]=++time;
    if(nd[id].num==0);
    else for(int i=0;i<nd[id].num;i++){
        if(nd[nd[id].nodes[i]].color==WHITE)visit(nd[id].nodes[i]);
    }
    nd[id].color=BLACK;
    f[id]=++time;
}