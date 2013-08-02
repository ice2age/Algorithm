#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //C(m, n) = C(m-1, n) + C(m-1, n-1)
        int t = min(m, n);
        m = m+n-2;
        n = t-1;
        long long* c = new long long[n+1];
        memset(c, 0, sizeof(long long)*(n+1));
        c[0] = 1;
        for (int i = 0; i < m; ++i)
        	for (int j = n; j >= 1; --j)
        		c[j] += c[j-1];
        return c[n];
    }
};

int main() {
	int m, n;
	Solution s;
	while (cin >> m >> n){
		cout << s.uniquePaths(m, n) << endl; 
	}
	return 0;
}