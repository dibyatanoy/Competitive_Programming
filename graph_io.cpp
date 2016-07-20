#include <stdio.h>

#define MAXV	  100
#define MAXDEGREE 50

typedef struct{

	int edges[MAXV+1][MAXDEGREE];
	int degree[MAXV+1];
	int nedges;
	int nvertices;
}graph;

initialize_graph(graph *g){

	
	int i;
	
	g->nvertices=0;
	printf("passed check 2");
	g->nedges=0;
	
	
	for(i=1;i<MAXV;i++)
		g->degree[i]=0;
	printf("passed check 3");
}

insert_edge(graph *g,int x,int y,int directed){
	
	g->edges[x][g->degree[x]]=y;
	g->degree[x]++;

	if(!directed){
		insert_edge(g,y,x,1);
	}else{
		g->nedges ++;
	}

}


read_graph(graph *g,int directed){
	int i;
	int m;
	int x,y;

	printf("passed check 1");
	initialize_graph(g);

	scanf("%d %d",&(g->nvertices),&m);

	for(i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}

}
	

void prt_graph(graph *g)
{
	int i,j;

	for(i=1;i<=g->nvertices;i++){
		printf("%d: ",i);
		for(j=0;j<g->degree[i];j++)
			printf(" %d",g->edges[i][j]);
		printf("\n");
	
	}
}

int main(){

	graph *g;
	int directed=1;

	read_graph(g,directed);
	prt_graph(g);



	return 0;

}