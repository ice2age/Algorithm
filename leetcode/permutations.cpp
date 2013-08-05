#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool nextPermutation(vector<int> &num) {
		int n = num.size();
		int i = n-2;
		while (i >= 0 && num[i] > num[i+1])
			--i;
		if (i < 0) return false;
		int j = n-1;
		while (num[j] < num[i])
			--j;
		swap(num[i], num[j]);
		reverse(&num[i+1], &num[n-1]+1);
		return true;
	}
	
	vector<vector<int> > permute(vector<int> &num) {
    	vector<vector<int> > v;
    	sort(num.begin(), num.end());
    	v.push_back(num);
    	while (nextPermutation(num))
    		v.push_back(num);
    	return v;
    }
};

int main() {
	int n;
	Solution s;
	vector<int> v;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		v.push_back(i-1);
	
	vector<vector<int> > vv = s.permute(v);
	
	for (int i = 0; i < vv.size(); ++i) {
		copy(vv[i].begin(), vv[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	
	return 0;
}