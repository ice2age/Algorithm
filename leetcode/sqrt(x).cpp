#include <iostream>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
		int l = 0, r = x/2+1, mid;
		while (l <= r){
			mid = (l+r) / 2;
			long long sqr = mid*mid;
			if (sqr == x){
				return mid;
			} else if (sqr > x){
				r = mid-1;
			} else {
				l = mid+1;
			}
		}
		return r;
	}
};

int main() {
	int x;
	Solution s;
	while (cin >> x){
		cout << s.sqrt(x) << endl;
	}
	return 0;
}