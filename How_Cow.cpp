#include <stdio.h>

void main(){

	int x1,y1,x2,y2,t,m,i,coordX,coordY;

	scanf("%d",&t);

	for(i=1;i<=t;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		scanf("%d",&m);
		printf("Case %d:\n",i);

		while(m--){
			scanf("%d %d",&coordX,&coordY);

			if(coordX-x1>0 && x2-coordX>0 && coordY-y1>0 && y2-coordY>0)
				printf("Yes\n");
			else
				printf("No\n");

		}
	}


}