#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0) return 0;
		int n = obstacleGrid[0].size();
		if (n == 0) return 0;
		int** c = new int*[m+1];
		for (int i = 0; i <= m; ++i) {
			c[i] = new int[n+1];
			c[i][0] = 0;
		}
		for (int j = 0; j <= n; ++j) 
			c[0][j] = 0;
			
		c[1][1] = (obstacleGrid[0][0]? 0 : 1);
		for (int i = 1; i <= m; ++i){
			for (int j = 1; j <= n; ++j){
				if (i == 1 && j == 1) continue;
				if (obstacleGrid[i-1][j-1]) c[i][j] = 0;
				else c[i][j] = c[i-1][j] + c[i][j-1];
			}
		}
		return c[m][n];
	}
};

int main() {
	Solution s;
	int m, n, it;
	while (cin >> m >> n){
		vector<vector<int> > vv;
		for (int i = 0; i < m; ++i){
			vector<int> v;
			for (int j = 0; j < n; ++j){
				cin >> it;
				v.push_back(it);
			}
			vv.push_back(v);
		}
		cout << s.uniquePathsWithObstacles(vv) << endl;
	}
	return 0;
}