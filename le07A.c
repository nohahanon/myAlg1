#include<stdio.h>
#include<stdlib.h>
#define N 100000
int spec_depth(int,int);
    typedef struct node{
        int id;
        int dim;
        int depth;
        int par;//parent index
        int *in;//secure array for internal elements index
        int type;//0->root 1->internal 2->leaf
    }Nodes;
    Nodes nd[N];
int main(){
    int n,i,j,id;
    scanf("%d",&n);
    int cnt=n;
    for(i=0;i<n;i++)nd[i].par=-1;//for root par
    while(cnt--){//id,dim,in,par
        scanf("%d",&id);
        nd[id].id=id;
        //printf("%d %d\n",id,nd[id].id);
        scanf("%d",&nd[id].dim);
        if(nd[id].dim==0){
            nd[id].type=2;
            continue;
        }
        nd[id].in=(int *)malloc(sizeof(int)*nd[id].dim);
        for(j=0;j<nd[id].dim;j++){
            scanf("%d",&nd[id].in[j]);
            nd[nd[id].in[j]].par=id; 
        }
        //printf("id:%d dim:%d par:%d\n",nd[id].id,nd[id].dim,nd[id].par);///////////
    }
    //printf("www\n");
    for(i=0;i<n;i++){//type
        if(nd[i].par==-1)nd[i].type=0;
        else if(nd[i].type==2);
        else nd[i].type=1;      
    }
    for(i=0;i<n;i++)nd[i].depth=spec_depth(i,0);

//output
for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,nd[i].par,nd[i].depth);
    if(nd[i].type==0)printf("root, ");
    else if(nd[i].type==1)printf("internal node, ");
    else if(nd[i].type==2)printf("leaf, ");
    printf("[");
    if(nd[i].dim!=0){
        for(j=0;j<nd[i].dim;j++){
            if(j==nd[i].dim-1)printf("%d",nd[i].in[j]);
            else printf("%d, ",nd[i].in[j]);
        }
    }
    printf("]\n");
    }
return 0;
}
int spec_depth(int id,int n){
    if(nd[id].type==0||nd[id].par==-1)return n;
    else return spec_depth(nd[id].par,n+1);
}