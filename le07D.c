#include<stdio.h>
void walk(int,int,int *);
int pr[40],in[40];
int main(){
    int n,i,pos;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&pr[i]);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    pos=0;
    walk(0,n-1,&pos);
    printf("\n");
    return 0;    
}
void walk(int begin,int end,int *pos){
    int i;
    if(begin<=end){
        i=begin;
        while(in[i]!=pr[*pos])i++;
        (*pos)++;
        walk(begin,i-1,pos);
        (*pos)++;
        walk(i+1,end,pos);
        printf("%d",in[i]);
        if(in[i]!=pr[0])printf(" ");
    }else (*pos)--;
}