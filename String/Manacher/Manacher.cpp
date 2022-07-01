#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int manacher(string& S)
{
	string T;
	for (char c : S)
	{
		T.push_back('$');
		T.push_back(c);
	}
	T.push_back('$');

	vector<int> A(T.size(), 0);
	int p = 0, r = 0;
	for (int i = 0; i < T.size(); ++i)
	{
		A[i] = i > r ? 0 : min(r - i, A[2 * p - i]);

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 < T.size() && T[i - A[i] - 1] == T[i + A[i] + 1])
			++A[i];

		if (r < i + A[i])
		{
			r = i + A[i];
			p = i;
		}
	}

	return *max_element(A.begin(), A.end());
}