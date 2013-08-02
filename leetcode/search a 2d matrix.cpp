#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size(); if (m == 0) return false;
		int n = matrix[0].size(); if (n == 0) return false;
		
		int l = 0, h = m*n-1, mid, r, c;
		while (l <= h){
			mid = (l + h) >> 1;
			r = mid / n;
			c = mid - r*n;
			if (matrix[r][c] == target)
				return true;
			else if (matrix[r][c] > target)
				h = mid - 1;
			else
				l = mid + 1;
		}
		return false;
	}
};

void print(vector<vector<int > >& m) {
	int n = m.size();
	cout << endl;
	for (int i = 0; i < n; ++i){
		copy(m[i].begin(), m[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

int main() {
	
	Solution s;
	vector<vector<int> > vv;
	int c = 0;
	for (int i = 0; i < 3; ++i){
		vector<int> v;
		for (int j = 0; j < 4; ++j)
			v.push_back(c++);
		vv.push_back(v);
	}
	print (vv);
	while (cin >> c)
		cout << s.searchMatrix(vv, c) << endl;
	return 0;
}