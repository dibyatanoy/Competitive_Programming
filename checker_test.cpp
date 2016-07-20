#include <stdio.h>

FILE *in,*out;
int outcount=0,count=0;
bool collist[15],lblist[30],rblist[30];

void output(int table[],int n){
     int i;
     printf("%d",table[0]+1);
     for (i=1;i<=n;i++) printf(" %d",table[i]+1);
     printf("\n");
}

void find(int row,int table[],int n){
    int i,kn,col,flag;
    if (row>n){
               count++;
               if (n>5 && table[0]<(n+1)/2) count++;
               if (outcount++<3) output(table,n);
               }
    else{
    if (row==0 && n>5) kn=n/2; else kn=n;
    for (col=0;col<=kn;col++){
        if (collist[col] || lblist[col+row] || rblist[col-row+n-1]) continue;
        collist[col]=1;
        lblist[col+row]=1;
        rblist[col-row+n-1]=1;
        table[row]=col;
        find(row+1,table,n);
        collist[col]=0;
        lblist[col+row]=0;
        rblist[col-row+n-1]=0;
        }
    }
}

int main(){
    //in=fopen("checker.in","r");
    //out=fopen("checker.out","w");
    int n,i,t[15];
    bool lblist[30],rblist[30];
    scanf("%d",&n);
    for (i=0;i<30;i++) {lblist[i]=0; rblist[i]=0;}
    for (i=0;i<15;i++) collist[i]=0;
    find(0,t,n-1);
    printf("%d\n",count);
    return 0;
}