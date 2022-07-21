#include<vector>

#define MAX 100002

using namespace std;

int S[MAX], V[MAX];
vector<int> adjList[MAX];

int getSize(int u, int p = -1)
{
	S[u] = 1;
	for (int v : adjList[u])
	{
		if (V[v] || v == p) continue;
		S[u] += getSize(v, u);
	}
	return S[u];
}

int getCent(int u, int cap, int p = -1)
{
	for (int v : adjList[u])
	{
		if (V[v] || v == p) continue;
		if (S[v] * 2 > cap) return getCent(v, cap, u);
	}
	return u;
}

void dnc(int u)
{
	int cent = getCent(u, getSize(u)); V[cent] = 1;

	//Do something here

	for (int v : adjList[cent])
	{
		if (V[v]) continue;
		dnc(v);
	}
}