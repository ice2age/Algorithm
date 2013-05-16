#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
#include <utility>

using namespace std;
typedef long long Loong;

const int MAX_LEN = 10000;
struct Tree
{
	char value;
	Tree* left;
	Tree* right;

	Tree(char v) : value(v), left(NULL), right(NULL) {}
	Tree(char v, Tree* l, Tree* r) : value(v), left(l), right(r) {}

	void revLayerOrder(int n)
	{
		char result[MAX_LEN];
		result[n] = 0;
		queue<Tree*> que;
		que.push(this);
		while (!que.empty())
		{
			Tree* tree = que.front();
			que.pop();
			result[--n] = tree->value;
			if (tree->left)
				que.push(tree->left);
			if (tree->right)
				que.push(tree->right);
		}
		puts(result);
	}
};

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	char line[MAX_LEN];
	cin >> n;
	while (n--)
	{
		stack<Tree*> stk;
		cin >> line;
		int len = strlen(line);
		for (int i = 0; i < len; ++i)
		{
			char v = line[i];
			if (islower(v))
				stk.push(new Tree(v));
			if (isupper(v))
			{
				Tree* tb = stk.top(); stk.pop();
				Tree* ta = stk.top(); stk.pop();
				stk.push(new Tree(v, ta, tb));
			}
		}
		stk.top()->revLayerOrder(len);
	}

	return 0;
}