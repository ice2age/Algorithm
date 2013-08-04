#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
    	int* left = new int[n];
    	int max = left[0] = 0;
    	for (int i = 0; i < n; ++i){
    		left[i] = max;
    		if (A[i] > max)
    			max = A[i];
    	}
    	int sum = max = 0, min;
    	for (int i = n-1; i > 0; --i){
    		min = std::min(left[i], max);
    		sum += std::max(min-A[i], 0);
    		if (A[i] > max)
    			max = A[i];
    	}
    	return sum;
    }
};

int main() {
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int b[] = {2,1,2};
	Solution s;
	cout << s.trap(a, 12) << endl;
	cout << s.trap(b, 3) << endl;
	return 0;
}