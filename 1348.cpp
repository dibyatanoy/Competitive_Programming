#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

VI V[30004];

int dfsTime, dfsStart[30004], dfsEnd[30004];
int tree[60004];
int depth[60004], parent[30004][16];

void dfs(int at, int par)
{
	dfsStart[at] = ++dfsTime;
	depth[at] = depth[par] + 1;
	
	int i, v;

	parent[at][0] = par;
	for(i = 1; i <= 15; i++)
		parent[at][i] = parent[parent[at][i - 1]][i - 1];

	FORN(i, SZ(V[at]))
	{
		v = V[at][i];
		if(v == par) continue;
		dfs(v, at);
	}
	dfsEnd[at] = ++dfsTime;
}

int LCA(int u, int v)
{
	if(depth[u] > depth[v]) swap(u, v);
	
	int i;

	for(i = 15; i >= 0; i--)
	{
		if(depth[v] - (1<<i) >= depth[u])
			v = parent[v][i];
	}

	for(i = 15; i >= 0; i--)
	{
		if(parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	if(u == v) return u;
	return parent[u][0];
}

//return cf[idx]
int read(int idx)
{
	int sum = 0;

	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

//add val to f[idx].
//MaxVal = Just max value of index
void update(int idx ,int val)
{
	while (idx <= 60000)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int genie[30004];

int main()
{
	int T, ks, i, u, v;
	int n, ans, middle, type, q;

	scanf("%d", &T);
	FORAB(ks, 1, T)
	{
		scanf("%d", &n);
		FORN(i, n) 
		{
			scanf("%d", &genie[i + 1]);
			V[i + 1].clear();
		}

		FORN(i, n - 1)
		{
			scanf("%d %d", &u, &v);
			u++, v++;
			V[u].push_back(v);
			V[v].push_back(u);
		}

		dfsTime = 0;
		dfs(1, 0);

		CLR(tree);

		FORN(i, n)
		{
			update(dfsStart[i + 1], genie[i + 1]);
			update(dfsEnd[i + 1], -genie[i + 1]);
		}

		printf("Case %d:\n", ks);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d %d", &type, &u, &v);
			if(type == 1)
			{
				update(dfsStart[u + 1], v - genie[u + 1]);
				update(dfsEnd[u + 1], genie[u + 1] - v);
				genie[u + 1] = v;
			}
			else
			{
				u++, v++;
				middle = LCA(u, v);
				ans = read(dfsStart[u]) + read(dfsStart[v]) - 2 * read(dfsStart[middle]) + genie[middle];
				printf("%d\n", ans);
			}
		}
	}

	return 0;
}
