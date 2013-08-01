#include <iostream>

using namespace std;

class Solution {
public:
	int doit(int x, int r) {
    	if (x) return doit(x/10, r*10+x%10);
    	return r;
	}
	
    int reverse_recursive(int x) {
    	if (x < 0)
    		return -doit(-x, 0);
    	else
    		return doit(x, 0);
    }
    
    int reverse(int x) {
    	int s = 1;
    	if (x < 0){
    		s = -1;
    		x = -x;
    	}
    	int r = 0;
    	while (x){
    		r = r * 10 + x % 10;
    		x /= 10;
    	}
    	return s*r;
    }
};

int main() {
	int x;
	Solution s;
	while (cin >> x){
		cout << s.reverse(x) << endl;
	}
	return 0;
}