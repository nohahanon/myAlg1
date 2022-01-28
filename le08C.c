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
node * delete(node *,int);
int reLeafVal(node *);
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
        }else if(0==strcmp(buf,"delete")){
            node *tmp;
            scanf("%d",&num);
            tmp=delete(&root,num);
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
node *delete(node *now,int num){
    if(num==now->val&&now->left==NULL&&now->right==NULL){
        free(now);
        return NULL;
    }else if(num==now->val&&now->left==NULL&&now->right!=NULL){
        node *tmp=now->right;
        free(now);
        return tmp;
    }else if(num==now->val&&now->left!=NULL&&now->right==NULL){
        node *tmp=now->left;
        free(now);
        return tmp;
    }else if(num==now->val&&now->left!=NULL&&now->right!=NULL){
      /*now->val=now->right->val;
        now->right=delete(now->right,now->right->val);//ua----*/
      now->val=reLeafVal(now->right);//目的の葉ノードの値を返すその際そいつの削除も行う。
      //printf("aaa\n");///////////////////////////////////
      now->right=delete(now->right,now->val);
      return now;
    }
    if(num<now->val)now->left=delete(now->left,num);
    else now->right=delete(now->right,num);
    return now;
}
int reLeafVal(node *now){
  if(now->right==NULL&&now->left==NULL){
    int tmp=now->val;
    return tmp;
  }
  return reLeafVal(now->left);
}
//対象が子を持たないならそのまま対象の親と絶縁させる
//対象の子が一つだけなら対象の位置にその子を据える
//対象の子が二つなら中間順巡回で対象の次に得られる奴の\
値を対象にコピーし、奴を削除する。この削除では上二つを適用する\
それできるようinsertされると思うしいいでしょう！
//rootノードが独身の時に削除命令来たらどうしよう
//rootのーどが独身の時に削除来たらセグフォなるからね注意 最後のreturn手前のイフ文で再帰起こって二回目のそこでヌルから矢印出る

//timeoutのreが出ている タコスタコス U<-横から見たタコス
//case3 delete 20におけるセグフォ
//子が二つある時の削除方式の実装に誤りが見られる　対象の子の削除には1,2を適用する　再帰～
/*
std2dc7:le08 s1290080[179]$ ./a.out
50
insert 30
insert 17
insert 88
insert 53
insert 5
insert 20
insert 18
insert 28
insert 27
insert 60
insert 2000000000
insert 55
insert 63
insert -1
insert 8
print
 -1 5 8 17 18 20 27 28 30 53 55 60 63 88 2000000000
 30 17 5 -1 8 20 18 28 27 88 53 60 55 63 2000000000
delete 53
print
 -1 5 8 17 18 20 27 28 30 55 60 63 88 2000000000
 30 17 5 -1 8 20 18 28 27 88 60 55 63 2000000000
delete 2000000000
print
 -1 5 8 17 18 20 27 28 30 55 60 63 88
 30 17 5 -1 8 20 18 28 27 88 60 55 63
delete 20
print
 -1 5 8 17 18 28 27 30 55 60 63 88
 30 17 5 -1 8 28 18 27 88 60 55 63
delete 5
print
 -1 8 17 18 28 27 30 55 60 63 88
 30 17 8 -1 28 18 27 88 60 55 63
delete 8
print
 -1 17 18 28 27 30 55 60 63 88
 30 17 -1 28 18 27 88 60 55 63
prnt

*/
