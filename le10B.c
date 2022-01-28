/*#include<stdio.h>
#define N 101
#define MAX 100000000
int solve(int,int,int);
int p[N],m[N][N];
int main(){
    //input
    int n,i,j;
    scanf("%d",&n);
    int tmp[n][2];
    for(i=0;i<n;i++)scanf("%d%d",&tmp[i][0],&tmp[i][1]);
    for(i=0;i<n;i++)p[i]=tmp[i][0];p[n]=tmp[n-1][1];//init p[]
    for(i=0;i<n+1;i++)for(j=0;j<n+1;j++)m[i][j]=0;//init m[][]
    //process
    for(i=1;i<n+1;i++)for(j=i+1;j<n+1;j++)m[i][j]=solve(i,0,j);
    //output
    printf("%d\n",m[1][n]);
    return 0;
}
int solve(int i,int k,int j){
    int min=MAX;  
    if(i==j)return m[i][j];
    else if(i+1==j)return m[i][j]=p[i-1]*p[i]*p[i+1];
    else if(i<=k&&k<j)return solve(i,0,k)+solve(k+1,0,j)+p[i-1]*p[k]*p[j];
    for(k=i;k<j;k++){
        int tmp=m[i][j]!=0?m[i][j]:solve(i,k,j);//
        min=min>tmp?tmp:min;
    }
    return min;
}*/
/*#include<stdio.h>
#define MAX 100000000
int main(){
    int i,j,k,l,t,n,p[100],m[100][100];
    scanf("%d",&n);
    for(i=0;i<101;i++)m[i][i]=0;
    for(i=1;i<n+1;i++)scanf("%d%d",&p[i-1],&p[i]);
    for(l=1;l<n;l++){
        for(i=1;i<=n-l;i++){//i+l<=n
            j=i+l;
            m[i][j]=MAX;
            for(k=i;k<j;k++){
                t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(m[i][j]>t)m[i][j]=t;
            }
        }
    }
    printf("%d\n",m[1][n]);
    return 0;
}*/
/***********************
//p[]:与えられた行列の行と列を保管する。
積可能な形式で与えられるから被りの部分は必要ないため確保しない。
0行1列2行3列...とあるためi番目の行列の行がp[i-1],列がp[i]にある。
sampleだとp[6+1]={30,35,15,5,10,20,25};となる。だから0番目行列ない。1origin.
//m[][]:m[i][j] をMi*...*Mjのコスト保管場所とする。
まずは1.2,2.3,3.4のような隣合う数の要素から埋めていく。
//対角線上は使わない。対角線の一つ上は簡単に求まる一通りしかないし。
対角線の一つ上の一つ上から難しい。
ex:0,2要素 m0m1m2はm0*m1m2とm0m1*m2の二通りある。
このうち小さいほうを0,2要素に代入する。
m1m2,m0m1の分のコストは対角線一つ上を見るといい。
最終的には1,n要素を出力する。pを1originで扱うからm[][]も1originで扱う。

************************/

#include <stdio.h>
#include <limits.h>
long long int r[100], c[100];
long long int solve(int,int);
//matrix[i][j]: solve[i][j]の結果
long long int matrix[100][100];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld %lld",&r[i],&c[i]);
    //n == 1の場合は自明なのでここで終了
    if(n==1){printf("0\n");return 0;}
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(i!=j)matrix[i][j]=-1;
            else matrix[i][j]=0;
        }
    }
    printf("%lld\n",solve(0,n-1));
    return 0;
}

// A[begin]からA[end]までの行列積の最小計算回数を求める
long long int solve(int begin,int end){
    //既に同じ引数で計算したことがある場合
    if(matrix[begin][end]!=-1)return matrix[begin][end];
    if(begin==end)return 0;
    if(begin+1==end)return matrix[begin][end]=r[begin]*c[begin]*c[end];
    long long int result=LLONG_MAX;
    for(int i=begin;i<end;i++){
        long long int tmp=solve(begin,i)+solve(i+1,end)+r[begin]*c[i]*c[end];
        if(tmp<result)result=tmp;
    }
    return matrix[begin][end]=result;
}