#include <iostream>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		if (n <= 1) return 0;
		int b = 0, e = 0, c = 0;
		while (e < n) {
			int max = e;
			c++;
			for (int i = b; i <= e; ++i) {
				if (A[i] + i > max)
					max = A[i] + i;
				if (max >= n-1)
					return c;
			}
			b = e+1;
			e = max;
		}
		return c;
	}
};

int main() {
	int n;
	int a[] = {2, 3, 1, 1, 4};
	int b[] = {3, 2, 1, 0, 4};
	Solution s;
	cout << s.jump(a, 5) << endl;
	
	return 0;
}