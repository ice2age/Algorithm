#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int l = 0, r = height.size()-1;
		int mx = 0;
		while (l < r) {
			int v = (r - l) * min(height[l], height[r]);
			mx = max(mx, v);
			if (height[l] <= height[r])
				++l;
			else
				--r;
		}
		return mx;
	}
};

int main() {
	int h;
	vector<int> v;
	while (cin >> h){
		v.push_back(h);
	}
	Solution s;
	cout << s.maxArea(v) << endl;
	
	return 0;
}