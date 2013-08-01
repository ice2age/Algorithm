#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	void search(const string& s, int i, int b, string ip, vector<string>& v) {
		if (s.size() - i > (4-b)*3) return;
		if (i == s.size() && b == 4) {
			ip.pop_back();
			v.push_back(ip);
			return;
		}
		int num = 0;
		for (int j = i; j < i+3; ++j) {
			num = 10 * num + (s[j]-'0');
			if (num <= 255)
				search(s, j+1, b+1, ip+s.substr(i, j-i+1)+'.', v);
			if (num == 0)
				break;
		}
	}
	
	vector<string> restoreIpAddresses(string s) {
		string ip;
		vector<string> v;
		search(s, 0, 0, ip, v);
		return v;
	}
};

int main() {
	string str = "25525511135";
	Solution s;
	vector<string> v = s.restoreIpAddresses(str);
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << endl;
	}
	return 0;
}