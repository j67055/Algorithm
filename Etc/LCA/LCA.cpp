#include<vector>

#define MAX 100010
#define LOG 20

using namespace std;

int N, L[MAX], P[MAX][LOG];
vector<int> adjList[MAX];

void dfs(int u)
{
	for (int v : adjList[u])
	{
		if (L[v] != -1) continue;
		L[v] = L[u] + 1;
		P[v][0] = u;
		dfs(v);
	}
}

void buildSpt()
{
	for (int k = 1; k < LOG; ++k)
		for (int i = 1; i <= N; ++i)
			P[i][k] = P[P[i][k - 1]][k - 1];
}

void init()
{
	memset(L, -1, sizeof(L)); L[1] = 0;
	dfs(1);
	buildSpt();
}

int query(int u, int v)
{
	if (L[u] > L[v]) swap(u, v);

	int sub = L[v] - L[u];
	for (int k = 0; (1 << k) <= sub; ++k)
	{
		int mask = 1 << k;
		if (mask & sub)
		{
			v = P[v][k];
		}
	}

	if (v != u)
	{
		for (int k = LOG - 1; k >= 0; --k)
			if (P[u][k] != P[v][k])
				v = P[v][k], u = P[u][k];

		v = u = P[u][0];
	}

	return v;
}