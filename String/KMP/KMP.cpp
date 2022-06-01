#include <string>

#define MAX 1000002

using namespace std;

string T, P;
int b[MAX];

void kmpPreprocess()
{
	int i = 0, j = -1; b[0] = -1;
	while (i < P.size())
	{
		while (j != -1 && P[i] != P[j]) j = b[j];
		++i, ++j;
		b[i] = j;
	}
}

bool kmpSearch()
{
	int i = 0, j = 0;
	while (i < T.size())
	{
		while (j != -1 && T[i] != P[j]) j = b[j];
		++i, ++j;
		if (j == P.size()) return 1;
	}

	return 0;
}