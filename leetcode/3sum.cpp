#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
	void search(int i, bool *visited, const vector<int> &num, vector<int>& s, vector<vector<int> >& v, int t, int step) {
		int n = num.size();
		if (t == 0 && step == 0) {
			v.push_back(s);
			return;
		}
		if (i >= n) return;
		if (step <= 0) return;
		if (t < num[i]) return;
		if (n - i < step) return;
		
		for (; i < n; ++i){
			if (!visited[i]){
				if (i > 0 && num[i] == num[i-1] && !visited[i-1])
					continue;
				visited[i] = true;
				s.push_back(num[i]);
				search(i+1, visited, num, s, v, t-num[i], step-1);
				visited[i] = false;
				s.pop_back();
			}
		}
	}
	
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<int> s;
		vector<vector<int> > v;
		sort(num.begin(), num.end());
		bool* visited = new bool[num.size()];
		memset(visited, false, num.size()*sizeof(bool));
		search(0, visited, num, s, v, 0, 3);
		return v;
	}
};

void print(vector<vector<int> >& v) {
	for (int i = 0; i < v.size(); ++i) {
		copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

int main() {
	int n, in;
	Solution s;
	vector<int> v;
	while (cin >> n) {
		for (int i = 0; i < n; ++i){
			cin >> in;
			v.push_back(in);
		}
		print(s.threeSum(v));
	}
	return 0;
}