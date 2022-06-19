#include <vector>
#include <queue>

#define INF 1000000000
#define MAX 2004

using namespace std;

int s, t;
int res[MAX][MAX], parent[MAX], visited[MAX];
vector<int> adjList[MAX];

int augment(int v, int minEdge)
{
	if (v == s) return minEdge;
	if (parent[v] != -1)
	{
		int f = augment(parent[v], min(minEdge, res[parent[v]][v]));
		if (f)
		{
			res[parent[v]][v] -= f; res[v][parent[v]] += f;
			return f;
		}
	}
	return 0;
}

int edmondsKarp()
{
	int mf = 0;
	while (1)
	{
		memset(parent, -1, sizeof(parent));
		memset(visited, 0, sizeof(visited));

		queue<int> q; q.push(s); visited[s] = 1;
		while (!q.empty())
		{
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int v : adjList[u])
			{
				if (!res[u][v] || visited[v]) continue;

				parent[v] = u;

				visited[v] = 1;
				q.push(v);
			}
		}

		if (parent[t] == -1) break;

		int f = augment(t, INF);
		if (!f)break;
		mf += f;
	}

	return mf;
}