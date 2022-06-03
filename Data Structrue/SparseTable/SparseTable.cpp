#define MAX 100000
#define LOG 18

using namespace std;

int A[MAX], spt[MAX][LOG];

void buildSpt()
{
	for (int i = 0; i < MAX; ++i)
		spt[i][0] = A[i];

	for (int k = 1; k < LOG; ++k)
		for (int i = 0; i < MAX; ++i)
		{
			if (i + (1 << (k - 1)) >= MAX) continue;
			spt[i][k] = min(spt[i][k - 1], spt[i + (1 << (k - 1))][k - 1]);
		}
}

int querySpt(int i, int j)
{
	int k = (int)floor(log2(j - i + 1));
	return min(spt[i][k], spt[j - (1 << k) + 1][k]);
}
