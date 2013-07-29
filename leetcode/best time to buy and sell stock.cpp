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
        
        int max = 0;        
        int min = prices[0];
        for (int i = 1; i < n; ++i){
        	if (prices[i] < min)
        		min = prices[i];
        	else if (prices[i]-min > max)
        		max = prices[i]-min;
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