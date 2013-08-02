#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; ++i){
			if (2*i >= n-1)
				break;
			for (int j = i; j < n-i-1; ++j){
				int r = j, c = n-1-i;
				int old = matrix[i][j], tmp;
				while (r != i || c != j){
					tmp = matrix[r][c];
					matrix[r][c] = old;
					old = tmp;
					tmp = r;
					r = c;
					c = n-1-tmp;
				}
				matrix[r][c] = old;
			}
		}
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
	int n, it;
	while (cin >> n) {
		vector<vector<int > > vv;
		for (int i = 0; i < n; ++i){
			vector<int> v;
			for (int j = 0; j < n; ++j){
				cin >> it;
				v.push_back(it);
			}
			vv.push_back(v);
		}
		s.rotate(vv);
		print (vv);
	}
	return 0;
}