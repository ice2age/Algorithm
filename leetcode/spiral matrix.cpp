#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
	enum {Down, Left, Up, Right};
	
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int m = matrix.size();
		if (m == 0) return vector<int>();
		else if (m == 1) return matrix[0];
		int n = matrix[0].size();
		vector<int> v(matrix[0].begin(), matrix[0].end());
		int step[2] = {m-1, n-1};
		int i = 0, j = n-1, id = 0, dir = Down;
		int count = (m - 1) * n;
		while (true) {
			int s = step[id];
			while (s--) {
				switch(dir) {
					case Left:	--j; break;
					case Right:	++j; break;
					case Up:	--i; break;
					case Down:	++i; break;
        		}
        		v.push_back(matrix[i][j]);
        		count--;
			}
			if (count == 0) break;
			step[id]--;
			id = 1 - id;
			dir = (dir+1) % 4;
		}
		return v;
	}
};

void print(vector<int>& v) {
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;
}

int main() {
	int m, n, it;
	Solution s;
	while (cin >> m >> n){
		vector<vector<int> > vv;
		for (int i = 0; i < m; ++i){
			vector<int> v;
			for (int i = 0; i < n; ++i){
				cin >> it;
				v.push_back(it);
			}
			vv.push_back(v);
		}
		print(s.spiralOrder(vv));
	}
	return 0;	
}