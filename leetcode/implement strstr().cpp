#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!haystack || !needle) return NULL;
        int a = strlen(haystack), b = strlen(needle);
        if (a < b) return NULL;
        for (int i = 0; i <= a - b; ++i){
        	int j = 0;
        	for (; j < b && haystack[i+j]==needle[j]; ++j)
        		;
        	if (j == b) return haystack+i;
        }
        return NULL;
    }
};

int main() {
	Solution s;
	char a[100], b[100];
	cin >> a >> b;
	cout << s.strStr(a, b) << endl;
	return 0;
}