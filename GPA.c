#include<stdio.h>
char scoreToGrade(int);
int gradeToPoint(char);
int main(){
    char a;
    int pre_score,pre_degree,gpa_son=0,degree=0;
    while(1){
        printf("評点と単位数を入力してください (Ctrl+Dで終了): ");
        if(EOF==scanf("%d%d",&pre_score,&pre_degree))break;
        a=scoreToGrade(pre_score);
        printf("%dの評価は%cで、Grade Point(GP)は%dです。(%d単位)\n"
        ,pre_score,a,
        gradeToPoint(a),pre_degree);
        degree+=pre_degree;
        gpa_son+=(pre_degree)*(gradeToPoint(a));
    }
printf("Grade Point Average (GPA): %f,  単位数: %d\n",(double)gpa_son/degree,degree);
return 0;
}

char scoreToGrade(int score){
if(score<=34)return 'F';
else if(score<=49)return 'D';
else if(score<=64)return 'C';
else if(score<=79)return 'B';
else if(score<=100)return 'A';
}

int gradeToPoint(char c){
if(c=='F'||c=='D')return 0;
else if(c=='C')return 2;
else if(c=='B')return 3;
else if(c=='A')return 4;
}
