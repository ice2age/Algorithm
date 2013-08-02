#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
	
	void search(int i, vector<int>&s, vector<int>& sub, vector<vector<int> >& ret) {
    	if (i == s.size()) {
    		ret.push_back(sub);
    		return;
    	}
    	search(i+1, s, sub, ret); 	// not choose s[i]
    	sub.push_back(s[i]);		// choose s[i]
    	search(i+1, s, sub, ret);
    	sub.pop_back();
	}
	
    vector<vector<int> > subsets_recursive(vector<int> &S) {
    	vector<int> sub;
    	vector<vector<int> > ret;
    	sort(S.begin(), S.end());
    	search(0, S, sub, ret);
    	return ret;
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
    	sort(S.begin(), S.end());
    	vector<vector<int> > ret(1);
    	for (int i = 0; i < S.size(); ++i) {
    		int n = ret.size();
    		while (n--) {
    			ret.push_back(ret[n]);
    			ret.back().push_back(S[i]);
    		}
    	}	
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
	vector<int> v;
	for (int i = 0; i < 3; ++i)
		v.push_back(i+1);
	
	Solution s;
	printsets(s.subsets(v));
	return 0;
}