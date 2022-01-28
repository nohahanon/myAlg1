#include<stdio.h>//テラタームには転送機能があるコピペしにくいけどこれで解決
//仕分けしてからのマージソート的な？？
//軸が端によったりするとマジ大変　既にソートされているものに行うと分割うまくできない
//基本的に安定ではない マージソートと比べて早いけど
typedef struct{
char ptrn;
int num;
}Card;

int partition(int *,int,int);
void quickSort(int *,int,int);
//数だけの配列を確保する必要がある　そこだけを抽出する

int main(){
int n,i;
scanf("%d",&n);
Card card[n];
int A[n],O[n];//Aが数だけ　Oが順序を
for(i=0;i<n;i++){
    scanf("%c %d",card[i].ptrn,&card[i].num);
    A[i]=card[i].num;   
}
quickSort(A,0,n-1);
for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
}
return 0;
}
void quickSort(int A[],int p,int r){
    if(p<r){
        int q=partition(A,p,r);//基準の位置を返す
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);//rは含む
    }
}
int partition(int A[],int p,int r){
int i=p-1,j;
 tmp=A[j];
        A[j]=A[i];
        A[i]=tmp;
    }
    j++;
}
int tmp=A[i+1];
A[i+1]=A[r];
}
/*int n,i,j;
scanf("%d",&n);
int A[n];
for(i=0;i<n;i++)scanf("%d",A+i);
i=-1; j=0;
while(j!=n-1){
if(A[j]<=A[n-1]){//<=じゃないとだめなのか
    i++;//ここで戦線を前進させたいからiを-1にしておいた
    int tmp=A[i];
    A[i]=A[j];
    A[j]=tmp;  
}
j++;
}
int tmp=A[n-1];
A[n-1]=A[i+1];
A[i+1]=tmp;
int a=i+1;
for(i=0;i<n;i++){
if(i==a)printf("[%d] ",A[i]);
 else if(i==n-1)printf("%d\n",A[i]);
 else printf("%d ",A[i]);
}
//printf("\n");
return 0;
}*/