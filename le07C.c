#include<stdio.h>
#define N 25
void show1(int);
void show2(int);
void show3(int);
struct tree{
    int par;//for specify the root node
    int left;
    int right;
}nd[N];//glo---balllllllllllllllllllllllllllllll
int main(){
    int n,tmp,id,root;
    scanf("%d",&n);
    tmp=n;
    while(tmp--)nd[tmp].par=-1;
    tmp=n;
    while(tmp--){
        scanf("%d",&id);        
        scanf("%d %d",&nd[id].left,&nd[id].right);
        if(nd[id].right!=-1)nd[nd[id].right].par=id;
        if(nd[id].left!=-1)nd[nd[id].left].par=id;
    }
    tmp=n;
    while(nd[--tmp].par!=-1);
    root=tmp;
    printf("Preorder\n");
    show1(root);
    printf("\nInorder\n");
    show2(root);
    printf("\nPostorder\n");
    show3(root);
    printf("\n");
    return 0;
}
void show1(int id){
    if(id==-1)return;
    printf(" %d",id);
    show1(nd[id].left);
    show1(nd[id].right);
}
void show2(int id){
    if(id==-1)return;
    show2(nd[id].left);
    printf(" %d",id);
    show2(nd[id].right);
}
void show3(int id){
    if(id==-1)return;
    show3(nd[id].left);
    show3(nd[id].right);
    printf(" %d",id);
}
/*
void show(node_t *node){
if(node==NULL)return;
printf("%d\n",node->val);
show(node->left);
show(node->right);
}
*/ 