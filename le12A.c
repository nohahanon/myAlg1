#include<stdio.h>
#define N 100
#define INF 100000000
#define BLACK 1
#define WHITE 0
int prim();
int a[N][N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    //for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d",a[i][j]);printf("\n");}
    printf("%d\n",prim());
    return 0;
}
int prim(){
    int d[n];
    int color[n];
    int pi[n];
    //init
    for(int i=0;i<n;i++){d[i]=INF;color[i]=WHITE;}
    d[0]=0;
    //prim
    while(1){
        int mincost=INF;
        int u;
        for(int i=0;i<n;i++){
            if(color[i]!=BLACK&&d[i]<mincost){//未探索で一番軽い辺とつながるのどこか調べる。一番最初は初期化で指定した場所で足踏みする形になる。
                mincost=d[i];
                u=i;
            }
        }
        if(mincost==INF)break;
        color[u]=BLACK;//ノードuへの処理を行う
        for(int i=0;i<n;i++){
            if(a[i][u]==-1)continue;
            if(color[i]!=BLACK&&a[i][u]<d[i]){
                pi[i]=u;//pi[]いるのかなこれ
                d[i]=a[i][u];//uと隣接するノードに正しい値を持たせる。値を更新していく。
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)sum+=(d[i]==-1?0:d[i]);
    return sum;
}
//prim 最小全域木(辺に重みのあるグラフにおいてその総和が最小となる木の取り方)
//d[] 自分から出る枝の中で一番軽いものを持つ。ただし適当に選ぶルートノードは0を置く。
//ただ全てのノードについてその枝を見ていてはO(n^3)となる。そこでprim
//