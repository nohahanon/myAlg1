#include<stdio.h>
#define N 5
//insertionSort
void insertionSort(void);
//bubbleSort
void bubbleSort(void);
//selectionSort
void selectionSort(void);
//shellSort uhhh
void shellSort(void);
//mergeSort
void mergeSort(int,int);
void merge(int,int,int);
int A[N]={3,5,1,2,4},B[N];
//countingSort
void countingSort(void);
//quickSort
void quickSort(int,int);
int partition(int,int);
int forQ[N]={1,2,3,5,4};
//heapSort
void heapSort(void);
void heapMake(int *);
void heapKeep(int *,int);
int heapsize=N;

//binarySearch
int main(){
    int i;
    insertionSort();
    bubbleSort();
    selectionSort();
    shellSort();
    mergeSort(0,N);///
    printf("mergeSort:\t");
    for(i=0;i<N;i++)printf("%d|",A[i]);
    printf("\n");    
    countingSort();
    quickSort(0,N-1);
    printf("quickSort:\t");
    for(i=0;i<N;i++)printf("%d|",forQ[i]);
    printf("\n");    
    heapSort();
    return 0;
}
void insertionSort(){
    int i,j,A[N]={3,5,1,4,2};
    for(i=1;i<N;i++){
        j=i;
        while((j>0)&&(A[j-1]>A[j])){
            int tmp=A[j];
            A[j]=A[j-1];
            A[j-1]=tmp;
            j--;
        }
    }
    printf("insertionSort:\t");
    for(i=0;i<N;i++)printf("%d|",A[i]);
    printf("\n");
}
void bubbleSort(){
    int i,j,A[N]={5,3,4,2,1};
    for(i=0;i<N;i++){
        for(j=0;j<N-1-i;j++){
            if(A[j]>A[j+1]){
                int tmp=A[j];
                A[j]=A[j+1];
                A[j+1]=tmp;
            }
        }
    }
    printf("bubbleSort:\t");
    for(i=0;i<N;i++)printf("%d|",A[i]);
    printf("\n");
}
void selectionSort(){
    int i,j,A[N]={4,1,5,2,3};
    int min;
    for(i=0;i<N-1;i++){
        min=i;
        for(j=i;j<N;j++)if(A[min]>A[j])min=j;
        if(min==i)continue;
        int tmp=A[i];
        A[i]=A[min];
        A[min]=tmp;
    }
    printf("selectionSort:\t");
    for(i=0;i<N;i++)printf("%d|",A[i]);
    printf("\n");    
}
void shellSort(){
    int i,j,k,x=1,m=0,A[N]={1,5,4,3,2},g[20];
    for(i=0;x<=N;i++){
        g[i]=x;
        x=3*x+1;
        m++;
    }
    for(k=m-1;k>=0;k--){
        for(i=g[k];i<N;i++){
            int v=A[i];
            j=i-g[k];
            while(j>=0&&A[j]>v){
                A[j+g[k]]=A[j];
                j-=g[k];
            }
            A[j+g[k]]=v;
        }
    }
    printf("shellSort:\t");
    for(i=0;i<N;i++)printf("%d|",A[i]);
    printf("\n");    
}
void mergeSort(int left,int right){
    int mid=(left+right)/2;
    if(left==right||left==right-1)return;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
}
void merge(int left,int mid,int right){
    int i=left,j=mid,k=0;
    while(i<mid&&j<right){
        if(A[i]<A[j])B[k++]=A[i++];
        else B[k++]=A[j++];
    }
    if(i==mid)while(j<right)B[k++]=A[j++];
    else while(i<mid)B[k++]=A[i++];
    for(i=0;i<k;i++)A[left+i]=B[i];
}
void countingSort(){
    const int n=10;
    int i,A[N]={3,5,2,4,1},B[N+1],C[n];
    for(i=0;i<n;i++)C[i]=0;
    for(i=0;i<N;i++)C[A[i]]++;
    for(i=1;i<n;i++)C[i]+=C[i-1];
    for(i=0;i<N;i++){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
    printf("countingSort:\t");
    for(i=1;i<=N;i++)printf("%d|",B[i]);
    printf("\n");    
}
void quickSort(int p,int r){
    if(p<r){
        int q=partition(p,r);
        quickSort(p,q-1);
        quickSort(q+1,r);
    }
}
int partition(int p,int r){
    int i=p-1,j=p;
    while(j!=r){
        if(forQ[j]<=forQ[r]){
            i++;
            int tmp=forQ[j];
            forQ[j]=forQ[i];
            forQ[i]=tmp;
        }
        j++;
    }
    int tmp=forQ[r];
    forQ[r]=forQ[i+1];
    forQ[i+1]=tmp;
    return i+1;
}
void heapSort(void){
    int a[N+1]={-4,5,4,1,2,3};//i orogin
    heapMake(a);
    for(int i=N;i>1;i--){//i>1は絶対
        int tmp=a[1];
        a[1]=a[heapsize];
        a[heapsize]=tmp;
        heapsize--;
        heapKeep(a,1);
    }
    printf("heapSort:\t");
    for(int i=1;i<N+1;i++)printf("%d|",a[i]);
    printf("\n");
}
void heapMake(int a[]){for(int i=N/2;i>0;i--)heapKeep(a,i);}
void heapKeep(int a[],int now){
    int l=now*2,r=l+1,largest;
    if(l<=heapsize&&a[l]>a[now])largest=l;
    else largest=now;
    if(r<=heapsize&&a[r]>a[largest])largest=r;
    if(largest!=now){
        int tmp=a[now];
        a[now]=a[largest];
        a[largest]=tmp;
        heapKeep(a,largest);
    }    
}
/*
insertion sort　O(n^2)/O(n) 安定 inplace 小さな配列に対しては高速　改良版がシェルソート
まずは0と1を比べソート、次に2と1を比べソート新たに0と1を比べソート、のように領地拡大→ソートを繰り返していく 大富豪の時のあれ

bubble sort O(n^2)/O(n) 安定 inplace　改良版に奇遇転置ソート　交換ソート
jループにおいてはjとj+1要素を比較するため継続条件のところがN-1-iとなっている。端に端に大きな奴を寄せていく。逆もできるけど。

selection sort　O(n^2)/O(n^2)
非比較ソート 非安定ソート　inplace 改良版にヒープソート　各ループごとに最小値も最大値も見つけて両端確定させることもできる
iループがN-1までなのはjループの初期値がiとなるからで、もしi<Nならi==N-1の配列ぎりぎりの時もj++で範囲外になる。これを防ぐためであり、またそのときminもiもjも同じ値になり比較の意味がない。最初からiの方で制限してやろうっていう。
minは最小値の添え字を抱えている。一回のjループごとに必ず見つかるから必ずiループでも交換が生じる。min=iとするところからわかるようにiの場所にふさわしい数を探している。だからi==minのときは最初からお前でよかったんね、とcontinueしている。

shell sort 最悪は間隔に依存/O(nlogn)
非安定ソート　挿入ソートの一般化　挿入ソートの「ほとんど整列されたデータに対しては高速」という長所を間隔を段々狭めていくことで活かす。　最適な幅は未解決問題。

merge sort O(nlogn)/O(nlogn)
outplace sort （ナイーブな）クイックソートと比べると、最悪計算量は少ない。ランダムなデータでは通常、クイックソートのほうが速い。

counting sort ???/O(n+k)
合計スペースもO(n+k)
非比較ソート　基数ソートのサブルーチン

quick sort O(nlogn)/O(n^2) ave->O(nlogn)
inplace sort
 
heapSort O(nlogn)/O(nlogn)
リストの並べ替えを二分ヒープ木を用いて行う
一度完全なヒープを作る。根に最大がいるから最後尾と交換、keepheapを根から行う。また最大値出てくる。を繰り返す。
*/