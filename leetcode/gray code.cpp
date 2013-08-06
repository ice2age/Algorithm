#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	
	void search(int cur, int n, set<int>& already, vector<int>& v) {
		v.push_back(cur);
		already.insert(cur);
		
		for (int i = 0; i < n; ++i) {
			int next = (cur ^ (1 << i));
			if (already.count(next) == 0)
				search(next, n, already, v);
		}
			
	}
	
	vector<int> grayCode(int n) {
		set<int> already;
		vector<int> v;
		search(0, n, already, v);
		return v;
	}
};

int main() {
	int n;
	Solution s;
	while (cin >> n){
		vector<int> v = s.grayCode(n);
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}