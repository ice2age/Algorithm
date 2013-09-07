#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string placeQueen(int j, int n) {
		int i;
		string row;
		for (i = 0; i < n; ++i) {
			if (i == j) row.push_back('Q');
			else 		row.push_back('.');
		}	
		return row;
	}

	void search(int row, int n, vector<string>& sol, bool* col, bool* add, bool* sub) {
		if (row == n) {
			queens.push_back(sol);
			return;
		}

		for (int j = 0; j < n; ++j) {
			if (!col[j] && !add[j+row] && !sub[j-row+n]) {
				col[j] = true;
				add[j+row] = true;
				sub[j-row+n] = true;
				sol.push_back(placeQueen(j, n));
				search(row+1, n, sol, col, add, sub);
				sol.pop_back();
				col[j] = false;
				add[j+row] = false;
				sub[j-row+n] = false;
			}
		}
	}

	vector<vector<string> > solveNQueens(int n) {
		queens.clear();
		vector<string> sol;
		bool* col = new bool[n];
		bool* sub = new bool[n<<1];
		bool* add = new bool[n<<1];
		memset(col, false, n*sizeof(bool));
		memset(sub, false, (n<<1)*sizeof(bool));
		memset(add, false, (n<<1)*sizeof(bool));
		search(0, n, sol, col, add, sub);
		return queens;
	}

private:
	vector<vector<string> > queens;
};

void printQueens(const vector<vector<string> >& queens, int n) {
	int s = queens.size();
	for (int i = 0; i < s; ++i) {
		vector<string> sol = queens[i];
		for (int j = 0; j < n; ++j)
			cout << sol[j] << endl;
		cout << endl;
	}
}

int main() {
	int n;
	Solution s;
	while (cin >> n) {
		printQueens(s.solveNQueens(n), n);
	}
	return 0;
}