#include <iostream>
using namespace std;

class Solution {
public:
	double power(double x, int n) {
    	if (n == 0)
    		return 1;
    	if (n % 2 == 0)
    		return power(x*x, n/2);
    	else
    		return power(x*x, n/2) * x;
	}
	
    double pow(double x, int n) {
    	x = power(x, (n > 0 ? n : -n));
    	if (n < 0) return 1/x;
    	return x;
    }
};

int main() {
	int n;
	double x;
	Solution s;
	while (cin >> x >> n)
		cout << s.pow(x, n) << endl;

	return 0;
}