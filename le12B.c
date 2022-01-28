#include<stdio.h>
#include<stdlib.h>
#define N 100
#define INF 100000000
#define WHITE 0
#define BLACK 1
struct node{
    int num;
    int *neighbor;
    int *weight;
    int color;
}nd[N];
int n;
int d[N];
//int pi[N]; ナンに使うのこれ
void dijkstra();

int main(){
    //input
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int id;
        scanf("%d",&id);
        scanf("%d",&nd[id].num);
        if(nd[id].num==0)continue;
        nd[id].neighbor=(int *)malloc(sizeof(int)*nd[id].num);
        nd[id].weight=(int *)malloc(sizeof(int)*nd[id].num);
        for(int j=0;j<nd[id].num;j++)scanf("%d %d",&nd[id].neighbor[j],&nd[id].weight[j]);
    }
    //process
    dijkstra();
    //output
    for(int i=0;i<n;i++)printf("%d %d\n",i,d[i]);
    return 0;
}

void dijkstra(){
    //init
    for(int i=0;i<n;i++){d[i]=INF;nd[i].color=WHITE;}
    d[0]=0;
    //process
    while(1){
        int mincost=INF;
        int u;
        for(int i=0;i<n;i++){
            if(nd[i].color!=BLACK&&d[i]<mincost){
                mincost=d[i];
                u=i;//一番小さいd持つやつを探す。処理するため。そこに流れをつけるためにINFで初期化、d[0]=0とかした。  
            }
        }
        if(mincost==INF)break;//mincostが上のループで変わらないということは全てが探索済みのBLACKであるということ。終わってよし。
        nd[u].color=BLACK;
        if(nd[u].num==0)continue;
        else for(int i=0;i<nd[u].num;i++){
            if(nd[nd[u].neighbor[i]].color!=BLACK&&d[u]+nd[u].weight[i]<d[nd[u].neighbor[i]]){
                //pi[i]=u;
                d[nd[u].neighbor[i]]=d[u]+nd[u].weight[i];
            }
        }
    }
}
//dijkstra's algorithm は辺の重みが非負数の場合の単一始点最短経路問題を解くための最良優先探索によるアルゴリズム
//負数ある時はベルマンフォード法
//d[]で各ノードのルートノードからの距離を管理する
//primは最小全域木を求める。dijkstraはあるノードからの最短距離を求める。コードはだいぶ似ているけども、関数内第二ループにおけるif文とd[]の扱い方が違う。
//le12C.cは関数内の最小求める部分ヒープでやれってやつ