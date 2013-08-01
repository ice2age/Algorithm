#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool paircmp(const pair<int,int>& lhs, const pair<int,int>& rhs) {
    	return lhs.first < rhs.first;
	}
	
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        vector<pair<int, int> > tv;
        for (int i = 0; i < numbers.size(); ++i) {
        	tv.push_back(make_pair(numbers[i], i+1));
        }
        
        sort (tv.begin(), tv.end(), paircmp);
        
        for (int i = 0, j = numbers.size()-1; i < j; ) {
        	int sum = tv[i].first+tv[j].first;
        	if (sum == target) {
        		ret.push_back(min(tv[i].second,tv[j].second));
        		ret.push_back(max(tv[i].second,tv[j].second));
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
		if (!ret.empty()) cout << ret[0] << ", " << ret[1] << endl;
	}
	
	return 0;
}