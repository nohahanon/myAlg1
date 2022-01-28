//大きい順で並べたい
//ばばっとならべるというより一つずつ取り出したい
//le12C.cじゃid要素持たせたほうがよさそう
//配列の管理がずさん　失敗
#include<stdio.h>
#include<stdlib.h>
int heapsort(int *);
void heapkeep(int *,int);
int heapsize;
int num;

int main(){
    scanf("%d",&num);
    int a[num+1];//1origin
    for(int i=1;i<num+1;i++)scanf("%d",&a[i]);
    heapsize=num;
    while(1){
        printf("input 0 to dequeue (exit:999) -> ");
        scanf("%d",&num);
        if(num==0)printf("%d\n",heapsort(a));
        else if(num==999)exit(1);
    }
    return 0;
}

int heapsort(int a[]){
    for(int i=num/2;i>=1;i--)heapkeep(a,i);
    int tmp=a[heapsize];
    a[heapsize]=a[1];
    a[1]=tmp;
    return a[heapsize--];
}
void heapkeep(int a[],int now){
    int l=now*2,r=l+1,smallest;
    if(l<=heapsize&&a[l]<a[now])smallest=l;
    else smallest=now;
    if(r<=heapsize&&a[r]<a[smallest])smallest=r;
    if(smallest!=now){
        int tmp=a[now];
        a[now]=a[smallest];
        a[smallest]=tmp;
        heapkeep(a,smallest);
    }
}