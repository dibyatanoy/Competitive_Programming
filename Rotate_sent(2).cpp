#include <stdio.h>
#include <string.h>

int main(){

	char seq[1000],ans[500][500];
	int testcase,i,length,row,col,maxrow,j;

	scanf("%d",&testcase);
	
	for(i=1;i<=testcase;i++){
		
		scanf(" %[^\n]s",seq);
		length=strlen(seq);

		for(row=0;row<500;row++){
			for(col=0;col<500;col++)
				ans[row][col]='\0';
		}
		row=0;col=0;
		maxrow=0;

		for(j=0;j<length;j++){
			if(seq[j]=='.'||seq[j]=='!'||seq[j]=='?'){
				ans[row][col]=seq[j];
				if(row>maxrow) maxrow=row;
				row=0;
				col++;
			}else{
				if(!(row==0&&seq[j]==' ')){
					ans[row][col]=seq[j];
					row++;
				}
				
			}
		
		}

		j=col;
		for(row=0,col=0;row<=maxrow;row++){
			for(col=0;col<=j;col++){
				if(!(ans[row][col]=='\0')){
					printf("%c",ans[row][col]);
				}else printf(" ");
				if(col!=j) printf(" ");

			}
			printf("\n");

		}
	}

	return 0;
}