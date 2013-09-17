#include <cmath>
#include <limits>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size(); // m x n
		int** c = new int*[m];
		for (int i = 0; i < m; ++i){
			c[i] = new int[n];
			memset(c[i], 0, sizeof(int)*n);
		}
		for (int i = 0; i < m; ++i){
			c[i][0] = matrix[i][0] == '1' ? 1 : 0;
			for (int j = 1; j < n; ++j){
				c[i][j] = matrix[i][j] == '1' ? (c[i][j-1]+1) : 0;
			}
		}
		int ret = 0;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				int width = numeric_limits<int>::max();
				for (int k = i; k >= 0; --k) {
					width = min(width, c[k][j]);
					ret = max(ret, width*(i-k+1));
				}
			}
		}
		return ret;
	}
};

int main() {
	string str;
	vector<vector<char> > mat;
	while (cin >> str){
		vector<char> line;
		for (int i = 0; i < str.length(); ++i)
			line.push_back(str[i]);
		mat.push_back(line);
	}
	
	Solution s;
	cout << s.maximalRectangle(mat) << endl;
	return 0;
}