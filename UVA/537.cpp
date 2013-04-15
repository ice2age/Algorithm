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
	char line[1000];
	double real;
	cin >> T;
	getchar();
	for (int t = 1; t <= T; ++t)
	{
		gets(line);
		int cnt = 0;
		used[0] = used[1] = used[2] = 0;
		for (int i = 0; line[i]; ++i)
		{
			if (line[i] == '=')
			{
				mark(line[i-1]);
				++i;
				++cnt;
				sscanf (line+i, "%lf", &real);
				real *= getPrefix(i, line);
				setData(real, line[i]);
			}

			if (cnt == 2)
				break;
		}
		printf ("Problem #%d\n", t);
		int unsolved = 0;
		double known[2];
		cnt = 0;
		for (int i = 0; i < 3; ++i)
			if (!used[i])
				unsolved = i;
			else
				known[cnt++] = data[i];

		printf ("%c=%.2lf%c\n\n", concept[unsolved], funcs[unsolved](known[0], known[1]), unit[unsolved]);
	}
	return 0;
}
