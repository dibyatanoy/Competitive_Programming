#include <stdio.h>
#include <string.h>

int main(){

	char seq[1001],right[1001],rev[1001];
	int length,i,right_ct,pal;

	scanf(" %[^\n]s",seq);

	while(!(seq[0]=='D' && seq[1]=='O' && seq[2]=='N' && seq[3]=='E')){
		
		length=strlen(seq);
		right_ct=0;
		pal=1;
	
		for(i=0;i<length;i++){
			
				if(seq[i]>=65 && seq[i]<=90){
					right[right_ct]=seq[i]+32;
					right_ct++;
				}else if(seq[i]>=97 && seq[i]<=122){
					right[right_ct]=seq[i];
					right_ct++;
				}
			
			
	
		}

		right[right_ct]='\0';

		for(i=0;i<right_ct;i++)
			rev[i]=right[right_ct-1-i];

		rev[i]='\0';

		for(i=0;i<=right_ct;i++)
			if(right[i]!=rev[i]) pal=0;

		if(pal) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");

		scanf(" %[^\n]s",seq);
	}

	return 0;
}