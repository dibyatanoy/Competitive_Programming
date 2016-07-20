#include <stdio.h>

static char backward[100][52],forward[100][52];
static int fw,bw;

void stackinit(){
	int k,l;
	fw=0;bw=0;
	for(k=0;k<100;k++){
		for(l=0;l<52;l++){
			backward[k][l]='\0';
			forward[k][l]='\0';
		}
	}
}

void push_fw(char curr_pg[100]){
	int k;
	for(k=0;curr_pg[k]!='\0';k++)
		forward[fw][k]=curr_pg[k];

	forward[fw][k]='\0';
	fw++;

}

/*char pop_fw(){
	int i;
	char seq[100];

	fw--;
	for(i=0;forward[fw][i]!='\0';i++)
		seq[i]=forward[fw][i];
	seq[i]='\0';

	return seq[100];

}*/

void push_bw(char curr_pg[100]){
	int k;
	for(k=0;curr_pg[k]!='\0';k++)
		backward[bw][k]=curr_pg[k];

	backward[bw][k]='\0';
	bw++;

}

/*char pop_bw(){
	int i;
	char seq[100];

	bw--;
	for(i=0;backward[bw][i]!='\0';i++)
		seq[i]=backward[bw][i];
	seq[i]='\0';

	return seq[100];

}*/

int is_empty_fw(){
	return(!fw);
}

int is_empty_bw(){
	return(!bw);
}

void empty_fw(){
	int k,l;
	fw=0;
	for(k=0;k<100;k++){
		for(l=0;l<52;l++){
			forward[k][l]='\0';
		}
	}
}

int main(){

	int testcase,i,started,j,a;
	char cmd[100],curr_pg[100],init[24]="http://www.lightoj.com/";
	
	scanf("%d",&testcase);

	
	for(i=1;i<=testcase;i++){
		j=0;
		stackinit();
		started=0;
		for(j=0;j<24;j++)
			curr_pg[j]=init[j];
		curr_pg[j]='\0';

		printf("Case %d:\n",i);


		while(scanf(" %[^\n]s",cmd)==1){
			if(cmd[0]=='V'&&cmd[1]=='I'&&cmd[2]=='S'&&cmd[3]=='I'&&cmd[4]=='T'){
				push_bw(curr_pg);
				for(j=6;cmd[j]!='\0';j++)
					curr_pg[j-6]=cmd[j];
				curr_pg[j-6]='\0';
				printf("%s\n",curr_pg);
				empty_fw();
			
			}else if(cmd[0]=='B'&&cmd[1]=='A'&&cmd[2]=='C'&&cmd[3]=='K'){

				if(is_empty_bw()){
					printf("Ignored\n");
				}else{
					push_fw(curr_pg);

					/*curr_pg=pop_bw();*/
					

					bw--;
					for(a=0;backward[bw][a]!='\0';a++)
						curr_pg[a]=backward[bw][a];
					curr_pg[a]='\0';


					printf("%s\n",curr_pg);
				}
				
			
			}else if(cmd[0]=='F'&&cmd[1]=='O'&&cmd[2]=='R'&&cmd[3]=='W'&&cmd[4]=='A'&&cmd[5]=='R'&&cmd[6]=='D'){
				
				if(is_empty_fw()){
					printf("Ignored\n");

				}else{
					push_bw(curr_pg);
					
					/*curr_pg[100]=pop_fw();*/
					
	

					fw--;
					for(a=0;forward[fw][a]!='\0';a++)
						curr_pg[a]=forward[fw][a];
					curr_pg[a]='\0';

					
					

					printf("%s\n",curr_pg);
				}
			}else if(cmd[0]=='Q'&&cmd[1]=='U'&&cmd[2]=='I'&&cmd[3]=='T')
				break;
		}
	
	}

	return 0;
}