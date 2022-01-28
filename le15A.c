#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",n/25+n%25/10+n%25%10/5+n%5);
    return 0;
}