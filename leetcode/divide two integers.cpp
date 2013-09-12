#include <iostream>
using namespace std;

class Solution {
public:
	static bool odd(int x) {
		return x&1 == 1;
	}
	
	static bool even(int x) {
		return x&1 == 0;
	}
	
	int divide(int dividend, int divisor) {
		int sign = 1;
		if (dividend > 0 && divisor < 0) sign = -1;
		if (dividend < 0 && divisor > 0) sign = -1;
		dividend = (dividend >= 0 ? dividend : -dividend);
		divisor = (divisor >= 0 ? divisor : -divisor);
		while (divisor > 1 && even(divisor)) {
			dividend >>= 1;
			divisor >>= 1;
		}
		if (divisor == 1) return sign*dividend;
		int ret = 0;
		while (dividend >= divisor) {
			ret++;
			dividend -= divisor;
		}
		return sign * dividend;
	}
};

int main() {
	int a, b;
	Solution s;
	while (cin >> a >> b){
		cout << s.divide(a, b) << endl; 
	}
	return 0;
}