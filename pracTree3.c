//prac tree
#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
    int val;
    struct Tree *right;
    struct Tree *left;
}node;
void insert(node *,int);
void show(node *);
int main(){
    int n;
    node root={5,NULL,NULL};//critetion is 5.
    while(1){
        printf("please input a number -> ");
        scanf("%d",&n);
        if(n==999)break;//999で終わり
        else insert(&root,n);
        //printf("aaa\n");
        //show(&root);////////////////
    }
    show(&root);
    printf("\n");
    return 0;
}
void insert(node *now,int val){
    /*if(now->right==NULL&&now->left==NULL){
        node *tmp;
        tmp=(node *)malloc(sizeof(node));
        tmp->left=NULL;
        tmp->right=NULL;
        tmp->val=val;
        if(now->val<=val)now->right=tmp;
        else now->left=tmp;
        return;
    };*/
    if(now->right==NULL&&now->val<=val){
        node *tmp;
        tmp=(node *)malloc(sizeof(node));
        tmp->left=NULL;
        tmp->right=NULL;
        tmp->val=val;
        now->right=tmp;
        return;        
    }else if(now->left==NULL&&val<now->val){
        node *tmp;
        tmp=(node *)malloc(sizeof(node));
        tmp->left=NULL;
        tmp->right=NULL;
        tmp->val=val;
        now->left=tmp;
        return;                
    }
    if(now->val<=val)insert(now->right,val);
    else insert(now->left,val);
}
void show(node *now){
    /*if(now->left==NULL&&now->right==NULL){
    //printf("%d|",now->val);
    return;        
    }*/
    if(now==NULL)return;
    show(now->left);
    printf("%d|",now->val);
    show(now->right);
}
