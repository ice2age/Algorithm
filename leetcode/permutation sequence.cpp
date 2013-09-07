#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int factorial(int n) {
		int r = 1;
		for (int i = 2; i <= n; ++i)
			r *= i;
		return r;
	}
	
	int getKth(int k, bool* visited) {
		int i = 0, count = 0;
		while (count < k) {
			if (!visited[i++])
				++count;
		}
		return i-1;
	}
	
	void search(int n, int k, string& res, bool* visited) {
		if (n == 0) return;
		int num = factorial(n-1);
		int i = (k+num-1) / num;
		int j = getKth(i, visited);
		visited[j] = true;
		res.push_back('0'+j+1);
		search(n-1,k-(i-1)*num, res, visited);
	}
	
	string getPermutation(int n, int k) {
		bool* visited = new bool[n];
		memset (visited, false, n*sizeof(bool));
		string res;
		search(n, k, res, visited);
		return res;
	}
};

int main() {
	Solution s;
	int n, k;
	while (cin >> n >> k) {
		cout << s.getPermutation(n, k) << endl;
	}
	
	return 0;
}