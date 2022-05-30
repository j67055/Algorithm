#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

class SegmentTree
{
private:
	int n;
	vll A, st, lazy;

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
		lazyUpdate(p, L, R);

		if (i > R || j < L) return 0;
		if (i <= L && R <= j)
			return st[p];
		else
			return rsq(left(p), i, j, L, (L + R) / 2) + rsq(right(p), i, j, (L + R) / 2 + 1, R);
	}

	void updateRange(int p, int i, int j, ll v, int L, int R)
	{
		lazyUpdate(p, L, R);

		if (i > R || j < L) return;
		if (i <= L && R <= j)
		{
			lazy[p] += v;
			lazyUpdate(p, L, R);
		}
		else
		{
			updateRange(left(p), i, j, v, L, (L + R) / 2);
			updateRange(right(p), i, j, v, (L + R) / 2 + 1, R);

			st[p] = st[left(p)] + st[right(p)];
		}
	}

	void lazyUpdate(int p, int L, int R)
	{
		if (lazy[p])
		{
			st[p] += (ll)(R - L + 1) * lazy[p];

			if (L != R)
			{
				lazy[left(p)] += lazy[p];
				lazy[right(p)] += lazy[p];
			}
			lazy[p] = 0;
		}
	}

public:
	SegmentTree(const vll& _A)
	{
		A = _A;
		n = A.size();
		st.assign(4 * n, 0);
		lazy.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	ll rsq(int i, int j)
	{
		return rsq(1, i, j, 0, n - 1);
	}

	void updateRange(int i, int j, ll v)
	{
		updateRange(1, i, j, v, 0, n - 1);
	}
};