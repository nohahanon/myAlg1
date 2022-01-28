//メモ化再帰
#include<stdio.h>
int fibo(int);
int fib[44];
int main(){
    int n,i;
    for(i=0;i<44;i++)fib[i]=0;
    scanf("%d",&n);
    printf("%d\n",fibo(n));
    return 0;
}
int fibo(int n){
    if(n==1||n==0)return 1;
    else if(fib[n]==0)return fib[n]=fibo(n-1)+fibo(n-2);
    else return fib[n];
}