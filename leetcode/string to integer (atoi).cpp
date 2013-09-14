#include <cctype>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		int sign = 1;
		while (isspace(*str))
			++str;
		if (*str == '-')
			sign = -1, ++str;
		else if (*str == '+')
			++str;
		long long ans = 0;
		while (*str && isdigit(*str)) {
			ans = 10*ans + *str++ - '0';
			if (sign > 0 && ans > INT_MAX) return INT_MAX;
			if (sign < 0 && ans > (long long)INT_MAX+1) return INT_MIN;
		}
		return sign*ans;
	}
};

int main() {
	char str[100];
	Solution s;
	while (cin >> str){
		cout << s.atoi(str) << endl;
	}
	return 0;
}