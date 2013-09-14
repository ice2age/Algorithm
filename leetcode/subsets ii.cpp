#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
	void search(int i, vector<bool>& choose, vector<int>&s, vector<int>& sub, vector<vector<int> >& ret) {
    	if (i == s.size()) {
    		ret.push_back(sub);
    		return;
    	}
    	
    	if (i == 0 || 
    		s[i] != s[i-1] ||
    		choose[i-1] ) {
    		sub.push_back(s[i]);		// choose s[i]
    		choose[i] = true;
    		search(i+1, choose, s, sub, ret);
	    	sub.pop_back();
	    	choose[i] = false;
    	}
    	search(i+1, choose, s, sub, ret); 	// not choose s[i]
	}
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<int> sub;
		vector<bool> choose(S.size(), false);
		vector<vector<int> > ret;
		search(0, choose, S, sub, ret);
		return ret;
	}
};

void printsets(vector<vector<int> >& v) {
	for (int i = 0; i < v.size(); ++i){
		if (v[i].empty()) cout << "null" << endl;
		else {
			copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}
}

int main() {
	int i;
	vector<int> v;
	while (cin >> i)
		v.push_back(i);
	
	Solution s;
	printsets(s.subsetsWithDup(v));
	return 0;
}