#include<stdio.h>
#define SENTINEL 1000000000
void mergeSort(int *,int,int);
void merge(int *,int,int,int);
int count=0;
int main(){
  int n,i;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  mergeSort(A,0,n);
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n%d\n",A[n-1],count);
  return 0;
}
void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
  else return;
}
void merge(int A[],int left,int mid,int right){//Aのここからここまでの結合に来ました。完全な\
ソートはまだ済んでいないですけど数少ないし半分それぞれずつは済んでるので楽ですよね。一旦半分\
ずつ配列に確保してからAに戻しましょう。的な。
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;//sentinel用の要素も欲しいからn1n2要素の配列を作る
  int L[n1],R[n2];
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=SENTINEL; R[n2]=SENTINEL;
  i=0; j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
            count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }
}