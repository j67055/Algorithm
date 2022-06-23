#include <vector>

#define MAX 1002

using namespace std;

int N, adjMatrix[MAX][MAX], work[MAX];
vector<int> path;

//���Ϸ� ���/����Ŭ�� ������ ��쿡�� ��밡��.
void eulerCycle(int u)
{
	for (int& v = work[u]; v < N; ++v)
	{
		if (adjMatrix[u][v])
		{
			--adjMatrix[u][v], --adjMatrix[v][u];
			eulerCycle(v);
		}
	}

	path.push_back(u);
}