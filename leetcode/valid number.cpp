#include <string>
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isNumber(const char *s) {
		bool existn = false;
		bool existe = false;
		bool existdot = false;
		while (*s && isspace(*s))
			++s;
		int l = strlen(s);
		while (l > 0 && isspace(s[l-1]))
			--l;
		if (l == 0) return false;
		for (int i = 0; i < l; ++i) {
			if (isspace(s[i])) {
				return false;
			} else if (isalpha(s[i])) {
				if (s[i] != 'e' && s[i] != 'E') return false;
				if (existe || !existn) return false;
				if (i == 0 || i == l-1) return false;
				existe = true;
			} else if (s[i] == '.') {
				if (existdot || existe) return false;
				bool d = false;
				if (i > 0 && isdigit(s[i-1])) d = true;
				if (!d && i < l-1 && isdigit(s[i+1])) d = true;
				if (!d) return false;
				existdot = true;
			} else if (s[i] == '+' || s[i] == '-') {
				if (i == l-1) return false;
				if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
			} else {
				existn = true;
			}
		}
		return true;
	}
};

int main(){
	string str;
	Solution s;
	while (getline(cin, str)){
		cout << s.isNumber(str.c_str()) << endl;
	}
	return false;
}