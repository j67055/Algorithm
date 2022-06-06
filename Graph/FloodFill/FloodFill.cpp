#include<vector>

#define MAX 10000

using namespace std;

int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

int N, M, board[MAX][MAX];

bool isOut(int x, int y)
{
	return x < 0 || x >= M || y < 0 || y >= N;
}

void floodFill(int x, int y, int from, int to)
{
	board[y][x] = to;
	for (int i = 0; i < 8; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (isOut(nx, ny)) continue;
		if (board[ny][nx] != from) continue;
		floodFill(nx, ny, from, to);
	}
}

void floodFill(int from)
{
	int to = 0;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			if (board[y][x] == from)
				floodFill(x, y, from, to++);
}