#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
	void search(int i, int n, bool* visited, int j, int k, vector<int>& s, vector<vector<int> >& v) {
		if (j == k){
			v.push_back(s);
			return;
		}
		
		for (; i < n; ++i){
			if (!visited[i]){
				s.push_back(i+1);
				visited[i] = true;
				search(i+1, n, visited, j+1, k, s, v);
				s.pop_back();
				visited[i] = false;
			}
		}
	}
	vector<vector<int> > combine(int n, int k) {
		vector<int> s;
		vector<vector<int> > v;
		bool* visited = new bool[n];
		memset(visited, false, n*sizeof(bool));
		search(0, n, visited, 0, k, s, v);
		return v;
	}
};

void print (vector<vector<int> >& v) {
	int n = v.size();
	for (int i = 0; i < n; ++i) {
		copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

int main() {
	int n, k;
	Solution s;
	while (cin >> n >> k) {
		vector<vector<int> > v = s.combine(n, k);
		print (v);
	}
	return 0;
}