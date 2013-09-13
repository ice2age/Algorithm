#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1) return s;
		int len = s.length();
		int width = (len - nRows) / (nRows - 1);
		
		char** c = new char*[nRows];
		for (int i = 0; i < nRows; ++i) {
			c[i] = new char[width];
			memset(c[i], 0, width*sizeof(char));
		}
		int dx[] = {1, -1};
		int dy[] = {0,  1};
		int count = 0, i = 0, j = 0, id = 0;
		while (count <= len) {
			c[i][j] = s[count++];
			if (id == 1 && i == 0) id = 1 - id;
			if (id == 0 && i == nRows-1) id = 1 - id;
			i += dx[id];
			j += dy[id];
		}
		string ans;
		for (int i = 0; i < nRows; ++i){
			for (int j = 0; j < width; ++j){
				if (c[i][j]) ans += c[i][j];
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	string str;
	int n;
	while (cin >> str >> n){
		cout << s.convert(str, n) << endl;
	}
	return 0;
}