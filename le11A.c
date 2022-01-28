#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    int m=n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=0;
    while(n--){
        int id,dim,place;
        scanf("%d %d",&id,&dim);
        if(dim==0)continue;
        int index[dim];
        for(int i=0;i<dim;i++)scanf("%d",&index[i]);
        for(int i=0;i<dim;i++)a[id-1][index[i]-1]=1;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(j==m-1)printf("%d",a[i][j]);
            else printf("%d ",a[i][j]);
        }
    printf("\n");
    }
    return 0;
}