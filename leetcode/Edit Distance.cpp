#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.length(), m = word2.length();
		int** c = new int*[n+1];
		for (int i = 0; i <= n; ++i)
			c[i] = new int[m+1];
		for (int i = 0; i <= n; ++i)
			c[i][0] = i;
		for (int j = 0; j <= m; ++j)
			c[0][j] = j;

		//c(i, j) = c(i-1,j-1); or min{c(i-1,j), c(i, j-1)}
		for (int i = 1; i <=n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (word1[i-1] == word2[j-1])
					c[i][j]= c[i-1][j-1];
				else
					c[i][j] = min(c[i-1][j-1], min(c[i-1][j], c[i][j-1])) + 1;
			}
			return c[n][m];
	}
};

int main() {
	Solution s;
	string word1, word2;
	while (cin >> word1 >> word2)
		cout << s.minDistance(word1, word2) << endl;
	return 0;
}