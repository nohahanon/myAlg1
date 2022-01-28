#include<stdio.h>
#include<string.h>
#define MAX 20050
#define INF 1e9
void push(char);
char pop(void);//char操作スタックで実装する
int pos,len;
char st[MAX];
int main(){
    double sum=0;//amount water
    int depth[MAX],Min[MAX],mini;//mini has no worth
    int i,S[MAX],pool=0,ans=0;
    char str[MAX],ch;
    scanf("%s",str);
    len=strlen(str);
    pos=0;//what this mean
    for(i=0;i<len;i++){
        if(str[i]=='\\'){//this other \ is for escape
        depth[i]=++pool;
        }else if(str[i]=='/'){
        depth[i]=--pool;
        }else{
            depth[i]=pool;
        }
    }
    mini=INF;
    for(i=len-1;i>=0;i--){
        if(depth[i]<mini){
        mini=depth[i];//minimun upoad
        }
        Min[i]=mini;
    }
    pool=0;
    for(i=0;i<len;i++){
        if(str[i]=='\\'){
            if(i!=len-1&&depth[i]==Min[i])continue;
            push(str[i]);
        }else if(str[i]=='/'){
            ch=pop();
            if(ch!='#'){
                sum+=((pos+1)-0.5)*2;
            }
        }else{
            sum+=pos;
        }
        if(sum>0&&(pos==0)){
            S[pool++]=sum;
            ans+=sum;
            sum=0;
        }
    }
    printf("%d\n%d",ans,pool);
    for(i=0;i<pool;i++){
        printf(" %d",S[i]);
    }
    printf("\n");
return 0;
}

void push(char ch){
    st[pos++]=ch;
}
char pop(){
    if(pos==0){
        return '#';
    }
    return st[--pos];
}