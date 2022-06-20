#include <vector>
#include <queue>

#define INF 1000000000
#define MAX 2004

using namespace std;

int s, t;
int res[MAX][MAX], level[MAX], work[MAX];
vector<int> adjList[MAX];

int augment(int u, int minEdge)
{
	if (u == t) return minEdge;

	for (int& i = work[u]; i < adjList[u].size(); ++i)
	{
		int v = adjList[u][i];
		if (level[v] != level[u] + 1 || !res[u][v]) continue;
		int f = augment(v, min(minEdge, res[u][v]));
		if (f)
		{
			res[u][v] -= f, res[v][u] += f;
			return f;
		}
	}

	return 0;
}

int dinic()
{
	int mf = 0;
	while (1)
	{
		memset(level, -1, sizeof(level));
		memset(work, 0, sizeof(work));

		queue<int> q; q.push(s); level[s] = 0;
		while (!q.empty())
		{
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int v : adjList[u])
			{
				if (level[v] != -1 || !res[u][v]) continue;
				level[v] = level[u] + 1;
				q.push(v);
			}
		}

		if (level[t] == -1) break;

		int bf = 0;
		while (1)
		{
			int f = augment(INF, s);
			if (!f) break;
			bf += f;
		}

		if (!bf) break;
		mf += bf;
	}

	return mf;
}