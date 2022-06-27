#include<vector>

#define MAX 1000002

using namespace std;

typedef pair<int, int> ii;

int root, rootChildren, order = 0;
int num[MAX], low[MAX], points[MAX];
vector<vector<int>> adjList;
vector<ii> bridge;

void articulationPointAndBridge(int u, int p)
{
	num[u] = low[u] = order++;
	for (int v : adjList[u])
	{
		if (num[v] == -1)
		{
			if (u == root) ++rootChildren;

			articulationPointAndBridge(v, u);

			if (num[u] <= low[v])
				points[u] = 1;

			if (num[u] < low[v])
				bridge.push_back({ u, v });

			low[u] = min(low[u], low[v]);
		}
		else if (v != p)
			low[u] = min(low[u], num[v]);
	}
}

void articulationPointAndBridge(int V)
{
	memset(num, -1, sizeof(num));

	for (int i = 0; i < V; ++i)
		if (num[i] == -1)
		{
			root = i, rootChildren = 0;
			articulationPointAndBridge(i, -1);
			points[i] = rootChildren > 1;
		}
}