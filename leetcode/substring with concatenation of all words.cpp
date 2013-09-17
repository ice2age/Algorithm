#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int n = L.size();
        if (n == 0) return ret;
        int wlen = L[0].length();
        int len = n * wlen;
        map<string, int> words;
        for (int i = 0; i < n; ++i)
        	++words[L[i]];
        int l = S.length();
        for (int i = 0; i <= l-len; ++i) {
        	map<string, int> mp(words);
        	int j = 0;
        	for (; j < n; ++j) {
				string word = S.substr(i+j*wlen, wlen);
				if (mp.count(word) == 0) break;
				if (--mp[word] < 0) break;
        	}
        	if (j == n) ret.push_back(i);
		}
		return ret;
    }
};

int main() {
	string a, b;
	vector<string> v;
	cin >> a;
	while (cin >> b) {
		v.push_back(b);
	}
	Solution s;
	vector<int> i = s.findSubstring(a, v);
	copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}