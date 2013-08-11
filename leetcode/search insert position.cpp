#include <iostream>
using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int l = 0, r = n-1, mid;
		while (l <= r){
			mid = (l+r) >> 1;
			if (A[mid] == target){
				return mid;
			} else if(A[mid] > target){
				r = mid-1;
			} else{
				l = mid+1;
			}
		}
		return r+1;
	}
};

int main() {
	int n;
	Solution s;
	while (cin >> n){
		int* a = new int[n];
		for (int i = 0; i < n; ++i){
			cin >> a[i];
		}
		int t;
		cin >> t;
		cout << s.searchInsert(a, n, t) << endl;
	}
	return 0;
}