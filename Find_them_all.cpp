#include<stdio.h>

int main(){

	int testcase,i,j,n,m;
	char seq[101],vowels[101],consonants[101];

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		n=0;
		m=0;
		
		scanf(" %[^\n]s",seq);

			for(j=0;seq[j]!='\0';j++){
				if(seq[j]=='a'||seq[j]=='e'||seq[j]=='i'||seq[j]=='o'||seq[j]=='u'||seq[j]=='A'||seq[j]=='E'||seq[j]=='I'||seq[j]=='O'||seq[j]=='U'){
					vowels[n]=seq[j];
					n++;
				}else if(seq[j]!=' '){
					consonants[m]=seq[j];
					m++;
				}
			}
		


		vowels[n]='\0';
		consonants[m]='\0';

		printf("Case %d:\n",i);
		printf("%s\n",vowels);
		printf("%s\n\n",consonants);
			
	
	}

	return 0;
}