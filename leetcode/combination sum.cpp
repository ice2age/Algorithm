#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
	void search(int i, const vector<int> &num, vector<int>& s, vector<vector<int> >& v, int t) {
		int n = num.size();
		if (t == 0) {
			v.push_back(s);
			return;
		}
		if (t < 0 ) return;
		if (i >= n) return;
		if (t < num[i]) return;
		
		for (; i < n; ++i){
			s.push_back(num[i]);
			search(i, num, s, v, t-num[i]);
			s.pop_back();
		}
	}
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> s;
		vector<vector<int> > v;
		int n = candidates.size();
		sort(candidates.begin(), candidates.end());
		search(0, candidates, s, v, target);
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
			print(s.combinationSum(v, in));
	}
	return 0;
}