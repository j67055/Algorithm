#include<vector>

#define MAX 100002

using namespace std;

int visited[MAX], matched[MAX];
vector<int> adjList[MAX];

int augment(int l)
{
	if (visited[l]) return 0;
	visited[l] = 1;

	for(int r : adjList[l])
		if (matched[r] == -1 || augment(matched[r]))
		{
			matched[r] = l;
			return 1;
		}

	return 0;
}

int bipartiteMaching(int V)
{
	memset(matched, -1, sizeof(matched));

	int mcbm = 0;
	for (int i = 0; i < V; ++i)
	{
		memset(visited, 0, sizeof(visited));
		mcbm += augment(i);'
	}
	
	return mcbm;
}