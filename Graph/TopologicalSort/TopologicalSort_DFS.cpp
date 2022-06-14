#include<algorithm>
#include<vector>

#define MAX 10000

using namespace std;

int V, visited[MAX];
vector<int> adjList[MAX], ts;

void dfs(int u)
{
	visited[u] = 1;
	for (int v : adjList[u])
		if (!visited[v]) dfs(v);

	ts.push_back(u);
}

void topologicalSort()
{
	for (int u = 0; u < V; ++u)
		if (!visited[u])
			dfs(u);

	reverse(ts.begin(), ts.end());
}