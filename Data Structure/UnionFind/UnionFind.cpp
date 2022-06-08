#include<vector>

using namespace std;

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
