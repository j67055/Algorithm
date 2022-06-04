#include<vector>
#include<queue>

#define MAX 10000

using namespace std;

int visited[MAX];
vector<int> adjList[MAX];

void bfs(int s)
{
	queue<int> q; q.push(s); visited[s] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v : adjList[u])
		{
			if (visited[v]) continue;
			visited[v] = 1;
			q.push(v);
		}
	}
}