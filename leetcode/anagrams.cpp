#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> result(0);
		int nSize = strs.size();
		if (nSize == 0) return result;
		vector<string> tmp(strs);
		for(int i = 0; i < nSize; ++i)
			sort(tmp[i].begin(), tmp[i].end());
		
		map<string, vector<int> > ana;
		for (int i = 0; i < nSize; ++i)
			ana[tmp[i]].push_back(i);
		
		map<string, vector<int> >::iterator itr = ana.begin();
		for( ; itr != ana.end(); ++itr) {
			if (itr->second.size() > 1) {
				vector<int>& v = itr->second;
				for (int i = 0; i < v.size(); ++i)
					result.push_back(strs[v[i]]);
			}
		}
		return result;
	}
};

int main() {
	string word;
	vector<string> v;
	while (cin >> word){
		v.push_back(word);
	}
	
	Solution s;
	v = s.anagrams(v);
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
	
	return 0;
}