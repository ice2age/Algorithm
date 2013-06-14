#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int, int> mp;
		for (size_t i = 0; i < num.size(); ++i)
			mp[num[i]] = i;
		int maxLen = 0;
		vector<bool> visited(num.size(), false);
		for (size_t i = 0; i < num.size(); ++i) {
			if (visited[i])
				continue;
			visited[i] = true;
			int count = 1;
			int n = num[i];
			while (mp.count(--n)) {
				++count;
				visited[mp[n]] = true;
			}
			n = num[i];
			while (mp.count(++n)) {
				++count;
				visited[mp[n]] = true;
			}
			if (count > maxLen)
				maxLen = count;
		}
		return maxLen;
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(100);
	v.push_back(4);
	v.push_back(200);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	Solution s;
	cout << s.longestConsecutive(v) << endl;

	return 0;
}