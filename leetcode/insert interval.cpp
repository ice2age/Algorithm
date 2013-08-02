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

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ret;
		ret.push_back(newInterval);
		if (intervals.empty())
			return ret;
		
		Interval pre, cur;
		for (int i = 0; i < intervals.size(); ++i){
			pre = ret.back();
			ret.pop_back();
			cur = intervals[i];
			if (cur.end < pre.start){
				ret.push_back(cur);
				ret.push_back(pre);
			}else if (cur.start > pre.end){
				ret.push_back(pre);
				ret.push_back(cur);
			}else {
				newInterval.end = max(pre.end, cur.end);
				newInterval.start = min(pre.start, cur.start);
				ret.push_back(newInterval);
			}
		}
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
		cin >> s >> e;
		Interval val(s, e);
		print(v);
		v = sln.insert(v, val);
		print(v);
	}
	return 0;
}