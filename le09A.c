#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int a[n+1];
    for(i=1;i<n+1;i++)scanf("%d",&a[i]);
    for(i=1;i<n+1;i++){
        printf("node %d: key = %d,",i,a[i]);
        if(i==1)printf(" left key = %d, right key = %d, \n",a[i*2],a[i*2+1]);
        else if(n/2+1<=i)printf(" parent key = %d, \n",a[i/2]);
        else if(i==n/2){
           if(n%2==0)printf(" parent key = %d, left key = %d, \n",a[i/2],a[i*2]);
           else printf(" parent key = %d, left key = %d, right key = %d, \n",a[i/2],a[i*2],a[i*2+1]);
        }
        else printf(" parent key = %d, left key = %d, right key = %d,\n",a[i/2],a[i*2],a[i*2+1]);
    }
    return 0;
}
//parentいないのはrootのみ　parentしかないのは葉のみ
//片方しか子を持たない奴がいるときはのは要素数が偶数の時のみ　この処理は最後の要素を子に持つ奴の時になるからその時に判断する
//葉はn/2+1の要素から

//総評　出力が異質なのはルートと葉と最後の要素を子に持つ要素の時イフ文書きまくれーー
//wonder plucker

//0originなら　親k-1/2 子k+1 k+2となる