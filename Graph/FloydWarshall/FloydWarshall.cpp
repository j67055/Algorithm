#include <algorithm>

#define INF 1000000000

using namespace std;

int adjMatrix[102][102];

void FloydWarshall(int N)
{
	fill(&adjMatrix[0][0], &adjMatrix[N][N + 1], INF);

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
					adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
}