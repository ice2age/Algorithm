#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
	int partition(int* a, int l, int r) {
		int i = l-1, x = a[r];
		for (int j = l; j < r; ++j) {
			if (a[j] <= x)
				swap(a[++i], a[j]);
		}
		swap(a[++i], a[r]);
		return i;	
	}
	
	void qsort(int* a, int l, int r) {
    	if (l < r) {
    		int p = partition(a, l, r);
    		qsort(a, l, p-1);
    		qsort(a, p+1, r);	
    	}
	}
	
    void sortColors1(int A[], int n) {
        int i = 0, j = 0;
        for (int k = 0; k < n; ++k){
        	if (A[k] == 0)
        		++i;
        	else if (A[k] == 1)
        		++j;
        }
        int k = 0;
        for (k = 0; k < i; ++k)
        	A[k] = 0;
        for (; k < i+j; ++k)
        	A[k] = 1;
        for (; k < n; ++k)
        	A[k] = 2;
    }
    
    void sortColors(int A[], int n) {
    	int i = -1, k = n;
    	for (int j = 0; j < k;){
    		if (A[j] == 0)
    			swap(A[++i], A[j++]);
    		else if (A[j] == 2){
    			swap(A[--k], A[j]);
    		}
    		else j++;
    	}
    }
};

int main() {
	int n, i;
	Solution s;
	while (cin >> n){
		int* a = new int[n];
		for (int j = 0; j < n; ++j){
			cin >> i;
			a[j] = i;
		}
		s.sortColors(a, n);
		//s.qsort(a, 0, n-1);
		copy(a, a+n, ostream_iterator<int>(cout, " "));
	}
	return 0;
}