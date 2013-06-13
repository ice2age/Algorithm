#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		c = new int[len];
		p = new bool*[len];
		for (int i = 0; i < len; ++i)
			p[i] = new bool[len];

		c[0] = 0;
		const char* str = s.c_str();
		for (int j = 0; j < len; ++j) {
			c[j] = (j == 0 ? 0 : c[j-1]+1);
			for (int i = j; i >= 0; --i) {
				p[i][j] = false;
				if (str[i] == str[j] && (j-i < 2 || p[i+1][j-1])) {
					p[i][j] = true;
					c[j] = (i == 0 ? 0 : min(c[j], c[i-1] + 1));
				}
			}
		}
		return c[len-1];
	}
private:
	int* c;
	bool** p;
};

int main()
{
	Solution s;
	string str;
	while (cin >> str)
	{
		cout << s.minCut(str) << endl;
	}
	return 0;
}