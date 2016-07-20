/*
ID: dibyapo2
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct data{
	int p;
	int q;
	bool operator <(const data&a)const{
		return p<a.p;
	}
};
struct data2{
	int l;
	int w;
};
vector <data> results;
data2 recs[4];
int mina=30000;
bool taken1[4][4][4][4];
bool taken2[2][2][2][2];

int states1[4];
int states2[4];

int maxim(int a,int b){
	if(a>b) return a;
	return b;
}
int minim(int a,int b){
	if(a<=b) return a;
	return b;
}

void layout1(data2 rec1, data2 rec2,data2 rec3,data2 rec4){
	//printf("rec1= %d %d;rec2=%d %d;rec3=%d %d;rec4=%d %d\n",rec1.l,rec1.w,rec2.l,rec2.w,rec3.l,rec3.w,rec4.l,rec4.w);
	int l=rec1.w+rec2.w+rec3.w+rec4.w;
	int w=maxim(maxim(rec1.l,rec2.l),maxim(rec3.l,rec4.l));
	int area=l*w;
	if(area<mina){
		mina=area;
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.clear();
		results.push_back(temp);
		//if(area==36) {printf("for min, %d %d\n",temp.p,temp.q);printf("rec1= %d %d;rec2=%d %d;rec3=%d %d;rec4=%d %d\n",rec1.l,rec1.w,rec2.l,rec2.w,rec3.l,rec3.w,rec4.l,rec4.w);}
	}else if(area==mina){
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		
		results.push_back(temp);
	}
	return;
}
void layout2(data2 rec1, data2 rec2,data2 rec3,data2 rec4){
	int l=maxim(rec1.w,(rec2.w+rec3.w+rec4.w));
	int w=(rec1.l+maxim(rec2.l,maxim(rec4.l,rec3.l)));
	int area=l*w;
	if(area<mina){
		mina=area;
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.clear();
		results.push_back(temp);
		//if(area==2) printf("for min, %d %d\n",temp.p,temp.q);
	}else if(area==mina){
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		
		results.push_back(temp);
	}
	return;
}
void layout3(data2 rec1, data2 rec2,data2 rec3,data2 rec4){
	int l,w;
	l=(rec4.w+maxim(rec1.w,(rec2.w+rec3.w)));
	w=maxim(rec4.l,(rec1.l+maxim(rec2.l,rec3.l)));
	int area=l*w;
	if(area<mina){
		mina=area;
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.clear();
		results.push_back(temp);
		//if(area==36) {printf("l=%d w=%d\n",l,w);printf("for min, area=%d %d %d\n",min,temp.p,temp.q);printf("rec1= %d %d;rec2=%d %d;rec3=%d %d;rec4=%d %d\n",rec1.l,rec1.w,rec2.l,rec2.w,rec3.l,rec3.w,rec4.l,rec4.w);}
	}else if(area==mina){
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.push_back(temp);
	}
	return;
}
void layout4(data2 rec1, data2 rec2,data2 rec3,data2 rec4){
	int l=rec1.w+rec4.w+maxim(rec2.w,rec3.w);
	int w=maxim(rec1.l,maxim(rec4.l,rec2.l+rec3.l));
	int area=l*w;
	if(area<mina){
		mina=area;
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.clear();
		results.push_back(temp);
		//if(area==36) {printf("for min, %d %d\n",temp.p,temp.q);printf("for min, area=%d %d %d\n",min,temp.p,temp.q);printf("rec1= %d %d;rec2=%d %d;rec3=%d %d;rec4=%d %d\n",rec1.l,rec1.w,rec2.l,rec2.w,rec3.l,rec3.w,rec4.l,rec4.w);};
	}else if(area==mina){
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.push_back(temp);
	}
	return;
}
void layout5(data2 rec1, data2 rec2,data2 rec3,data2 rec4){
	int l,w;
	l=maxim(rec1.l+rec4.l,rec2.l+rec3.l);
	w=maxim(rec1.w+rec2.w,rec3.w+rec4.w);
	if(rec1.l<rec2.l){
		w=maxim(w,rec4.w+rec2.w);
	}
	if(rec1.l+rec4.l>rec2.l){
		w=maxim(w,rec3.w+rec4.w);
	}
	if(rec2.l<rec1.l){
		w=maxim(w,rec3.w+rec1.w);
	}
	w=maxim(w,rec4.w);
	w=maxim(w,rec3.w);
	int area=l*w;
	if(area<mina){
		mina=area;
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.clear();
		results.push_back(temp);
		//if(area==36) {printf("for min, %d %d\n",temp.p,temp.q);printf("rec1= %d %d;rec2=%d %d;rec3=%d %d;rec4=%d %d\n",rec1.l,rec1.w,rec2.l,rec2.w,rec3.l,rec3.w,rec4.l,rec4.w);};
	}else if(area==mina){
		data temp;
		temp.p=minim(l,w);
		temp.q=maxim(l,w);
		results.push_back(temp);
	}
	return;
}

void process(){
	data2 r[4];
	for(int i=0;i<4;i++){
		if(states2[i]==0){
			r[i]=recs[states1[i]];
		}else{
			r[i].l=recs[states1[i]].w;
			r[i].w=recs[states1[i]].l;
		}
	}

	layout1(r[0],r[1],r[2],r[3]);
	layout2(r[0],r[1],r[2],r[3]);
	layout3(r[0],r[1],r[2],r[3]);
	layout4(r[0],r[1],r[2],r[3]);
	layout5(r[0],r[1],r[2],r[3]);
	
	
}

void call2(int rec_no){
	if(rec_no==4){
		//printf("%d %d %d %d\n",states2[0],states2[1],states2[2],states2[3]);
		process();
		return;
	}else{
			for(int j=0;j<2;j++){
				states2[rec_no]=j;
				call2(rec_no+1);
			}
	}
}

int call(int rec_no){
	if(rec_no==4){
		//taken[states1[0]][states1[1]][states1[2]][states1[3]]=1;
		//printf("%d %d %d %d\n",states1[0],states1[1],states1[2],states1[3]);
		call2(0);
		return 0;

	}else{
		bool fnd;
		for(int i=0;i<4;i++){
			fnd=false;
			for(int j=rec_no-1;j>=0;j--){
				if(states1[j]==i){fnd=1;break;}
			}
			if(!fnd){states1[rec_no]=i;call(rec_no+1);}
		}
	}
}

int main(){


	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	int l,w;
	scanf("%d %d",&recs[0].l,&recs[0].w);
	mina=300000;
	results.clear();
	for(int i=1;i<4;i++) scanf("%d %d",&recs[i].l,&recs[i].w);
	int j;

	call(0);

	printf("%d\n",mina);

	sort(results.begin(),results.end());
	for(j=0;j<results.size();j++){
		if(!(results[j].p==results[j-1].p&&results[j].q==results[j-1].q))printf("%d %d\n",results[j].p,results[j].q);
	}
	
	return 0;
}