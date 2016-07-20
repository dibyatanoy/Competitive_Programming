#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int minim(int a,int b){
	return (a<b)? a:b;
}

int main(){

	int n,a=100010,b=100010,c=100010,d=100010;
	int ans1=-1,ans2,ans3,curr=a+c;

	scanf("%d",&n);
	for(int i=0;i<4;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int g1=minim(a,b);
		int g2=minim(c,d);

		if(g1+g2<curr&&(g1+g2)<=n){
			curr=g1+g2;
			ans1=i+1;
			ans2=g1;
			ans3=n-g1;
		}

	}
	if(ans1==-1) printf("-1\n");
	else{
		printf("%d %d %d\n",ans1,ans2,ans3);
	}

	return 0;
}