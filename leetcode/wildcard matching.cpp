#include <iostream>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		const char* star=NULL;
		const char* ss=s; 
		while (*s){
			if ((*p=='?')||(*p==*s)){s++;p++;continue;}
			if (*p=='*'){star=p++; ss=s;continue;}
			if (star){ p = star+1; s=++ss;continue;}
			return false;
		}
		while (*p=='*'){p++;}
		return !*p;
	}
	
	bool isMatch-recersive(const char *s, const char *p) {
		if (*s == 0 && *p == 0) return true;
		while (*s && *s == *p) s++, p++;
		//if (*s == 0 && *p == 0) return true;
		if (*s && !*p) return false;
		if (!*s){
			while (*p=='*') ++p;
			return !*p;
		}
		if (*p == '?') return isMatch(++s, ++p);
		if (*p >= 'a' && *p <= 'z') return false;
		while (*p == '*' && *(p+1) == '*')
			++p;
		return	(*s && isMatch(s+1, p)) || 	//match > 1
			(*s && *p && isMatch(s+1, p+1)) ||	//match 1
			(*p && isMatch(s, p+1));	//match 0
	}
};

int main() {
	Solution s;
	char a[100], b[100];
	a[0] = 0;
	b[0] = '*', b[1] = 0;
	cout << s.isMatch(a, b) << endl;
	while (cin >> a >> b){
		cout << s.isMatch(a, b) << endl;
	}
	return 0;
}