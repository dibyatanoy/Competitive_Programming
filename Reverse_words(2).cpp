#include <stdio.h>
#include <string.h>

int main(){

	int testcase,i,end_pt,k,length,rev_ct,start_pt,j;
	char seq[151],rev[151];

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
	
		scanf(" %[^\n]s",seq);
		length=strlen(seq);

		rev[length]='\0';
		rev_ct=0;

		for(j=length-1,end_pt=length-1;j>=0;j--){
			
			if(seq[j]==' '|| j==0){
				if(j!=0)
					start_pt=j+1;
				else
					start_pt=j;

				for(k=start_pt;k<=end_pt;k++,rev_ct++){
					rev[rev_ct]=seq[k];
				}

				end_pt=j-1;
				rev[rev_ct]=' ';
				rev_ct++;
			
			}
		}

		rev[rev_ct]='\0';

		printf("%s\n",rev);

	
	}

	return 0;
}