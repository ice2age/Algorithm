//qpad: vc_version="11"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        for (int i = 1; i <= rowIndex; ++i){
        	long long t = (rowIndex-i+1);
        	long long tt = v[i-1]*t/i;
        	v.push_back((int)tt);
        }
        return v;
    }
};

void print (vector<int> v){
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	Solution s;
	int i;
	while (cin >> i){
		print(s.getRow(i));
	}
	return 0;
}