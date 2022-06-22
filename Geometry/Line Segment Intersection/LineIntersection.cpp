#include <string>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Line { pll s, e; };

int ccw(pll mid, pll p1, pll p2)
{
	pll v1 = { p1.first - mid.first, p1.second - mid.second };
	pll v2 = { p2.first - mid.first, p2.second - mid.second };

	ll z = v1.first * v2.second - v1.second * v2.first;
	if (z > 0)
		return 1;
	else if (z == 0)
		return 0;
	else
		return -1;
}

bool isIntersected(Line& l1, Line& l2)
{
	int c1 = ccw(l1.s, l1.e, l2.s) * ccw(l1.s, l1.e, l2.e);
	int c2 = ccw(l2.s, l2.e, l1.s) * ccw(l2.s, l2.e, l1.e);

	if (!c1 && !c2)
	{
		pll a = min(l1.s, l1.e), b = max(l1.s, l1.e), c = min(l2.s, l2.e), d = max(l2.s, l2.e);

		return c <= b && a <= d;
	}

	return c1 + c2 < 0;
}