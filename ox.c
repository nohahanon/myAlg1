#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 3//table size

void show(void);
int check(int);
void place(int);

char table[N][N];
const char YOU='O',AI='X';

int main(){//main--------------------------------------------------------main
  int i,j,flag=0,turn=N*N;
  srand((unsigned int)time(NULL));
  for(i=0;i<N;i++){//initialize---------------------------------------------
    for(j=0;j<N;j++){
      table[i][j]='-';
    }
  }
  printf("OX Game\ndeveloped by nohanoha\n");
  show();

  while(turn--){
    place(flag);
    if(check(flag))break;
    flag++;
    if(flag%2==0)show();
  }
  //after end----------------------------------------------------------
  if(turn==0&&check(1)==0&&check(0)==0)printf("\n<---RESULT--->\n\nDROW!\n\n");
  else if(flag%2==0)printf("\n<---RESULT--->\n\nYOU(O) ARE THE WINNER!\n\n");
  else printf("\n<---RESULT--->\n\nAI(X) IS THE WINNER!\n\n");
  show();
  printf("\n");
  return 0;
}

void show(){//---------------------------------------------------------------
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf(" %c",table[i][j]);
    }
    printf("\n");
  }
}
void place(int flag){//--------------------------------------------------------
  int i,j;
  if(flag%2==0){//PLAYER SIDE//////////////////////////////////////////////////
    while(1){
    printf("Please input a coordinate --> ");
    scanf("%d%d",&i,&j);
    if(table[i][j]!='-') {
      printf("\n<!--The location is already placed!-->\n\n");
      continue;
    }
         table[i][j]=YOU;
    break;
    }
  }else{//AI SIDE//////////////////////////////////////////////////////////////
    while(1){
      i=rand()%N;
      j=rand()%N;
      if(table[i][j]!='-')continue;
      table[i][j]=AI;
      break;
    }
  }
}

int check(int flag){//--------------------------------------------------------
  char targ;
  int i,j,cnt=0;
  if(flag%2==0)targ=YOU;
  else targ=AI;
  //line
  for(i=0;i<N;i++){
    cnt=0;
    for(j=0;j<N;j++)if(table[i][j]==targ)cnt++;
    if(cnt==N)return 1;
  }
  //row
  for(i=0;i<N;i++){
    cnt=0;
    for(j=0;j<N;j++)if(table[j][i]==targ)cnt++;
    if(cnt==N)return 1;
  }
  //oblique1 コメントの中にバクスラ置いたらコメントアウトが次の行にも続くバグのもと
  cnt=0;
  for(i=0;i<N;i++){
    if(table[i][i]==targ)cnt++;
  if(cnt==N)return 1;
  //oblique2 /
  cnt=0;
  for(i=0;i<N;i++)if(table[i][N-i-1]==targ)cnt++;
  if(cnt==N)return 1;
  //still in the match
  return 0;
  }
}