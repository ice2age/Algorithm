#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		for (int i = 0; i < n; ++i) {
    		int j = i+1;
    		while (j < n && A[i] == A[j])
    			++j;
    		if (j - i > 2){
    			for (int k = j; k < n; ++k)
					A[k+i-j+2] = A[k];
				n -= (j-i-2);
    		}
    	}
    	return n;
    }
};

int main() {
	int a[] = {1, 1, 2, 3, 3, 3, 4, 5, 5};

	std::copy(a, a+9, ostream_iterator<int>(cout, ", "));
	cout << endl;
	Solution s;
	int n = s.removeDuplicates(a, 9);
	std::copy(a, a+n, ostream_iterator<int>(cout, ", "));
	return 0;
}