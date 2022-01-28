#include<stdio.h>
#include<stdlib.h>
#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)
#define p(i) i/2
void out(int a){
    char i=0,str[10];
    do str[i++]=(a%10)|0x30,a/=10;while(a>0);
    while(i--)pc(str[i]);
}
int in(){
    int ret=0,ch;
    while((ch=gc())>' ')ret=ret*10+(ch&0xf);
    return ret;
}
int cmp(const void *a,const void *b){return *(int *)a-*(int *)b;}
int i,j,tmp,n,a[200001];
int main(){
    n=in();
    for(i=0;i<n;i++)a[i]=in();//in() is equal for scanf()!
    qsort(a,n,4,cmp);//backcallFunction!!
    a[n]=a[0];
    for(i=1;i<n;i++){
        j=i;
        while(p(j)>0&&a[j]>a[p(j)]){
            tmp=a[j],a[j]=a[p(j)],a[p(j)]=tmp;
            j=p(j);
        }
    }
    for(int i=1;i<n;i++)out(a[i]),pc(' ');
    out(a[n]),pc('\n');
    return 0;
}

/*#include<stdio.h>
void heapSort(int *);
void makeHeap(int *);
void keepHeap(int *,int);
int heapsize,arraysize;
int main(){
    int n,i;
    scanf("%d",&n);
    int a[n+1];
    heapsize=arraysize=n;    
    for(i=1;i<n+1;i++)scanf("%d",&a[i]);
    heapSort(a);
    for(i=1;i<n+1;i++)printf(" %d",a[i]);
    printf("\n");
    return 0;
}
void heapSort(int a[]){
    makeHeap(a);//ここで基本的なヒープ構造は完成している
    for(int i=arraysize;i>1;i--){//ここでは最大値の抽出とヒープの維持が行われる
        //keepHeap(a,i);
        int tmp=a[1];
        a[1]=a[i];
        a[i]=tmp;
        heapsize--;
        keepHeap(a,1);//1を開始地点とするのはヒープが完成しているため上から最大値の正位置への移動だけで済む
    }
}
void makeHeap(int a[]){for(int i=arraysize/2;i>0;i--)keepHeap(a,i);}
void keepHeap(int a[],int now){
    int l=now*2,r=l+1,largest;
    if(l<=heapsize&&a[l]>a[now])largest=l;
    else largest=now;
    if(r<=heapsize&&a[r]>a[largest])largest=r;
    if(largest!=now){
        int tmp=a[now];
        a[now]=a[largest];
        a[largest]=tmp;
        keepHeap(a,largest);
    }
}
//なるほど完全二分木のヒープ構造を用いたソート。深さも安定だしinplaceやるなこいつ
*/