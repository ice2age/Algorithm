#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
	string say(const string& str) {
		int n = str.length();
		ostringstream out;
		for (int i = 0, j = 0; i < n; i = j){
			j = i+1;
			while (j < n && str[j]==str[i])
				++j;
			out << j-i << str[i];
		}
		return out.str();
	}
	
	string countAndSay(int n) {
		string str = "1";
		while (--n > 0)
			str = say(str);
		return str;	
	}
};

int main() {
	Solution s;
	int n;
	while (cin >> n)
		cout << s.countAndSay(n) << endl;
	return 0;
}