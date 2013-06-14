#include <cstdio>
#include <cassert>
#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution
{
public:
	void init()
	{
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j)
				isPal[i][j] = false;
		for (int j = 0; j < len; ++j)
			for (int i = j; i >= 0; --i)
				if (str[i] == str[j] && (j-i<2 || isPal[i+1][j-1]))
					isPal[i][j] = true;
	}

	void search(int i, vector<int>& index, vector<vector<string>>& vec)
	{
		if (i == len)
		{
			vector<string> v;
			for (size_t i = 0; i < index.size()-1; ++i)
				v.push_back(str.substr(index[i]+1, index[i+1]-index[i]));
			vec.push_back(v);
			return;
		}
		for (int j = i; j < len; ++j)
		{
			if (isPal[i][j])
			{
				index.push_back(j);
				search(j+1, index, vec);
				index.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s)
	{
		str = s;
		len = s.length();
		isPal = new bool*[len];
		for (int i = 0; i < len; ++i)
			isPal[i] = new bool[len];
		init();
		vector<int> index;
		vector<vector<string>> vec;
		index.push_back(-1);
		search(0, index, vec);
		return vec;
	}

private:
	int len;
	string str;
	bool** isPal;
};

int main()
{
	Solution s;
	string str;
	while (cin >> str)
	{
		vector<vector<string>> vec = s.partition(str);
		cout << "[" << endl;
		for (size_t i = 0; i < vec.size(); ++i)
		{
			cout << "\t[";
			for (size_t j = 0; j < vec[i].size(); ++j)
				cout << "\"" << vec[i][j] << "\"" << (j == vec[i].size()-1 ? "" : ",");
			cout << "]" << (i == vec.size()-1 ? "" : ",") << endl;
		}
		cout << "]" << endl;
	}
	return 0;
}