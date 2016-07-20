#include<stdio.h> 
 
#include<math.h> 
 
#include<string.h> 
 
int dec_to_bin(int); 
 
int main() 
 
{ 
 
int i,n,m; 
 
char s[10]; 
 
char ch[2]; 
 
printf("\nEnter the no of bits : "); 
 
scanf("%d",&n); 
 
ch[0]=(char)(n+48); //Converting value of n into character 
 
ch[1]='\0'; 
 
strcpy(s,"\n%0"); 
 
strcat(s,ch); 
 
strcat(s,"d"); //s contains following string "%0nd" where n is the no of bits 
 
m=pow(n,2)-1; 
 
for(i=0;i<=m;i++) 
 
{ 
 
printf(s,dec_to_bin(i)); 
 
} 
 
return 1; 
 
} 
 
 
int dec_to_bin(int i) 
 
{ 
 
int b=0,pos=0,remainder; 
 
while(i>0) 
 
{ 
 
remainder=i%2; 
 
b+=remainder*pow(10,pos++); 
 
i/=2; 
 
} 
 
return b; 
 
}


