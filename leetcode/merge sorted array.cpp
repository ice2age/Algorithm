#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1, k = m+n-1;
        for (; i >= 0 && j >= 0;){
        	if (A[i]>B[j]) 	A[k--] = A[i--];
        	else 			A[k--] = B[j--];
        }
        for (; j >= 0; --j)
        	A[k--] = B[j];
    }
};

int main() {
	int A[10] = {1, 3, 5, 7, 9};
	int B[5] = {2, 4, 6, 8, 10};
	
	Solution s;
	s.merge(A, 5, B, 5);
	std::copy(A, A+10, ostream_iterator<int>(std::cout,", "));
	
	return 0;
}