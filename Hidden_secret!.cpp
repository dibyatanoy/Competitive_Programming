#include <stdio.h>

int main(){
	
	int testcase,i,j,k,found;
	char name1[101],name2[101];

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf(" %[^\n]s",name1);
		scanf(" %[^\n]s",name2);

		for(j=0;name1[j]!='\0';j++){
			if(name1[j]>=65&&name1[j]<=90&&name1[j]!=' ')
				name1[j]=name1[j]+'a'-'A';

		}
		for(j=0;name2[j]!='\0';j++){
			if(name2[j]>=65&&name2[j]<=90&&name2[j]!=' ')
				name2[j]=name2[j]+'a'-'A';


		}

		found=1;
		for(j=0;name1[j]!='\0'&&found==1;j++){
			if(name1[j]!=' '){
				for(k=0;name2[k]!='\0';k++){
					found=0;
					if(name2[k]==name1[j]){
						found=1;
						name2[k]='!';
						break;

					}
				}
			}else found=1;
		}
		if(found){
			for(j=0;name2[j]!='\0';j++)
				if(name2[j]!='!'&&name2[j]!=' ') found=0;
		}

		if(found) printf("Case %d: Yes\n",i);
		else printf("Case %d: No\n",i);

	}
	return 0;
}

/** AC!!! **/