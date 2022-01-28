#include<stdio.h>
void maxHeapify(int *,int);
void buildMaxHeap(int *);
int heapsize;
int main(){
    int n,i;
    scanf("%d",&n);
    int a[n+1];
    heapsize=n;
    for(i=1;i<n+1;i++)scanf("%d",&a[i]);
    buildMaxHeap(a);
    for(i=1;i<n+1;i++)printf(" %d",a[i]);
    printf("\n");
    return 0;    
}
void buildMaxHeap(int a[]){
    for(int i=heapsize/2;i>0;i--){
        maxHeapify(a,i);//ぎりぎり葉じゃないとこから添え字小さいほうへ
        //heapsize--;
    }
}
void maxHeapify(int a[],int now){
    int left=now*2,right=now*2+1,largest;
    if(left<=heapsize&&a[left]>a[now])largest=left;
    else largest=now;
    if(right<=heapsize&&a[right]>a[largest])largest=right;
    if(largest!=now){
        int tmp=a[largest];
        a[largest]=a[now];
        a[now]=tmp;
        maxHeapify(a,largest);//こういうふうに上から下を、下から上にしていく。ここでの再帰が上から下。buildHeapが下から上ってかんじ。
    }
}