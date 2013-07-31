#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		stack<string> st;
		for (int i = 0, j = 1; j < path.length(); ++j){
			if (path[j] != '/' && j != path.length()-1)
				continue;
			if (path[j] != '/' && j == path.length()-1)
				j++;
			string cmd = path.substr(i, j-i);
			if (cmd == "/.."){
				if (!st.empty())
					st.pop();
			}
			else if (cmd == "/" || cmd == "/.") {

			}
			else
				st.push(cmd);
			i = j;
		}

		string ret;
		while (!st.empty()) {
			ret = st.top() + ret;
			st.pop();
		}
		if (ret.empty())
			ret = "/";
		return ret;
	}
};

int main() {
	Solution s;
	string path;
	while (cin >> path)
		cout << s.simplifyPath(path) << endl;
	return 0;
}