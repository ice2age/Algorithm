#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 1;
		while (--n > 0){
			a = a + b;
			b = a - b;
		}
		return a;
	}
};

int main() {
	Solution s;
	int n;
	while (cin >> n){
		cout << s.climbStairs(n) << endl;
	}
	return 0;
}