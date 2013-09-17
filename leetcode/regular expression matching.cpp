#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') 
			return *s == '\0';
		char next = *(p+1);
		if (next != '*') {
			assert(*p != '*');
			if (*s == '\0') return false;
			if (*p != '.' && *s != *p) return false;
			return isMatch(++s, ++p);
		} else {
			while (*s == *p || (*s && *p == '.')){
				if (isMatch(s, p+2)) return true;
				++s;
			}
		}
		return isMatch(s, p+2);
	}
};

int main() {
	Solution sln;
	assert (sln.isMatch("", ".") == false);
	assert (sln.isMatch("", ".*") == true);
	assert (sln.isMatch("a", "ab*") == true);
	assert (sln.isMatch("ab", ".*c") == false);
	assert (sln.isMatch("aaa", "ab*a*c*a") == true);
	assert (sln.isMatch("a", "ab*a") == false);
	assert (sln.isMatch("aaa", "aaaa") == false);
	assert (sln.isMatch("a", "a*a") == true);
	assert (sln.isMatch("bbbba", ".*a*a") == true);
	assert (sln.isMatch("a", "ab*") == true);
	assert (sln.isMatch("aa","a") == false);
	assert (sln.isMatch("aa","aa") == true);
	assert (sln.isMatch("aaa","aa") == false);
	assert (sln.isMatch("aa", "a*") == true);
	assert (sln.isMatch("aa", ".*") == true);
	assert (sln.isMatch("ab", ".*") == true);
	assert (sln.isMatch("aab", "c*a*b") == true);
	assert (sln.isMatch("ccaab", "c*a*b") == true);
	assert (sln.isMatch("ccc", "c*c") == true);
	assert (sln.isMatch("aaa", "ab*a") == false);
	
	cout << "test all passed!" << endl;
	char s[100], p[100];
	while (cin >> s >> p)
		cout << sln.isMatch(s, p) << endl;
	return 0;
}