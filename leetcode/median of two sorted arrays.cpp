#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays1(int A[], int m, int B[], int n) {
		int k = (m + n - 1) >> 1;
		int last = 0, i, j, c;
		for (i = 0, j = 0, c = 0; i < m && j < n; ++c){
			if (c == k+1) return (last+min(A[i], B[j])) / 2.0;
			if (A[i] <= B[j]) last = A[i++];
			else  last = B[j++];
			if (c == k && (m+n)%2 == 1) return last;
		}
		if (i < m) {
			if ((m+n)%2 == 1) return A[k-c+i];
			else if(k < c) return (last+A[k-c+i+1]) / 2.0;
			else return (A[k-c+i]+A[k-c+i+1]) / 2.0;
		} else {
			if ((m+n)%2 == 1) return B[k-c+j];
			else if (k < c) return (last+B[k-c+j+1]) / 2.0;
			else return (B[k-c+j]+B[k-c+j+1]) / 2.0;
		}
		return 0.0;
	}
	
	int findKth(int A[], int m, int B[], int n, int k) {
		if (m > n) return findKth(B, n, A, m, k);
		if (m == 0) return B[k-1];
		if (k == 1) return min(A[0], B[0]);
		int l = min(m, k/2), r = k-l;
		if (A[l-1] <= B[r-1])
			return findKth(A+l, m-l, B, n, k-l);
		return findKth(A, m, B+r, n-r, k-r);
	}
	
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int s = m+n;
		if (s % 2 == 1)
			return findKth(A, m, B, n, (m+n)/2+1);
		return (findKth(A, m, B, n, s/2) +
				findKth(A, m, B, n, s/2+1)) / 2.0;
	}
};

int main() {
	int m, n;
	int A[10], B[10];
	cin >> m >> n;
	for (int i = 0; i < m; ++i) cin >> A[i];
	for (int i = 0; i < n; ++i) cin >> B[i];
	Solution s;
	cout << s.findMedianSortedArrays(A, m, B, n) << endl;
	return 0;
}