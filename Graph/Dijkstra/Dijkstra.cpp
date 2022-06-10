#include<vector>
#include<queue>

#define INF 1000000000
#define MAX 20002

using namespace std;

typedef pair<int, int> ii;

int dist[MAX];
vector<ii> adjList[MAX];

void dijkstra(int s)
{
	fill(dist, dist + MAX, INF); dist[s] = 0;

	priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push({ 0, s });
	while (!pq.empty())
	{
		ii front = pq.top(); pq.pop();
		int u = front.second, uw = front.first;
		if (dist[u] < uw) continue;
		for (ii p : adjList[u])
		{
			int v = p.first, vw = p.second;
			if (dist[v] > dist[u] + vw)
			{
				dist[v] = dist[u] + vw;
				pq.push({ dist[v], v });
			}
		}
	}
}