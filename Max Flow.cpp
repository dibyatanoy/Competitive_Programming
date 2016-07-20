struct EDGE
{
	int u, cf, id, ini;

	EDGE(int a, int b, int d)
	{
		u=a;
		cf=b;
		id=d;
		ini = cf;
	}

	EDGE()
	{
	}
};

#define SIZE 205

struct Max_Flow
{
	int vis[SIZE], p[SIZE], id[SIZE];
	int source, sink;
	int n;

	vector<EDGE> V[SIZE];

	void add_edge(int a, int b, int cf)
	{
		int sz1 = V[a].size();
		int sz2 = V[b].size();

		V[a].push_back(EDGE(b, cf, sz2));
		V[b].push_back(EDGE(a, 0, sz1));
	}


	int augment()
	{
		queue<int> Q;
		int X;
		int sz, j, a, b, now, i;

		for(i = 0; i <= n; i++) p[i] = -1, vis[i] = 0;

		Q.push(source);
		p[source] = -1;
		vis[source] = 1;

		while(!Q.empty())
		{
			X = Q.front();
			Q.pop();

			sz=V[X].size();
			for(j=0;j<sz;j++)
				if(V[X][j].cf>0)
				{
					if(!vis[V[X][j].u])
					{
						vis[ V[X][j].u ] = 1;
						p[ V[X][j].u ] = X;
						id[ V[X][j].u ] = j;
						Q.push( V[X][j].u );
					}
				}
		}

		if(p[sink]==-1) return 0;

		int flow = 1000000000;
		now = sink;

		while(p[now]!=-1)
		{
			a = p[now];
			b = now;

			flow = MIN(flow, V[a][ id[b] ].cf);

			now = p[now];
		}

		now = sink;
		while(p[now]!=-1)
		{
			a = p[now];
			b = now;

			V[a][ id[b] ].cf -= flow;
			V[b][ V[a][id[b]].id ].cf += flow;

			now = p[now];
		}

		return flow;
	}

	//returns total cost, flow is not counted here.
	int total_flow;

	int flow()
	{
		int temp;

		total_flow = 0;

		while( temp = augment() )
		{
			total_flow+=temp;
		}

		return total_flow;
	}

	void clear()
	{
		for(int i = 0; i < SIZE; i++)
			V[i].clear();
	}

	void set(int a, int b)
	{
		source = a;
		sink = b;
	}

	void setN(int a)
	{
		n = a;
	}
};

/*
Max_Flow A;
A.setN(n);
A.set(source, sink);
A.add_edge(s, t, cap);
A.clear();
A.flow();
A.total_flow;
*/
