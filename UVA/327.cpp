#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

const int NUM = 26;
const int SIZE = 110;

int flag[NUM];
int value[NUM];
char expr[SIZE+1];

void addFlag()
{
	for (int i = 0; expr[i]; ++i)
		if (isalpha(expr[i]))
			flag[expr[i]-'a'] = 1;
}

void removeSpace()
{
	int i = 0;
	for (int j = 0; expr[j]; ++j)
		if (!isspace(expr[j]))
			expr[i++] = expr[j];
	expr[i] = 0;
}

bool checkPre(int& i, char ch, int len)
{
	if (i < len-2 && isalpha(expr[i+2]))
	{
		if (ch == '+')
			value[expr[i+2]-'a']++;
		else
			value[expr[i+2]-'a']--;
		expr[i] = ' ';
		expr[++i] = ' ';
		return true;
	}
	return false;
}

bool checkPost(int& i, char ch)
{
	if (i > 0 && isalpha(expr[i-1]))
	{
		flag[expr[i-1]-'a'] = (ch == '+' ? 2 : 3);
		expr[i] = ' ';
		expr[++i] = ' ';
		return true;
	}
	return false;
}

void removeUnary()
{
	int len = strlen(expr);
	for (int i = 0; i < len; ++i)
		if(i < len-1 && expr[i] == expr[i+1])
			if (!checkPost(i, expr[i]))
				checkPre(i, expr[i], len);
	removeSpace();
}

int calc()
{
	assert (expr[0] != 0);
	assert (isalpha(expr[0]));
	int result = value[expr[0]-'a'];
	for (int i = 1; expr[i]; ++i)
		if (isalpha(expr[i]))
		{
			if (expr[i-1] == '+')
				result += value[expr[i]-'a'];
			else
				result -= value[expr[i]-'a'];
		}
	return result;
}

void after()
{
	for (int i = 0; expr[i]; ++i)
	{
		if (flag[expr[i]-'a'] == 2)
			++value[expr[i]-'a'];
		else if (flag[expr[i]-'a'] == 3)
			--value[expr[i]-'a'];
	}
}

int solve()
{
	addFlag();
	removeSpace();
	removeUnary();
	int ret = calc();
	after();
	return ret;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (gets(expr) != NULL)
	{
		
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < NUM; ++i)
			value[i] = i+1;
		printf ("Expression: %s\n", expr);
		printf ("    value = %d\n", solve());
		for (int i = 0; i < NUM; ++i)
			if (flag[i])
				printf ("    %c = %d\n", i+'a', value[i]);
	}

	return 0;
}