#include <string>
#include <iostream>
using namespace std;

int v[]=   {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
class Solution {
public:
	string intToRoman(int num) {
		int n = sizeof(v) / sizeof(v[0]);
		string ans;
		for (int i = 0; i < n; ){
			if (num >= v[i]){
				ans += s[i];
				num -= v[i];
			}
			else ++i;
		}
		return ans;
	}
};

int main() {
	int i;
	Solution s;
	while (cin >> i){
		cout << s.intToRoman(i) << endl;
	}
	return 0;
}