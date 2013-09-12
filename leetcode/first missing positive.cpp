#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i = 0; i < n; ++i){
			while (A[i] != i+1){
				if (A[i] <= 0 || A[i] > n) break;
				int t = A[i];
				A[i] = A[t-1];
				A[t-1] = t;
			}
		}
		int i = 0;
		for (; i < n && A[i] == i+1; ++i)
			;
		return i+1;
	}
};

int main() {
	int n, in;
	Solution s;
	while (cin >> n){
		int * a = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cout << s.firstMissingPositive(a, n) << endl;
	}
	return 0;
}