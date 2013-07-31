#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
	string addBinary(string a, string b) {
		int n = a.length(), m = b.length();
		int l = max(n, m);
		
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = n; i < l; ++i) a.push_back('0');
		for (int i = m; i < l; ++i) b.push_back('0');
		string ret(l, 0);
		
		int carry = 0;
		for (int i = 0; i < l; ++i){
			ret[i] = (a[i]-'0') + (b[i] - '0') + carry;
			carry = ret[i] / 2;
			ret[i] %= 2;
		}
		if (carry)
			ret.push_back(carry);
		reverse(ret.begin(), ret.end());	
		for (int i = 0; i < ret.size(); ++i)
			ret[i] += '0';
		
		return ret;
	}
};

int main() {
	Solution s;
	string l, r;
	while (cin >> l >> r){
		cout << s.addBinary(l, r) << endl;
	}
	return 0;
}