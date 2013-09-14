#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
	void search(int i, const string& digits, string mapping[], string& v, vector<string>& ret) {
		if (i == digits.length()) {
			ret.push_back(v);
			return;
		}
		string mp = mapping[digits[i]-'0'];
		for (int j = 0; j < mp.length(); ++j){
			v.push_back(mp[j]);
			search(i+1, digits, mapping, v, ret);
			v.pop_back();
		}
	}
	
	vector<string> letterCombinations(string digits) {
		string map[] = {"", "", "abc", "def", "ghi", "jkl",  
								"mno", "pqrs", "tuv", "wxyz"}; 
		string v;
		vector<string> ret;
		search(0, digits, map, v, ret);
		return ret;	
	}
};

int main() {
	string d;
	Solution s;
	while (cin >> d){
		vector<string> ret = s.letterCombinations(d);
		copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}
	return 0;
}