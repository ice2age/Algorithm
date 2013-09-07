#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		int n = board.size();
		bool** row = new bool*[n];
		for (int i = 0; i < n; ++i){
			row[i] = new bool[n];
			memset(row[i], false, n*sizeof(bool));
		}
		bool** col = new bool*[n];
		for (int i = 0; i < n; ++i){
			col[i] = new bool[n];
			memset(col[i], false, n*sizeof(bool));
		}
		bool** cell = new bool*[n];
		for (int i = 0; i < n; ++i){
			cell[i] = new bool[n];
			memset(cell[i], false, n*sizeof(bool));
		}
		
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == '.')
					continue;
				int d = board[i][j] - '1';
				if (row[i][d] || col[j][d])
					return false;
				row[i][d] = true;
				col[j][d] = true;
				int ii = i/3, jj = j/3;
				int c = ii*3 + jj;
				if (cell[c][d])
					return false;
				cell[c][d] = true;
			}
		}
		
		return true;
	}
};

int main() {
	vector<vector<char> > board;
	string line;
	while (cin >> line) {
		vector<char> row;
		for (int i = 0; i < line.size(); ++i){
			row.push_back(line[i]);
		}
		board.push_back(row);
	}
	Solution s;
	cout << s.isValidSudoku(board) << endl;
	return 0;
}