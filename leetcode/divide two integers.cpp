#include <iostream>
using namespace std;

class Solution {
public:
<<<<<<< HEAD
<<<<<<< HEAD
	typedef long long loong;
	int divide(int dividend, int divisor) {
		loong a = abs(loong(dividend));
		loong b = abs(loong(divisor));
		int ans = 0;
		while (a >= b) {
			int i = 0;
			while (a >= (b << i+1))
				++i;
			ans += 1 << i;
			a -= b << i;
		}
		return ((dividend ^ divisor) >> 31) ? -ans : ans;
=======
=======
>>>>>>> 112a4021c1c989148bea3904f0c2271f6a7d5c48
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
<<<<<<< HEAD
>>>>>>> 112a4021c1c989148bea3904f0c2271f6a7d5c48
=======
>>>>>>> 112a4021c1c989148bea3904f0c2271f6a7d5c48
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