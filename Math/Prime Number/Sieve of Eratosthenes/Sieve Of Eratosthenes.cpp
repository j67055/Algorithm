#include <bitset>
#include <vector>

#define MAX 10000002

using namespace std;

typedef long long ll;

bitset<MAX> bs;
vector<int> primes;

void sieve()
{
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < MAX; ++i)
		if (bs[i])
		{
			for (ll j = i * i; j < MAX; j += i)
				bs[j] = 0;
			primes.push_back((int)i);
		}
}

bool isPrime(ll num)
{
	if (num < MAX)
		return bs[num];
	else
		for (int i = 0; i < primes.size(); ++i)
		{
			ll p = (ll)primes[i];
			if (p * p <= num)
				if (num % p == 0) return false;
		}

	return true;
}