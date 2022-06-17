#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

#define Abs(a) (a) > 0 ? (a) : -(a)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll primeFactors;

ll mulMod(ll x, ll y, ll mod)
{
	ll re = 0;

	while (y > 1)
	{
		if (y & 1) re = (re + x) % mod;
		x = (x + x) % mod;
		y /= 2;
	}

	return (re + x) % mod;
}

ll powMod(ll x, ll y, ll mod)
{
	ll re = 1;

	while (y > 1)
	{
		if (y & 1) re = mulMod(re, x, mod);
		x = mulMod(x, x, mod);
		y /= 2;
	}

	return mulMod(re, x, mod);
}

bool millerRabin(ll a, ll n)
{
	if (a % n == 0) return false;

	ll k = n - 1, temp;

	while (true)
	{
		temp = powMod(a, k, n);
		if (k & 1) return temp == 1 || temp == n - 1;
		if (temp == n - 1) return true;
		k /= 2;
	}
}

bool isPrime(ll n)
{
	ll a[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

	for (int i = 0; i < 12; ++i)
	{
		if (a[i] == n) return true;
		if (!millerRabin(a[i], n)) return false;
	}

	return true;
}

ll f(ll x, ll c, ll n)
{
	return (mulMod(x, x, n) + c) % n;
}

ll gcd(ll x, ll y)
{
	return y ? gcd(y, x % y) : x;
}

ll pollardRho(ll n)
{
	if (n % 2 == 0) return 2;

	ll x, y, c, g;

	do
	{
		x = y = rand() % n;
		c = rand() % n + 1;
		g = 1;

		while (g == 1)
		{
			x = f(x, c, n);
			y = f(y, c, n);
			y = f(y, c, n);
			g = gcd(Abs(x - y), n);
		}
	} while (g == n);

	return g;
}

void factorize(ll n)
{
	if (n == 1) return;

	if (isPrime(n))
	{
		primeFactors.push_back(n);
		return;
	}

	ll ans = pollardRho(n);

	factorize(ans);
	factorize(n / ans);
}