#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool operator < (const Interval& lhs, const Interval& rhs) {
	return lhs.start < rhs.start;
}

class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		int n = intervals.size();
		if (n <= 1)
			return intervals;
		
		vector<Interval> ret;
		sort(intervals.begin(), intervals.end());
		Interval* pre = &intervals[0];
		for (int i = 1; i < n; ++i){
			Interval* cur = &intervals[i];
			if (cur->start > pre->end){
				ret.push_back(*pre);
				pre = cur;
			}
			else
				pre->end = max(pre->end, cur->end);
		}
		ret.push_back(*pre);
		return ret;
	}
};

ostream& operator << (ostream& out, const Interval& inter) {
	out << '[' <<inter.start << "," << inter.end << ']';
	return out;
}

void print(vector<Interval>& v) {
	copy(v.begin(), v.end(), ostream_iterator<Interval>(cout, ","));
	cout << endl;
}

int main() {
	int n;
	Solution sln;
	while (cin >> n){
		int s, e;
		vector<Interval> v;
		for (int i = 0; i < n; ++i){
			cin >> s >> e;
			v.push_back(Interval(s, e));
		}
		print(v);
		v = sln.merge(v);
		print(v);
	}
	return 0;
}