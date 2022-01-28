#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 2000000000
void insert(int);
int extractMax(void);
//void heapMake(void);
void heapKeep(int);
int a[N+1];
int arraySize=0;
int main(){
    char buf[11];
    while(1){
        scanf("%s",buf);
        if(0==strcmp("insert",buf)){
            int s;
            scanf("%d",&s);
            insert(s);
        }else if(0==strcmp("extract",buf))printf("%d\n",extractMax());
        else if(0==strcmp("end",buf))break;
        else exit(7);
    }
    return 0;
}
void insert(int s){
    int i;
    arraySize++;//要素の数に等しい    
    a[arraySize]=s;
    i=arraySize;
    //heapMake();
    while(i>1&&a[i]>a[i/2]){
        int tmp=a[i];
        a[i]=a[i/2];
        a[i/2]=tmp;
        i/=2;
    }
       
}
//void heapMake(){for(int i=arraySize/2;i>0;i--)heapKeep(i);}
void heapKeep(int now){
    int l=now*2,r=l+1,largest;
    if(l<=arraySize&&a[l]>a[now])largest=l;
    else largest=now;
    if(r<=arraySize&&a[r]>a[largest])largest=r;
    if(now!=largest){
        int tmp=a[largest];
        a[largest]=a[now];
        a[now]=tmp;
        heapKeep(largest);
    }
}
int extractMax(void){
    //heapMake();//ここにおいて正解。ただまだtle。恐らくa[1]とa[arraySize]の交換ダメ
    int tmp=a[1];
    a[1]=a[arraySize];
    //for(int i=1;i<arraySize+1;i++)a[i]=a[i+1]; tle...
    arraySize--;
    //heapMake();
    heapKeep(1);//heapMakeでは全体を行っていた。insertにおける正位置への代入でこの交換では1を開始地点とするheapkeepで十分だった。
    return tmp;
}
//ペアリングヒープや、フィボナッチヒープ