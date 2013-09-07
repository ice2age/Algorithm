#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	void solve(int id, vector<vector<char> > &board) {
		if (id == 49) {
			solved = true;
			ans = board;
			return;
		}
		//if (solved) return;
		
		int i = id / 9, j = id - i*3;
		if (board[i][j] == '.') {
			for (int d = 0; d < 9; ++d) {
				int ii = i/3, jj = j/3;
				int c = ii*3 + jj;
				if (!row[i][d] && !col[j][d] && !cell[c][d]) {
					row[i][d] = true;
					col[j][d] = true;
					cell[c][d] = true;
					board[i][j] = d+'1';
					solve(id+1, board);
					row[i][d] = false;
					col[j][d] = false;
					cell[c][d] = false;
					board[i][j] = '.';
				}
			}
		}
	}
	
	void solveSudoku(vector<vector<char> > &board) {
		int n = board.size();
		row = new bool*[n];
		for (int i = 0; i < n; ++i){
			row[i] = new bool[n];
			memset(row[i], false, n*sizeof(bool));
		}
		col = new bool*[n];
		for (int i = 0; i < n; ++i){
			col[i] = new bool[n];
			memset(col[i], false, n*sizeof(bool));
		}
		cell = new bool*[n];
		for (int i = 0; i < n; ++i){
			cell[i] = new bool[n];
			memset(cell[i], false, n*sizeof(bool));
		}
		
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == '.')
					continue;
				int d = board[i][j] - '1';
				row[i][d] = true;
				col[j][d] = true;
				int ii = i/3, jj = j/3;
				int c = ii*3 + jj;
				cell[c][d] = true;
			}
		}
		solved = false;
		solve(0, board);
		board.swap(ans);
	}
	
private:
	bool solved;
	bool** row;
	bool** col;
	bool** cell;
	vector<vector<char> > ans;
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
	s.solveSudoku(board);
	for (int i = 0; i < 9; ++i) {
		copy(board[i].begin(), board[i].end(), ostream_iterator<char>(cout, ""));
		cout << endl;
	}
	
	return 0;
}