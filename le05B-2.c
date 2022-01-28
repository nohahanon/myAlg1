//wiki
#include<stdio.h>
void merge(int *,int *,int,int,int);
void divide(int *,int *,int,int);
int main(){
  int a[10]={5641,569,794,5,612,568,561,541,51,564};
  int b[10]={0};
  const int n=10;//array size
  int i;
  divide(a,b,0,n);
  for(i=0;i<n;i++)printf("%d|",a[i]);
  printf("\n");
  return 0;
}

void divide(int a[],int b[],int left,int right){
  int mid;
  if(left==right||left==right-1)return;
  mid=(left+right)/2;
  divide(a,b,left,mid);
  devide(a,b,mid,right);
  merge(a,b,left,mid,right);
}
void merge(int a[],int b[],int left,int mid,int right){
  int i=left,j=mid,k=0,l;
  while(i<mid&&j<right){
    if(a[i]<=a[j])b[k++]=a[i++];
    else b[k++]=a[j++];
  }
  if(i==mid)while(j<right)b[k++]=a[j++];
  else while(i<mid)b[k++]=a[i++];
  for(l=0;l<k;l++)a[left+l]=b[l];//bに一時保存した部分をaにも反映させる
}
//疑似コードで番兵を使っているのはmarge関数における比較格納作業において片方が\
出きった際比較において勝ってより小さい必要な値を格納してもらわないと困るから
//比較する際同じキー同士を比較するなんてことしないから安定　でもその分一時的な\
配列を確保する必要があるからよくない　あとメモリのスタック領域の場所取りがよくないときもある
//inplace sort メモリ効率のいいその関数の中だけで終わるソートのこと
//このマージソートではoutplace sortで余計にメモリ使わないといけない　二倍のメモリを使う
