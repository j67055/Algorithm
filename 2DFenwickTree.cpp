#include<vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class FenwickTree
{
private:
	vvi ft;

	int LSOne(int p)
	{
		return p & (-p);
	}
public:
	FenwickTree(int N)
	{
		ft.assign(N + 1, vi());
		for (int i = 0; i < N + 1; ++i)
			ft[i].assign(N + 1, 0);
	}

	void adjust(int x, int y, int p)
	{
		for (; y < ft.size(); y += LSOne(y))
			for (int _x = x; _x < ft.size(); _x += LSOne(_x))
				ft[y][_x] += p;
	}

	int rsq(int x, int y)
	{
		int sum = 0;
		for (; y; y -= LSOne(y))
			for (int _x = x; _x; _x -= LSOne(_x))
				sum += ft[y][_x];
		return sum;
	}

	int rsq(int x1, int y1, int x2, int y2)
	{
		return rsq(x2, y2) - rsq(x2, y1 - 1) - rsq(x1 - 1, y2) + rsq(x1, y1);
	}

	void rangeUpdate(int x1, int y1, int x2, int y2, int p)
	{
		adjust(x1, y1, p);
		adjust(x2 + 1, y1, -p);
		adjust(x1, y2 + 1, -p);
		adjust(x2 + 1, y2 + 1, p);
	}
};