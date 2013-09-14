#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int n = num.size();
		int ans = num[0]+num[1]+num[2];
		for (int i = 0; i <= n-3; ++i){
			int j = i+1, k = n-1;
			while (j < k) {
				int sum = num[i]+num[j]+num[k];
				if (sum == target) return target;
				if (abs(target-sum) < abs(target-ans))
					ans = sum;
				if (sum < target) ++j;
				else --k;
			}
		}
		return ans;
	}
};

int main() {
	int tar, n;
	vector<int> v;
	cin >> tar;
	while (cin >> n){
		v.push_back(n);
	}
	
	Solution s;
	cout << s.threeSumClosest(v, tar) << endl;
	return 0;
}