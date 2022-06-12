#include<vector>

#define INF 1000000000
#define MAX 20002

using namespace std;

typedef pair<int, int> ii;

int V, dist[MAX];
vector<ii> adjList[MAX];

void bellmanFord(int s)
{
	fill(dist, dist + MAX, INF); dist[s] = 0;

	for(int i = 0; i < V - 1; ++i)
		for(int u = 0; u < V; ++u)
			for (ii p : adjList[u])
			{
				int v = p.first, w = p.second;
				dist[v] = min(dist[v], dist[u] + w);
			}

}