#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		stack<int> s, width;
        height.push_back(0);
		int max = 0, w, min, n = height.size();
		for (int i = 0; i < n; ++i){
			if (s.empty() || height[i] >= s.top()) {
				s.push(height[i]);
				width.push(1);
			}
			else {
				w = 0;
				min = s.top();
				while (!s.empty() && s.top() > height[i]){
					w += width.top();
					min = std::min(min, s.top());
                    max = std::max(max, w * min);
					s.pop();
					width.pop();
				}
				w++;
				s.push(height[i]);
				width.push(w);
			}
		}
		return max;
	}
};

int main() {
	int n, in;
	Solution s;
	
	while (cin >> n)
	{
		vector<int> v;
		while (n--) {
			cin >> in;
			v.push_back(in);
		}
		cout << s.largestRectangleArea(v) << endl;
	}
	
	return 0;
}