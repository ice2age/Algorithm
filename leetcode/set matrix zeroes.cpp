#include <time.h>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;


class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int m = matrix.size(); if (m == 0) return;
		int n = matrix[0].size(); if (n == 0) return;
		
		bool row = false, col = false;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (matrix[i][j] == 0){
					matrix[i][0] = 0;
					matrix[0][j] = 0;
					if (i == 0) row = true;
					if (j == 0) col = true;
				}
			}
		}
		
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}
		if (row) memset(&matrix[0][0], 0, sizeof(int)*n);
		if (col) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
	}
};

void print(vector<vector<int > >& m) {
	int n = m.size();
	for (int i = 0; i < n; ++i){
		copy(m[i].begin(), m[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main() {
	Solution s;
	while (true) {
		time(NULL);
		vector<vector<int> > vv;
		int c = 0;
		for (int i = 0; i < 5; ++i){
			vector<int> v;
			for (int j = 0; j < 5; ++j)
				v.push_back(rand() % 10);
			vv.push_back(v);
		}
		print (vv);
		s.setZeroes(vv);
		print (vv);
		printf("continue ? 'y' or 'n': ");
		char ch = getchar();
		getchar();
		if (ch != 'y')
			break;
	}
	
	return 0;
}