#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Tree{
    int val;
    struct Tree *right;
    struct Tree *left;
}node;
void show_IN(node *);
void show_PR(node *);
void insert(node *,int);
node *make(int);
int find(node *,int);
int main(){
    int n,i,num,flag=0;
    char buf[7];
    node root;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",buf);
        if(0==strcmp(buf,"insert")){
            scanf("%d",&num);
            if(flag==0){
                root.val=num;
                root.right=NULL;
                root.left=NULL;
                flag=1;
                continue;
            }
            insert(&root,num);
        }else if(0==strcmp(buf,"print")){
            show_IN(&root);
            printf("\n");
            show_PR(&root);
            printf("\n");
        }else if(0==strcmp(buf,"find")){
            scanf("%d",&num);
            if(find(&root,num))printf("yes\n");
            else printf("no\n");
        }else exit(5);
    }
    return 0;
}
void insert(node *now,int val){
    if(now->left==NULL&&val<now->val){
        now->left=make(val);
        return;
    }else if(now->right==NULL&&now->val<=val){
        now->right=make(val);
        return;
    }
    if(val<now->val)insert(now->left,val);
    else insert(now->right,val);
}
node *make(int val){
    node *tmp=(node *)malloc(sizeof(node));
    tmp->val=val;
    tmp->right=NULL;
    tmp->left=NULL;
    return tmp;
}
void show_IN(node *now){
    if(now==NULL)return;
    show_IN(now->left);
    printf(" %d",now->val);
    show_IN(now->right);
}
void show_PR(node *now){
    if(now==NULL)return;
    printf(" %d",now->val);
    show_PR(now->left);
    show_PR(now->right);
}
int find(node *now,int num){
    /*if(now==NULL)return 0;
    else if(now->val==num)return 1;
    if(find(now->right,num)||find(now->left,num))return 1;
    else return 0;*/
    if(now==NULL)return 0;
    else if(now->val==num)return 1;
    else if(now->val<=num)return find(now->right,num);
    else if(num<now->val)return find(now->left,num);
}