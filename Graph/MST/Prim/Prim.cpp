#include<algorithm>
#include<vector>
#include<queue>

#define MAX 10002

using namespace std;

typedef pair<int, int> ii;

vector<ii> adjList[MAX];
priority_queue<ii, vector<ii>, greater<ii>> pq;
bool taken[MAX];

void progress(int u)
{
	taken[u] = 1;

	for (ii p : adjList[u])
	{
		int v = p.first, w = p.second;
		if (taken[v]) continue;
		pq.push({ w, v });
	}
}

int prim(int s)
{
	progress(s);

	int cost = 0;
	while (!pq.empty())
	{
		ii p = pq.top(); pq.pop();
		int u = p.second, w = p.first;

		if (taken[u]) continue;

		progress(u);
		cost += w;
	}

	return cost;
}