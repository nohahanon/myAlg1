//not stable
#include<stdio.h>
#define N 10
void keepHeap(int *,int);
void heapSort(int *);
int heapsize=N;
int main(){
  int i;
  int a[N+1]={-1,100056,832,243,11,8,65,1024,12,24,25};//1origin
  heapSort(a);
  //for(i=1;i<N+1;i++)printf("%d|",a[i]);
  printf("\n");
  return 0;
}
void heapSort(int a[]){
  for(int j=0;j<N;j++){
    for(int i=N/2;i>=1;i--)keepHeap(a,i);
    int tmp=a[heapsize];
    a[heapsize]=a[1];
    a[1]=tmp;
    printf("%d|",a[heapsize--]);
  }
}
void keepHeap(int a[],int now){
  int l=now*2,r=now*2+1;
  int largest;
  if(l<=heapsize&&a[l]>a[now])largest=l;
  else largest=now;
  if(r<=heapsize&&a[r]>a[largest])largest=r;//r<=heapsizeの条件わりと必要
  if(largest!=now){
    int tmp=a[now];
    a[now]=a[largest];
    a[largest]=tmp;
    keepHeap(a,largest);
  }
}
