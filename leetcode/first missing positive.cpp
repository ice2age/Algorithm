#include <iostream>
#include <iterator>
using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		int c = 0, sum = 0;
		for (int i = 0; i < n; ++i){
			if (A[i] > 0){
				c++;
				sum += A[i];
			}
		}
		return (c+1)*(c+2)/2 - sum;
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