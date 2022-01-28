#include<stdio.h>
#define N 1000
int main(){
    int n;
    scanf("%d",&n);
    double p[n],q[n+1],c[n+1][n+1],d[n+1],s,t;
    for(int i=0;i<n;i++)scanf("%lf",&p[i]);
    for(int i=0;i<n+1;i++)scanf("%lf",&q[i]);
    c[0][0]=q[0];d[0]=p[0]+q[0];
    for(int i=1;i<n+1;i++){
        c[i][i]=q[i];
        c[i-1][i]=p[i-1]+(q[i-1]+q[i])*2;
        d[i]=d[i-1]+p[i]+q[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            s=c[j][j]+c[j+1][i+j+1];
            for(int k=j;k<i+j;k++){
                t=c[j][k+1]+c[k+2][i+j+1];
                s=s>t?t:s;
            }
            c[j][i+j+1]=s+d[i+j]-d[j-1]+q[i+j+1];
        }
    }
    printf("%lf\n",c[0][n]);
    return 0;
}