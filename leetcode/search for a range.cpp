#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lower(int A[], int n, int t) {
    	int l = 0, h = n-1, m = 0;
    	while (l <= h) {
    		m = (l + h) >> 1;
    		if (l == h) break;
    		if (A[m] >= t) 	h = m;
    		else 			l = m + 1;
    	}
    	if (A[m] == t) return m;
    	return -1;
	}
	
	int upper(int A[], int n, int t) {
    	int l = 0, h = n-1, m = 0;
    	while (l <= h) {
    		m = (l + h + 1) >> 1;
    		if (l ==  h) break;
    		if (A[m] > t) 	h = m - 1;
    		else 			l = m;
    	}
    	if (A[m] == t) return m;
    	return -1;
	}
	
    vector<int> searchRange(int A[], int n, int target) {
		int l = this->lower(A, n, target);
		int u = this->upper(A, n, target);
		vector<int> v;
		v.push_back(l);
		v.push_back(u);
		return v;
    }
};

int main() {
	int a[] = {5, 7, 7, 8, 8, 10};
	Solution s;
	vector<int> v = s.searchRange(a, 6, 8);
	cout << v[0] << ", " << v[1] << endl;
	return 0;
}