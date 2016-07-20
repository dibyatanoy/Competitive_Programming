#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MX 200100
#define maxim(a,b) (a>b)? a:b
 
using namespace std;
char seq[104];
int dp[104][28][104],k,n;
bool vis[104][28][104];
int score[28][28];

int call(int pos,char c,int val){
	if(pos==n-1) return 0;
	if(vis[pos][c-'a'][val]) return dp[pos][c-'a'][val];

	int gain=-99999999,i,j;

	for(i=0;i<26;i++){
		if((seq[pos+1]-'a'!=i ) && (val<k)) {gain=maxim(gain,call(pos+1,char(i+'a'),val+1)+score[c-'a'][i]);
		//if(pos==4 &&  c=='s' && i=='e'-'a' && val==5) printf("Here with %c and %c %d %d\n",c,char(i+'a'),score[c-'a'][i],val);
		}
	}
	//if(pos==4 && val==5) printf("Here with %c %d \n",c,gain);
	gain=maxim(gain,call(pos+1,seq[pos+1],val)+score[c-'a'][seq[pos+1]-'a']);

	vis[pos][c-'a'][val]=1;
	return dp[pos][c-'a'][val]=gain;
}


int main(){

	scanf("%s %d",seq,&k);
	n=strlen(seq);

	//printf("%d",k);

	int pairs;
	scanf("%d",&pairs);
	memset(score,0,sizeof(score));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<pairs;i++){
		getchar();
		char a,b;
		int c;
		scanf("%c %c %d",&a,&b,&c);
		//printf("%c %c %d\n",a,b,c);
		score[a-'a'][b-'a']=c;
	}
	
	int ans=-99999999;
	for(int j=0;j<26;j++){
		if((seq[0]-'a') != j && k>=1) ans=maxim(ans,call(0,char('a'+j),1));
	}
	ans=maxim(ans,call(0,seq[0],0));
	printf("%d\n",ans);
	return 0;
}