#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int i, j;
        int n = strlen(s);
        for (i = n-1; i >= 0 && isspace(s[i]); --i)
        	;
        for (j = i; j >= 0 && isalpha(s[j]); --j)
        	;
        return i-j;
    }
};

int main() {
	char line[1024];
	Solution s;
	while (gets(line)){
		cout << s.lengthOfLastWord(line) << endl;
	}
	return 0;
}