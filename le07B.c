#include<stdio.h>
#define N 25
int spec_depth(int,int);
int spec_height(int,int,int);
int spec_sib(int);
struct node{
    int right;
    int left;
    int par;
    int sib;
    int deg;
    int depth;
    int height;//
    int type;//0root 1internal 2leaf
}nd[N];//index==id
int main(){
    int n,i,j,cnt,id;
    scanf("%d",&n);
    cnt=n;
    for(i=0;i<n;i++)nd[i].par=-1;
    while(cnt--){
        scanf("%d",&id);
        scanf("%d %d",&nd[id].left,&nd[id].right);
        if(nd[id].left==-1&&nd[id].right==-1)nd[id].type=2;//par //process for their children
        else if(nd[id].left!=-1&&nd[id].right==-1)nd[nd[id].left].par=id;
        else if(nd[id].left==-1&&nd[id].right!=-1)nd[nd[id].right].par=id;
        else {
            nd[nd[id].left].par=id;
            nd[nd[id].right].par=id;            
        }
        //printf("id:%d left:%d right:%d",id,nd[id].left,nd[id].right);        
    }
    for(i=0;i<n;i++){//type deg
        if(nd[i].par==-1)nd[i].type=0;
        else if(nd[i].type==2);
        else nd[i].type=1;
        if(nd[i].right!=-1&&nd[i].left!=-1)nd[i].deg=2;
        else if(nd[i].right!=-1||nd[i].left!=-1)nd[i].deg=1;
        else nd[i].deg=0;
        //printf("%d\n",i);
    }
    for(i=0;i<n;i++){
        //printf("%d\n",i);
        nd[i].depth=spec_depth(i,0);
        //printf("%d\n",i);
        //return 0;
        nd[i].height=spec_height(i,0,i);//segmentation fault is here!
        //return 0;
        if(nd[i].par==-1)nd[i].sib=-1;
        else nd[i].sib=spec_sib(i);
        //printf("%d\n",i);
    }
//output
    for(i=0;i<n;i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,nd[i].par,nd[i].sib,nd[i].deg,nd[i].depth,nd[i].height);
        if(nd[i].type==0)printf("root\n");
        else if(nd[i].type==1)printf("internal node\n");
        else if(nd[i].type==2)printf("leaf\n");
    }   
    return 0;
}

int spec_depth(int id,int n){
    if(nd[id].type==0||nd[id].par==-1)return n;
    else return spec_depth(nd[id].par,n+1);
}
int spec_height(int id,int n,int conid){
    int left,right;
    if(nd[id].right==-1&&nd[id].left==-1)return n;
    else if(nd[id].right!=-1&&nd[id].left==-1){
        right=spec_height(nd[id].right,n+1,conid);
        left=0;
    }else if(nd[id].right==-1&&nd[id].left!=-1){
        right=0;
        left=spec_height(nd[id].left,n+1,conid);
    }else {
    right=spec_height(nd[id].right,n+1,conid);
    left=spec_height(nd[id].left,n+1,conid);
    }
    //printf("%d %d %d\n",id,right,left);
    if(id!=conid)return right>=left?right:left;
    else return nd[id].height=(right>=left?right:left);
}
int spec_sib(int id){
    if(nd[nd[id].par].left==id)return nd[nd[id].par].right;
    else return nd[nd[id].par].left;
}