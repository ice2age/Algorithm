#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	reverse(digits.begin(), digits.end());
    	int c = 1;
    	for (int i = 0; i < digits.size(); ++i){
    		digits[i] += c;
    		c = digits[i] / 10;
    		digits[i] %= 10;
    	}
    	if (c) digits.push_back(c);
    	reverse(digits.begin(), digits.end());
    	return digits;
    }
};

int main() {
	
	vector<int> v;
	v.push_back(9);
	v.push_back(9);
	Solution s;
	v = s.plusOne(v);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	return 0;
}