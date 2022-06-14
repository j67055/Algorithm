#include<vector>
#include<queue>

#define MAX 10000

using namespace std;

int V, indegree[MAX];
vector<int> adjList[MAX], ts;

void bfs()
{
	queue<int> q;
	for (int u = 0; u < V; ++u)
		if (!indegree[u])
			q.push(u);

	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v : adjList[u])
			if (!--indegree[v]) q.push(v);

		ts.push_back(u);
	}
}
