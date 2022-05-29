#include<vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

class SegmentTree
{
private:
	int n;
	vll st, A;

	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R)
	{
		if (L == R)
			st[p] = A[L];
		else
		{
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);

			st[p] = st[left(p)] + st[right(p)];
		}
	}

	ll rsq(int p, int i, int j, int L, int R)
	{
		if (i > R || j < L) return 0;
		if (i <= L && j >= R) return st[p];

		return rsq(left(p), i, j, L, (L + R) / 2) + rsq(right(p), i, j, (L + R) / 2 + 1, R);
	}

	void update(int p, int i, ll v, int L, int R)
	{
		if (i < L || i > R) return;

		if (L == R && R == i)
		{
			A[i] = v;
			st[p] = v;
		}
		else
		{
			update(left(p), i, v, L, (L + R) / 2);
			update(right(p), i, v, (L + R) / 2 + 1, R);

			st[p] = st[left(p)] + st[right(p)];
		}
	}

public:
	SegmentTree(const vll& _A)
	{
		A = _A;
		n = A.size();
		st.assign(n * 4, 0);
		build(1, 0, n - 1);
	}

	ll rsq(int i, int j)
	{
		return rsq(1, i, j, 0, n - 1);
	}

	void update(int i, ll v)
	{
		update(1, i, v, 0, n - 1);
	}
};