//Longest Common Subsequence problem: LCS
//https://qiita.com/_rdtr/items/c49aa20f8d48fbea8bd2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    while(n--){
        char s1[1000],s2[1000];
        scanf("%s\n%s",s1,s2);
        int strlen_s1=strlen(s1),strlen_s2=strlen(s2);
        int a[strlen_s1+1][strlen_s2+1];//(1,1)origin
        for(i=0;i<strlen_s1+1;i++)for(j=0;j<strlen_s2+1;j++)a[i][j]=0;
        for(i=1;i<strlen_s1+1;i++){
            for(j=1;j<strlen_s2+1;j++){
                if(s1[i-1]==s2[j-1])a[i][j]=a[i-1][j-1]+1;
                else a[i][j]=a[i][j-1]>=a[i-1][j]?a[i][j-1]:a[i-1][j];
            }
        }
        printf("%d\n",a[strlen_s1][strlen_s2]);
    }
    return 0;
}