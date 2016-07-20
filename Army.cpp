#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXX 10002
#define pb push_back
#define minim(a,b) (a<b)? a:b

using namespace std;

int main(){

	int n,d[102],a,b,i,ans=0;

	scanf("%d",&n);

	for(i=1;i<n;i++){
		scanf("%d",&d[i]);
	}
	scanf("%d%d",&a,&b);

	for(i=a;i<b;i++) ans+=d[i];

	printf("%d\n",ans);

	return 0;
}