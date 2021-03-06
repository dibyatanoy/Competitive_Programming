#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN (1<<20)

typedef long long int64;
typedef struct {
	double R; double I;
} cdouble;

cdouble operator+(cdouble a, cdouble b) { cdouble c=(cdouble){a.R+b.R, a.I+b.I}; return c; }
cdouble operator-(cdouble a, cdouble b) { cdouble c=(cdouble){a.R-b.R, a.I-b.I}; return c; }
cdouble operator*(cdouble a, cdouble b) { cdouble c=(cdouble){a.R*b.R-a.I*b.I, a.R*b.I+a.I*b.R}; return c; }
cdouble operator/(cdouble a, int n) { cdouble c=(cdouble){a.R/n, a.I/n}; return c; }
cdouble operator*(cdouble a, double d) { cdouble c=(cdouble){a.R*d, a.I*d}; return c; }
cdouble conj(cdouble a) { cdouble c=(cdouble){a.R, -a.I}; return c; }

double PI = acos(-1);

void FFTrec(cdouble *f, int n, cdouble w) {
	if (n==2) {
		cdouble a=f[0], b=f[1];
		f[0]=a+b; f[1]=a-b;
	} else {
		cdouble w2=w*w;
		int n2=n/2;
		FFTrec(f,n2,w2); FFTrec(f+n2,n2,w2);
		cdouble wi=(cdouble){1,0};
		for (int i=0;i<n2;i++) {
			cdouble g=wi*f[i+n2];
			f[i+n2]=f[i]-g;
			f[i]=f[i]+g;
			wi=wi*w;
		}
	}
}

void FFT(cdouble *a, int k, cdouble *f, int inv=-1) {
	int n=1<<k;
	for (int i=0;i<n;i++) {
		int rev=0, x=i;
		for (int j=0;j<k;j++) { rev=rev*2+(x&1); x>>=1; }
		f[rev]=a[i];
	}
	cdouble w = (cdouble){cos(inv*2*PI/n), sin(inv*2*PI/n)};
	FFTrec(f,n,w);
	if (inv==1) for (int i=0;i<n;i++) f[i]=f[i]/n;
}

cdouble ff[MAXN], gg[MAXN];
void conv(cdouble *f, cdouble *g, int k, cdouble *fg, int real=1) {
	int n=1<<k;

	if (real) {
		for (int i=0;i<n;i++) f[i].I=g[i].R;
		FFT(f,k,g);
		for (int i=0;i<n;i++) {
			ff[i]=(g[i]+conj(g[(n-i)%n]))*0.5;
			gg[i]=(cdouble){0,-1}*(g[i]-conj(g[(n-i)%n]))*0.5;
		}

		for (int i=0;i<n;i++) f[i]=ff[i]*gg[i];

		cdouble w=(cdouble){1,0}, wi=(cdouble){cos(2*PI/n), sin(2*PI/n)};
		cdouble fe, fo;
		for (int i=0;i<n/2;i++,w=w*wi) {
			fe=(f[i]+conj(f[n/2-i]))*0.5; fo=(f[i]-conj(f[n/2-i]))*w*0.5;
			g[i]=fe+(cdouble){0,1}*fo;
		}

		FFT(g,k-1,f,1);
		for (int i=0;i<n/2;i+=2) {
			fg[i]=(cdouble){f[i/2].R, 0};
			fg[i+1]=(cdouble){f[i/2].I, 0};
		}
	} else {
		FFT(f,k,ff); FFT(g,k,gg);
		for (int i=0;i<n;i++) f[i]=ff[i]*gg[i];
		FFT(f,k,fg,1);
	}
}

#define MAX 666

int resFFT[MAX][MAX],xx[MAX][MAX],yy[MAX][MAX];
int sx[2][MAX][MAX],sy[2][MAX][MAX];
cdouble x[MAXN],y[MAXN],z[MAXN];

void calcSums(int a[MAX][MAX], int s[2][MAX][MAX], int r, int c) {
	for (int i=0;i<r;i++) for (int j=0;j<c;j++) for (int p=0;p<2;p++) {
		if (p==0) s[p][i][j]=a[i][j]; else s[p][i][j]=a[i][j]*a[i][j];
		if (0<=i-1) s[p][i][j]+=s[p][i-1][j];
		if (0<=j-1) s[p][i][j]+=s[p][i][j-1];
		if (0<=i-1 && 0<=j-1) s[p][i][j]-=s[p][i-1][j-1];
	}
}

int getSum(int s[MAX][MAX], int r1, int c1, int r2, int c2) {
	int sum=s[r2][c2];
	if (0<=r1-1) sum-=s[r1-1][c2];
	if (0<=c1-1) sum-=s[r2][c1-1];
	if (0<=r1-1 && 0<=c1-1) sum+=s[r1-1][c1-1];
	return sum;
}

pair<int,pair<int,int> > score[MAX*MAX];

int main() {

	int r,c,rp,cp,r0,c0,sol;
	scanf("%d %d",&r,&c);
	int kr,nr,kc,nc,n;
	for (kr=1;(1<<kr)<r;kr++);
	for (kc=1;(1<<kc)<c;kc++);
	nr=1<<kr; nc=1<<kc; n=nr*nc;

	for (int i=0;i<r;i++) for (int j=0;j<c;j++) { scanf("%d",&xx[i][j]); x[i*nc+j]=(cdouble){xx[i][j],0}; }
	scanf("%d %d",&rp,&cp);
	for (int i=0;i<rp;i++) for (int j=0;j<cp;j++) {
		scanf("%d",&yy[i][j]); y[(n-(i*nc+j))%n]=(cdouble){yy[i][j],0};
	}
	scanf("%d %d",&r0,&c0); r0--; c0--;
	scanf("%d",&sol);
	calcSums(xx,sx,r,c); calcSums(yy,sy,rp,cp);

	conv((cdouble*)x,(cdouble*)y,kr+kc,(cdouble*)z);

	int st=0;
	for (int i=0;i+rp<=r;i++) {
		for (int j=0;j+cp<=c;j++) {
			int h=xx[i+r0][j+c0];
			resFFT[i][j] = sy[1][rp-1][cp-1] + 2*h*sy[0][rp-1][cp-1] + rp*cp*h*h;
			resFFT[i][j] += getSum(sx[1],i,j,i+rp-1,j+cp-1) -2*h*getSum(sx[0],i,j,i+rp-1,j+cp-1);
			resFFT[i][j] += -2*(int)round(z[i*nc+j].R);
			score[st++]=make_pair(resFFT[i][j],make_pair(i+1,j+1));
		}
	}

	sort(score,score+st);
	for (int i=0;i<sol;i++) printf("%d %d %d\n",score[i].second.first, score[i].second.second, score[i].first);

	return 0;
}
