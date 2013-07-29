#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		if (n == 0){
			return 0;
		}
		int* p1 = new int[n];
		p1[0] = 0;
		int min = prices[0];
		for (int i = 1; i < n; ++i){
			min = std::min(min, prices[i]);
			p1[i] = max(p1[i-1], prices[i]-min);
		}


		int* p2 = new int[n];
		p2[n-1]=0;
		int max = prices[n-1];
		for (int i = n-2; i >= 0; --i){
			max = std::max(max, prices[i]);
			p2[i] = std::max(p2[i+1],max-prices[i]);
		}

		max = 0;
		for (int i = 0; i < n; ++i){
			if (p1[i]+p2[i] > max){
				max = p1[i]+p2[i];
			}
		}
		return max;
	}
};

int main() {
	Solution s;
	int p;
	vector<int> v;
	while (cin >> p){
		v.push_back(p);
	}
	cout << s.maxProfit(v);

	return 0;	
}