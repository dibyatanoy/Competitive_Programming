#include <stdio.h>
#include <stdlib.h>

struct node{
	int seq;
	int passenger;
	struct node *next;
};

static int queue[51],status[21][21],n,m,head,tail;

int all_ridden(){
	int i,j;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			if(status[i][j]!=1) return 0;
	}
	return 1;
}

void status_init(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			status[i][j]=0;
	}
}

void shift_right(int k){
	int l;
	for(l=k-1;l>tail;l--)
		queue[l+1]=queue[l];
	tail++;
}

int remove_next(int seq){
	int k,val;
	for(k=head;k>tail;k--){
		if(status[queue[k]][seq]!=1){
			val=queue[k];
			shift_right(k);
			return val;
			
		}

	}
	return -1;

}

int finished(int l){
	int k;
	for(k=1;k<=m;k++){
		if(status[l][k]!=1) return 0;
	}
	return 1;

}

void push_que(int l){
	queue[tail]=l;
	tail--;
}

int main(){

	int testcase,i,j,time,psngr;
	struct node *t, *x;

	
	scanf("%d",&testcase);
	for(i=1;i<=testcase;i++){
		scanf("%d %d",&n,&m);
		time=0;

		t=(struct node *)malloc(sizeof *t);
		t->seq=1;x=t;t->passenger = -1;

		for(j=2;j<=m;j++){
			t->next=(struct node *)malloc(sizeof *t);
			t=t->next;
			t->passenger = -1;
			t->seq=j;
		}
		t->next=x;

		for(j=20;j>=20-n+1;j--)
			queue[j]=20-j+1;
		head=20;
		tail=j;

		status_init();

		while(!(all_ridden())){
			t=t->next;
			time+=5;
			if((t->passenger)>0){
				psngr=t->passenger;
				status[psngr][t->seq]=1;
				t->passenger=remove_next(t->seq); /*Remember to return -1 if all have ridden*/
				if(!finished(psngr))
					push_que(psngr);
			}else{
				t->passenger=remove_next(t->seq);
			}
		}

		printf("Case %d: %d\n",i,time);

		



	}

	return 0;
}

/*

   ***         ***        ************         *              ***      *
 *           *     *            *             *  *          *     *    *
 *           *     *            *            *    *         *          *
 *			 *     *            *           *      *        *          *
 *  ***		 *     *            *           ********        *          *
 *    *		 *     *            *           *      *        *     *
   **		   ***              *           *      *          ***      *

  */