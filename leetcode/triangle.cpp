#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        for (int r = row-2; r >= 0; --r){
        	for (int c = 0; c < triangle[r].size(); ++c)
        		triangle[r][c] += min(triangle[r+1][c], triangle[r+1][c+1]);
        }
        return triangle[0][0];
    }
};

int main() {
	freopen("input.txt", "r", stdin);
	int in;
	Solution s;
	vector<vector<int> > tri;
	for (int i = 0; i < 4; ++i){
		vector<int> v;
		for (int j = 0; j <= i; ++j){
			cin >> in;
			cout << in << " ";
			v.push_back(in);
		}
		cout << endl;
		tri.push_back(v);
	}
	cout << s.minimumTotal(tri) << endl;
	return 0;
}