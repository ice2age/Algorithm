#include <iostream>
#include <iterator>
using namespace std;


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	for (int i = 0; i < n;) {
    		if (A[i] == elem) {
    			A[i] = A[n-1];
    			--n;
    		}
    		else ++i;
    	}
    	return n;
    }
};

int main() {
	int a[] = {1, 2, 4, 2, 3, 2};
	Solution s;
	int n = s.removeElement(a, 6, 2);
	copy(a, a+n, ostream_iterator<int>(cout, " "));
	return 0;
}