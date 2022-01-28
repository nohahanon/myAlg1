#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag{
    struct node_tag *left;
    struct node_tag *right;
    int val;
}node_t;
node_t *make_node(int);
node_t *insert(node_t *,int);
void show(node_t *);

int main(){
    node_t *root=NULL;
    int val;
while(1){
    if(scanf("%d",&val)==EOF)break;
    root=insert(root,val);
}
show(root);
return 0;
}
node_t *insert(node_t *node,int val){
if(node==NULL)node=make_node(val);
else if(node->val>=val)node->left=insert(node->left,val);
else node->right=insert(node->right,val);
return node;
}
node_t *make_node(int val){
node_t *new_node;
new_node=(node_t *)malloc(sizeof(node_t));
new_node->left=NULL;
new_node->right=NULL;
new_node->val=val;
return new_node;
}
void show(node_t *node){
if(node==NULL)return;
printf("%d\n",node->val);
show(node->left);
show(node->right);
}