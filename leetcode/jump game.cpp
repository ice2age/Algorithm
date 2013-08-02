#include <iostream>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (n <= 1) return true;
		bool* c = new bool[n];
		c[0] = true;
		for (int i = 1; i < n; ++i){
			c[i] = false;
			for (int j = i-1; j >= 0; --j){
				if (c[j] && (i-j<=A[j])){
					c[i] = true;
					break;
				}
			}
		}
		return c[n-1];
	}
};

int main() {
	int n;
	int a[] = {2, 3, 1, 1, 4};
	int b[] = {3, 2, 1, 0, 4};
	Solution s;
	cout << s.canJump(a, 5) << endl;
	cout << s.canJump(b, 5) << endl;
	
	return 0;
}