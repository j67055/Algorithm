#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

typedef tuple<int, int, int> iii;

class UnionFind
{
private:
	vector<int> p, rank;

public:
	UnionFind(int n)
	{
		p.assign(n, 0);
		rank.assign(n, 0);
		for (int i = 0; i < n; ++i)
			p[i] = i;
	}

	int findSet(int i)
	{
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}

	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j)
	{
		if (isSameSet(i, j)) return;

		int x = findSet(i), y = findSet(j);
		if (rank[x] < rank[y])
			p[x] = y;
		else
		{
			p[y] = x;
			if (rank[x] == rank[y])
				++rank[x];
		}
	}
};

vector<iii> edgeList;

int kruskal(int vertexCnt)
{
	UnionFind uf(vertexCnt);

	sort(edgeList.begin(), edgeList.end());

	int cost = 0;
	for (iii t : edgeList)
	{
		int u = get<1>(t), v = get<2>(t), w = get<0>(t);

		if (uf.isSameSet(u, v)) continue;

		uf.unionSet(u, v);
		cost += w;
	}

	return cost;
}
