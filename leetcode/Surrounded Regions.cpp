#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
	void flood(vector<vector<char>> &board, int i, int j) {
		assert (i >= 0 && i < r && j >= 0 && j < c);
		board[i][j] = '.';
		if (j > 0 && board[i][j-1] == 'O')
			flood(board, i, j-1);
		if (j < c-1 && board[i][j+1] == 'O')
			flood(board, i, j+1);
		if (i > 0 && board[i-1][j] == 'O')
			flood(board, i-1, j);
		if (i < r-1 && board[i+1][j] == 'O')
			flood(board, i+1, j);
	}

	void postProcess(vector<vector<char>> &board) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (board[i][j] == 'O')
					board[i][j] = 'X';
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (board[i][j] == '.')
					board[i][j] = 'O';
	}

	void solve(vector<vector<char>> &board) {
		if (board.empty())
			return;
		r = board.size();
		c = board[0].size();
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (board[i][j] == 'O' && (i == 0 || i == r-1 || j == 0 || j == c-1))
					flood(board, i, j);
		postProcess(board);
	}

private:
	int r, c;
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution s;
	string str;
	vector<vector<char>> board;
	int i = 0;
	while (cin >> str)
	{
		board.resize(i+1);
		for (size_t j = 0; j < str.length(); ++j)
			board[i].push_back(str[j]);
		++i;
	}
	s.solve(board);

	return 0;
}