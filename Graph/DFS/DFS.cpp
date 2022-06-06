#include<vector>

#define MAX 10000

using namespace std;

int visited[MAX];
vector<int> adjList[MAX];

void dfs(int u)
{
	visited[u] = 1;
	for (int v : adjList[u])
		if (!visited[v]) dfs(v);
}
