#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool found;
	string s1, s2, s3;

	bool search(int i, int j, int k){
		if (found) return true;
		if (k == s3.length()){
			found = true;
			return true;
		}
		else if (i == s1.length())
			return s2.substr(j) == s3.substr(k);
		else if (j == s2.length())
			return s1.substr(j) == s3.substr(k);

		if (i < s1.length() && s1[i] == s3[k])
			if (!found && search(i+1, j, k+1))
				return true;

		if (j < s2.length() && s2[j] == s3[k])
			if (!found) return search(i, j+1, k+1);
		return false;
	}

	bool isInterleave(string s1, string s2, string s3) {
		int n = s1.length(), m = s2.length(), l = s3.length();
		if (n + m != l) return false;
		bool** c = new bool*[n+1];
		for (int i = 0; i < n+1; ++i)
			c[i] = new bool[m+1];
		c[0][0] = true;
		for (int i = 1; i <= n; ++i)	
			c[i][0] = c[i-1][0] && s1[i-1] == s3[i-1];
		for (int j = 1; j <= m; ++j)
			c[0][j] = c[0][j-1] && s2[j-1] == s3[j-1]; 
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				c[i][j] = false;
				if (s1[i-1] == s3[i+j-1]) c[i][j] |= c[i-1][j];
				if (s2[j-1] == s3[i+j-1]) c[i][j] |= c[i][j-1];
			}
		}
		return c[n][m];
	}
};

int main() {
	string s1, s2, s3;
	Solution s;
	while (cin >> s1 >> s2 >> s3)
		cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}