#include <stdio.h>

long int vol[102],largest,smallest;
int l_pos,s_pos;

void find_thief(int n){
	int k;
	largest=0;smallest=1000002;
	for(k=0;k<n;k++){
		if(vol[k]>largest){
			largest=vol[k];
			l_pos=k;
		}
		if(vol[k]<smallest){
			smallest=vol[k];
			s_pos=k;
		}
	}
}

int main(){

	int testcase,i,num1,num2,num3,stud,j;
	char names[102][22];

	scanf("%d",&testcase);

	for(i=1;i<=testcase;i++){
		scanf("%d",&stud);

		for(j=0;j<stud;j++){
			scanf("%s",names[j]);
			scanf("%d %d %d",&num1,&num2,&num3);
			vol[j]=num1*num2*num3;
		}

		find_thief(stud);

		if(smallest==largest) printf("Case %d: no thief\n",i);
		else{
			printf("Case %d: ",i);
			/*for(j=0;names[largest][j]!='\0';j++)*/
				printf("%s",names[l_pos]);
			printf(" took chocolate from ");
			/*for(j=0;names[smallest][j]!='\0';j++)*/
				printf("%s",names[s_pos]);

			printf("\n");
		}
	}

	return 0;
}

/* AC !!! */