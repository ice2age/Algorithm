#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	void search(int i, vector<int> &num, vector<int>& s, vector<vector<int> >& v, bool* visited) {
		int n = num.size();
		if (i == n) {
			v.push_back(s);
			return;
		}
		
		for (int j = 0; j < n; ++j){
			if (!visited[j]){
				if (j > 0 && num[j] == num[j-1] && !visited[j-1])
					continue;
				
				visited[j] = true;
				s[i] = num[j];
				search(i+1, num, s, v, visited);
				visited[j] = false;
			}
		}
	}
	
	vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<int> s(num.size());
    	vector<vector<int> > v;
    	bool* visited = new bool[num.size()];
    	memset(visited, false, num.size());
    	sort(num.begin(), num.end());
    	search(0, num, s, v, visited);
    	return v;
    }
};

int main() {
	int n;
	Solution s;
	vector<int> v;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	
	vector<vector<int> > vv = s.permute(v);
	
	for (int i = 0; i < vv.size(); ++i) {
		copy(vv[i].begin(), vv[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	
	return 0;
}