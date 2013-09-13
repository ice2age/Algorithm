#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> ans;
		for (int i = 1, sum = words[0].length(), cnt = 1; i < words.size(); ++i) {
			if (sum + cnt + words[i].length() > L) {
				int empty = L - sum;
				string row;
				for (int j = i-cnt; j < i; ++j, --cnt) {
					row.insert(row.length(), words[j]);
					int n = (empty + cnt - 1) / cnt;
					row.insert(row.end(), n, ' ');
					empty -= n;
				}
				ans.push_back(row);
			}
		}
	
		return ans;
	}
};

void print(vector<string>& v) {
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}

int main() {
	int L;
	cin >> L;
	vector<string> words;
	string word;
	while (cin >> word){
		words.push_back(word);
	}
	Solution s;
	print(s.fullJustify(words, L));
	
	return 0;
}