#include <vector>

using namespace std;

class FenwickTree
{
private:
	vector<int> ft;

	int LSOne(int p)
	{
		return p & (-p);
	}
	void adjust(int p, int k)
	{
		for (; p < ft.size(); p += LSOne(p))
			ft[p] += k;
	}

public:
	FenwickTree(int n)
	{
		ft.assign(n + 1, 0);
	}

	int rsq(int p)
	{
		int sum = 0;
		for (; p; p -= LSOne(p))
			sum += ft[p];
		return sum;
	}

	int rsq(int i, int j)
	{
		return rsq(j) - (i == 1 ? 0 : rsq(i - 1));
	}

	void rangeUpdate(int i, int j, int k)
	{
		adjust(i, k);
		adjust(j + 1, -k);
	}
};
