#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > tri;
        for (int i = 0; i < numRows; ++i){
        	vector<int> v;
        	for (int j = 0; j <= i; ++j){
        		if (j == 0 || j == i)
        			v.push_back(1);
        		else
        			v.push_back(tri[i-1][j-1]+tri[i-1][j]);
        	}
        	tri.push_back(v);
        }
        return tri;
    }
};

void print (vector<vector<int> > v){
	for (int i = 0; i < v.size(); ++i){
		for (int j = 0; j < v[i].size(); ++j){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	Solution s;
	int i;
	while (cin >> i){
		print(s.generate(i));
	}
	return 0;
}