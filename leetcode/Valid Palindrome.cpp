#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		int l = s.length();
		for (int i = 0, j = l-1; i < j; ++i, --j) {
    		while (i < j && !isalnum(s[i]))
    			++i;
    		while (j > i && !isalnum(s[j]))
    			--j;
    		if (tolower(s[i]) != tolower(s[j]))
    			return false;
		}
		return true;
    }
};

int main() {
	Solution s;
	string str;
	while (getline(cin, str)){
		cout << s.isPalindrome(str) << endl;
	}
	return 0;	
}