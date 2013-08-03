#include <iostream>
using namespace std;

class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n == 0) return 0;
		int max = A[0];
		for (int i = 1; i < n; ++i){
			if (A[i-1] > 0)
				A[i] += A[i-1];
			if (A[i] > max)
				max = A[i];
		}
		return max;
	}
};

int main() {
	Solution s;
	int a[]={-2,1,-3,4,-1,2,1,-5,4};
	cout << s.maxSubArray(a, 9) << endl;
	return 0;
}