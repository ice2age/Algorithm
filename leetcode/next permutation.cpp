#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int n = num.size();
		int i = n-2;
		while (i >= 0 && num[i] > num[i+1])
			--i;
		if (i < 0) {
			reverse(num.begin(), num.end());
			return;
		}
		int j = n-1;
		while (num[j] < num[i])
			--j;
		swap(num[i], num[j]);
		reverse(&num[i+1], &num[n-1]+1);
	}
};

int main() {
	int n;
	Solution s;
	vector<int> v;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		v.push_back(i);
	
	int total = 1;
	while (n > 0)
		total *= n--;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	while (--total){
		s.nextPermutation(v);
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	
	return 0;
}