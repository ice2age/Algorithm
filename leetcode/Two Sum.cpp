#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        sort(numbers.begin(), numbers.end());
        for (int i = 0, j = numbers.size()-1; i < j; ) {
        	int sum = numbers[i]+numbers[j];
        	if (sum == target) {
        		ret.push_back(i+1);
        		ret.push_back(j+1);
        		break;
        	}else if (sum < target)
        		i++;
        	else
        		j--;
        }
        return ret;
    }
};

int main() {
	vector<int> v;
	for (int i = 1; i <= 10; ++i){
		v.push_back(i);
	}
	Solution s;
	int t;
	while (cin >> t) {
		vector<int> ret = s.twoSum(v, t);
		cout << ret[0] << ", " << ret[1] << endl;
	}
	
	return 0;
}