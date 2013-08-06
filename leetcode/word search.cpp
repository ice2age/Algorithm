#include <vector>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
	bool search(int i, int j, int index, bool** visited, vector<vector<char> >& b, const string& w ) {
		if (index == w.length()) return true;
		
		int n = b.size(), m = b[0].size();
		if (i > 0 && !visited[i-1][j] && w[index] == b[i-1][j]){
			visited[i-1][j] = true;
			if (search(i-1, j, index+1, visited, b, w))
				return true;
			visited[i-1][j] = false;
		}
		if (i < n-1 && !visited[i+1][j] && w[index] == b[i+1][j]){
			visited[i+1][j] = true;
			if (search(i+1, j, index+1, visited, b, w))
				return true;
			visited[i+1][j] = false;
		}
		if (j > 0 && !visited[i][j-1] && w[index] == b[i][j-1]){
			visited[i][j-1] = true;
			if (search(i, j-1, index+1, visited, b, w))
				return true;
			visited[i][j-1] = false;
		}
		if (j < m-1 && !visited[i][j+1] && w[index] == b[i][j+1]){
			visited[i][j+1] = true;
			if (search(i, j+1, index+1, visited, b, w))
				return true;
			visited[i][j+1] = false;
		}
		return false;	
	}
	
	bool exist(vector<vector<char> > &board, string word) {
		if (word.length() == 0) false;
		int n = board.size();
		if (n == 0) return false;
		int m = board[0].size();
		bool** visited = new bool*[n];
		for (int i = 0; i < n; ++i){
			visited[i] = new bool[m];
			for (int j = 0; j < m; ++j)
				visited[i][j] = false;
		}
		
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (board[i][j] == word[0]) {
					visited [i][j] = true;
					if (search(i, j, 1, visited, board, word))
						return true;	
					visited [i][j] = false;
				}
			}
		}
		return false;
	}
};

void print(vector<vector<char> > & b) {
	int n = b.size();
	for (int i = 0; i < n; ++i) {
		copy(b[i].begin(), b[i].end(), ostream_iterator<char>(cout));
		cout << endl;
	}	
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		getchar();
		vector<vector<char> > b;
		for (int i = 0; i < n; ++i){
			vector<char> v;
			for (int j = 0; j < m; ++j){
				v.push_back(getchar());
			}
			getchar();
			b.push_back(v);
		}
		string str;
		Solution s;
		while (cin >> str){
			cout << s.exist(b, str) << endl;
		}
	}
	return 0;
}