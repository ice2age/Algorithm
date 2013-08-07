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
		if (n - i < step) return;
		int sum = 0;
		for (int j = 0; j < step; ++j)
			sum += num[i+j];
		if (sum > t) return;
		sum = 0;
		for (int j = 0; j < step; ++j)
			sum += num[n-j-1];
		if (sum  < t) return;
		
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
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<int> s;
		vector<vector<int> > v;
		int n = num.size();
		sort(num.begin(), num.end());
		if (n < 4 || num[0]+num[1]+num[2]+num[3] > target || num[n-1]+num[n-2]+num[n-3]+num[n-4] < target)
			return v;
		bool* visited = new bool[n];
		memset(visited, false, n*sizeof(bool));
		search(0, visited, num, s, v, target, 4);
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
		while (cin >> in)
			print(s.fourSum(v, in));
	}
	return 0;
}