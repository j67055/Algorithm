#include<vector>

#define MAX 10000

using namespace std;

int order = 0;
vector<int> visited, num, low, s, adjList[MAX];

int sccOrder = 0;
vector<int> sccIdx;

void scc(int u)
{
	visited[u] = 1;
	s.push_back(u);
	num[u] = low[u] = order++;

	for (int v : adjList[u])
	{
		if (num[v] == -1)
			scc(v);
		if (visited[v])
			low[u] = min(low[u], low[v]);
	}

	if (num[u] == low[u])
	{
		while (1)
		{
			int v = s.back(); s.pop_back(); visited[v] = 0;
			sccIdx[v] = sccOrder;
			if (u == v) break;
		}

		++sccOrder;
	}
}

void tarjanScc(int V)
{
	num.assign(V, -1);
	low.assign(V, 0);
	visited.assign(V, 0);
	sccIdx.assign(V, 0);

	for (int u = 0; u < V; ++u)
		if (num[u] == -1)
			scc(u);
}