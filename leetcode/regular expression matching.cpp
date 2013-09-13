#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch1(const char *s, const char *p) {
		const char* ss = NULL;
		const char* pp = NULL;
		while (*s != '\0') {
			if (*p == *s || *p == '.') { s++, p++; continue; }
			if (*p == '*') { ss = s, pp = p++; continue; }
			if (pp && (*(pp-1) == *ss || *(pp-1) == '.')) { s = ++ss, p = pp+1; continue; }
			if (*(p+1)=='*') { p+=2; continue; }
			return false;
		}
		while (*p) {
			if (*p == '*') pp = p++;
			else if (*(p+1) == '*') p+=2;
			else if (pp && *p == *(s-1)) p++;
			else return false;
		}
		return !*p;
	}

	bool isMatch(const char *s, const char *p) {
		if (!*s && !*p) return true;
		if (*s && !*p) return false;
		if (*p == '.') return isMatch(s+1, p+1);
		return isMatch()
	}
};

int main() {
	Solution sln;
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
	while (cin >> s >> p) {
		cout << sln.isMatch(s, p) << endl;
	}
	return 0;
}