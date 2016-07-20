#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#define MAXX 130

using namespace std;

int tree[MAXX][MAXX][MAXX];
int N;

/**void update_z(int px,int lx,int rx,int py,int ly,int ry,int pz,int lz,int rz,int x,int y,int z,int new_val){
	if(lz==rz){
		if(ly==ry){
			if(lx==rx) tree[px][py][pz]=new_val;
			else tree[px][py][pz]=tree[2*px][py][pz]+tree[2*px+1][py][pz];
		}else{
			if(lx==rx) tree[px][py][pz]=new_val;
			else tree[px][py][pz]=tree[2*px][py][pz]+tree[2*px+1][py][pz];
		}
	}
}

void update_y(int px,int lx, int rx,int py,int ly,int ry,int x,int y,int z,int new_val){
	if(ly!=ry){
		int midy=(ly+ry)/2;
		if(y<=midy){
			update_y(px,lx,rx,2*py,ly,midy,x,y,z,new_val);
		}else{
			update_y(px,lx,rx,2*py+1,midy+1,rx,x,y,z,new_val);
		}
	}
	update_z(px,lx,rx,py,ly,ry,1,0,N-1,x,y,z,new_val);
}

void update_x(int px,int lx, int rx, int x,int y,int z,int new_val){
	if(lx!=rx){
		int midx=(lx+rx)/2;
		if(x<=midx){
			update_x(2*px,lx,mx,x,y,z,new_val);
		}else{
			update_x(2*px+1,mx+1,rx,x,y,z,new_val);
		}
	}
	update_y(px,lx,rx,1,0,N-1,x,y,z,new_val);
}**/

void update(int idx,int idy,int idz,int k){
	int x,y,z;
	for(x=idx;x<=128;x+=(x & -x)){
		for(y=idy;y<=128;y+= (y & -y)){
			for(z=idz;z<=128;z+=(z & -z))
				tree[x][y][z]+=k;
		}
	}
}
int sum(int idx,int idy,int idz){
	int x,y,z,summ=0;
	for(x=idx;x>0;x-=(x & -x)){
		for(y=idy;y>0;y-= (y& -y)){
			for(z=idz;z>0;z-=(z & -z))
				summ+=tree[x][y][z];
		}
	}
	return summ;
}

int main(){

	scanf("%d",&N);
	memset(tree,0,sizeof(tree));
	int M;
	while(scanf("%d",&M)&&M!=3){
		if(M==1){
			int x,y,z,k;
			scanf("%d %d %d %d",&x,&y,&z,&k);
			++x;++y;++z;
			update(x,y,z,k);

		}else{
			int x1,y1,z1,x2,y2,z2;
			scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
			++x1;++y1;++z1;
			++x2;++y2;++z2;
			int result=(sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)+sum(x1-1,y1-1,z2))-(sum(x2,y2,z1-1)-sum(x1-1,y2,z1-1)-sum(x2,y1-1,z1-1)+sum(x1-1,y1-1,z1-1));

			printf("%d\n",result);
		}
	}
	return 0;
}
/** AC!!! My first fenwick tree a.k.a BIT. (though not very elegant :( )**/