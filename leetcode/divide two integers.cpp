#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		int ret = 0;
		int sign = 1;
		if (dividend > 0 && divisor < 0) sign = -1;
		if (dividend < 0 && divisor > 0) sign = -1;
		dividend = (dividend >= 0 ? dividend : -dividend);
		divisor = (divisor >= 0 ? divisor : -divisor);
		while (dividend >= divisor) {
			dividend -= divisor;
			ret++;
		}
		return ret * sign;
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