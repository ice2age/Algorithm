#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
		//c[i, j] = c[i-1, j] + (s[i]==s[j])*c[i-1, j-1]
		int n = S.length(), m = T.length();
		int* c = new int[m+1];
		memset (c, 0, sizeof(int)*(m+1));
		c[0] = 1;
		for (int i = 0; i < n; ++i)
			for (int j = m; j >= 1; --j)
				c[j] += (S[i] == T[j-1]) * c[j-1];
		
		return c[m];
    }
};

int main() {
	Solution so;
	string s, t;
	cin >> s >> t;
	cout << so.numDistinct(s, t);
	return 0;
}