#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long Loong;

double getP(double U, double I)
{
	return U*I;
}

double getUI(double P, double IU)
{
	return P/IU;
}

char unit[4] = "WVA";
char concept[4] = "PUI";
char prefix[4] = "mkM";
bool used[3];
double prenum[3] = {1e-3,1e3,1e6};
double data[3];
typedef double (*CalcFunc)(double a, double b);
CalcFunc funcs[3] = {getP, getUI, getUI};

double getPrefix(int& i, const char* str)
{
	while (str[i] && !isspace(str[i]))
		++i;
	--i;
	while (i>=0 && !isalpha(str[i]))
		--i;
	for (int j = 0; j < 3; ++j)
		if (prefix[j] == str[i-1])
			return prenum[j];
	return 1.0;
}

void mark(char ch)
{
	for (int i = 0; i < 3; ++i)
		if (concept[i] == ch)
			used[i] = true;
}

void setData(double d, char ch)
{
	for (int i = 0; i < 3; ++i)
		if (unit[i] == ch)
			data[i] = d;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int T;
	string line1;
	string line2;
	string character = "<>";

	cin >> T;
	getchar();
	while (T--)
	{
		getline(cin, line1);
		getline(cin, line2);

		string str[5];
		int i = 0, pre = 0, pos = 0;
		while ((pos = line1.find_first_of(character, pre)) != string::npos)
		{
			str[i++] = line1.substr(pre, pos-pre);
			pre = pos+1;
		}
		str[i] = line1.substr(pre, pos-pre);
		for (int j = 0; line1[j]; ++j)
			if (line1[j] != '<' && line1[j] != '>')
				putchar(line1[j]);
		cout << endl;
		int l = line2.length();
		for (int j = 0; j < l; ++j)
			if (j <= l-3 && line2[j] == '.' && line2[j] == line2[j+1] && line2[j] == line2[j+2])
			{
				cout << str[3] << str[2] << str[1] << str[4];
				j += 2;
			}
			else
				putchar(line2[j]);
		cout << endl;
	}
	return 0;
}
