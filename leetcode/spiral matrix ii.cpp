#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
	enum {Down, Left, Up, Right};
	
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > vv(n);
		for (int i = 0; i < n; ++i){
			vector<int> v(n);
			vv[i] = v;
		}
		if (n == 0) return vv;
		for (int i = 0; i < n; ++i)
			vv[0][i] = i+1;
		if (n == 1) return vv;
		
		int steps[2] = {n-1, n-1};
		int i = 0, j = n-1, id = 0, num = n+1, dir = Down;
		while (num <= n*n) {
			int s = steps[id];
			while (s--) {
				switch(dir) {
					case Left:	--j; break;
					case Right:	++j; break;
					case Up:	--i; break;
					case Down:	++i; break;
				}
				vv[i][j] = num++;
			}
			steps[id]--;
			id = 1 - id;
			dir = (dir+1) % 4;
		}
		return vv;
	}
};

void print(vector<vector<int> >& v) {
	for (int i = 0; i < v.size(); ++i){
		copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n;
	Solution s;
	while (cin >> n){
		print(s.generateMatrix(n));
	}
	return 0;	
}