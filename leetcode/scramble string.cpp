#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        if (m != n) return false;
        if (m == 0) return true;
        if (m == 1) return s1[0] == s2[0];
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        for (int i = 0; i < m; ++i)
        	if (t1[i] != t2[i]) return false;
        for (int i = 1; i < n; ++i){
        	string s11 = s1.substr(0, i);
        	string s12 = s1.substr(i);
        	string s21 = s2.substr(0, i);
        	string s22 = s2.substr(i);
        	if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
        	if (isScramble(s11, s22) && isScramble(s12, s21)) return true;
        	string s3 = s2.substr(0, n-i);
        	string s4 = s2.substr(n-i);
        	if (isScramble(s11, s4) && isScramble(s12, s3)) return true;
        }
        return false;
    }
};

int main() {
	Solution s;
	string s1, s2;
	while (cin >> s1 >> s2){
		cout << s.isScramble(s1, s2) << endl;
	}
	return 0;
}