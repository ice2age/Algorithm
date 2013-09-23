#include <iostream>
using namespace std;

class Solution {
public:
<<<<<<< HEAD
	static bool odd(int x) {
		return x&1 == 1;
	}
	
	static bool even(int x) {
		return x&1 == 0;
	}
	
	int divide(int dividend, int divisor) {
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