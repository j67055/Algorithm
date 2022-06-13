#include<string>

using namespace std;

class Trie
{
private:
	bool isWord;
	Trie* c[26];

	void build(string& s, int p)
	{
		if (p == s.size())
			isWord = true;
		else
		{
			int i = s[p] - 'a';
			if (!c[i])
				c[i] = new Trie();

			c[i]->build(s, p + 1);
		}
	}

	bool find(string& s, int p)
	{
		if (p == s.size()) return isWord;

		int i = s[p] - 'a';
		if (c[i]) return c[i]->find(s, p + 1);

		return 0;
	}

public:
	Trie()
	{
		isWord = 0;
		memset(c, 0, sizeof(c));
	}

	~Trie()
	{
		for (Trie* p : c)
			if (p)
				delete p;
	}

	void build(string& s)
	{
		build(s, 0);
	}

	void find(string& s)
	{
		find(s, 0);
	}
};