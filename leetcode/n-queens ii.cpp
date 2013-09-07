#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	void search(int row, int n, bool* col, bool* add, bool* sub) {
		if (row == n) {
			count++;
			return;
		}

		for (int j = 0; j < n; ++j) {
			if (!col[j] && !add[j+row] && !sub[j-row+n]) {
				col[j] = true;
				add[j+row] = true;
				sub[j-row+n] = true;
				search(row+1, n, col, add, sub);
				col[j] = false;
				add[j+row] = false;
				sub[j-row+n] = false;
			}
		}
	}

	int totalNQueens(int n) {
		count = 0;
		bool* col = new bool[n];
		bool* sub = new bool[n<<1];
		bool* add = new bool[n<<1];
		memset(col, false, n*sizeof(bool));
		memset(sub, false, (n<<1)*sizeof(bool));
		memset(add, false, (n<<1)*sizeof(bool));
		search(0, n, col, add, sub);
		return count;
	}

private:
	int count;
};

int main() {
	int n;
	Solution s;
	while (cin >> n) {
		cout << s.totalNQueens(n) << endl;
	}
	return 0;
}