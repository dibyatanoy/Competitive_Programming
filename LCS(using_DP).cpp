/* Dynamic Programming implementation of LCS problem */
/*#include<stdio.h> 
#include<stdlib.h> 
   
int max(int a, int b); */
   
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
/*int lcs( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; */
   
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   /*for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if(X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } */
     
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
  /* return L[m][n]; 
} */
   
/* Utility function to get max of 2 integers */
/*int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} */
   
/* Driver program to test above function */
/*int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
   
  int m = strlen(X); 
  int n = strlen(Y); 
   
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) ); 
   
  getchar(); 
  return 0; 
}*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
void print_lcs(char b[][20],char x[],int i,int j)
{
     if(i==0 || j==0)
      return;
     if(b[i][j]=='c')
      {
       print_lcs(b,x,i-1,j-1);
       printf(" %c",x[i-1]);
       }
      else if(b[i][j]=='u')
       print_lcs(b,x,i-1,j);
      else
       print_lcs(b,x,i,j-1);
}  
void lcs_length(char x[],char y[])
{
     int m,n,i,j,c[20][20];
     char b[20][20];
     m=strlen(x);
     n=strlen(y);    
     for(i=0;i<=m;i++)
      c[i][0]=0;
     for(i=0;i<=n;i++)
      c[0][i]=0;
     for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
      {
 if(x[i-1]==y[j-1])
 {
   c[i][j]=c[i-1][j-1]+1; 
   b[i][j]='c';           //c stands for left upright cross
   }
 else if(c[i-1][j]>=c[i][j-1])
 {
      c[i][j]=c[i-1][j];
      b[i][j]='u';         //u stands for upright or above
      }
 else
 {
     c[i][j]=c[i][j-1];
     b[i][j]='l';         //l stands for left
     }
 }          
    print_lcs(b,x,m,n);      
 }     
void lcs()
{
     int i,j;
     char x[20],y[20];     
     printf("1st sequence:");
     gets(x);
     printf("2nd sequence:");
     gets(y); 
     printf("\nlcs are:");
     lcs_length(x,y); 
     printf("\n");
     lcs_length(y,x);   
 }
void main()
{
     char ch;
     do
     {
           lcs();
           printf("\nContinue(y/n):");
           ch=getch();
           }
     while(ch=='y'||ch=='Y');
}

