#include <iostream>
using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		int l = 0, h = n-1, m;
		while (l <= h) {
			m = (l + h) >> 1;
			if (A[m] == target)
				return m;
			if (A[m] >= A[l]) {
				if (target > A[m] || target < A[l])
					l = m+1;
				else
					h = m-1;	
			} else {
				if (target < A[m] || target > A[h])
					h = m-1;
				else
					l = m+1;
			}
		}
		return -1;
	}
};

int main() {
	Solution s;
	//int a[] = {6, 7, 0, 1, 2, 4, 5};
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	int target;
	while (cin >> target)
		cout << s.search(a, 7, target) << endl;
	
	return 0;
}