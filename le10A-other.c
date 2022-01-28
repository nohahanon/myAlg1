#include<stdio.h>
int main(){
    int n,i,a=0,b=1,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        c=b;
        b+=a;
        a=c;
    }
    printf("%d\n",b);
    return 0;
}
//1 1 2 3 5 8 13 21 34 54...
//第3項2を得る　1+1;1+2;　求めたい項-1のループが必要
//a+b;b+c;c+a;a+b;と回していく

/*
int fib[45]={1,1}
for(int i=1;i<45;i++)fob[i]=fib[i-1]+fib[i-2];
でもいい
while(n--)c=a+b,a=b,b=c;
でもいい aを出力する
*/