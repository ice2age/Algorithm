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
#include <limits>
using namespace std;

typedef long long Loong;

struct bignum
{
	int len;
	char data[600];

	bignum()
	{
		len = 1;
		memset(data, 0, sizeof(data));
	}

	friend istream& operator >> (istream& in, bignum& num);
	explicit bignum(string str)
	{
		istringstream in(str);
		in >> *this;
	}

	explicit bignum(unsigned int num)
	{
		len = 0;
		memset(data, 0, sizeof(data));
		while (num > 0)
		{
			data[len++] = num % 10;
			num /= 10;
		}
		if (len == 0)
			len = 1;
	}

	bignum operator / (unsigned int num)
	{
		Loong r;
		bignum q;
		divide(num, q, r);
		return q;
	}

	int operator % (unsigned int num)
	{
		Loong r;
		bignum q;
		divide(num, q, r);
		return (int)r;
	}

private:
	void divide(unsigned int divisor, bignum& quotient , Loong& remainder)
	{
		remainder = 0;
		for (int i = len-1; i >= 0; --i)
		{
			remainder = remainder*10 + data[i];
			quotient.data[i] = (int)(remainder / divisor);
			remainder %= divisor;
		}
		quotient.len = len;
		while (quotient.len > 1 && quotient.data[quotient.len-1] == 0)
			--quotient.len;
	}
};

int compbignum(const bignum& lhs, const bignum& rhs)
{
	int i, j;
	int l = lhs.len;
	if (rhs.len > l)
		l = rhs.len;
	for (i = j = l-1; i >=0 && j >= 0 && lhs.data[i] == rhs.data[j]; --i, --j)
		;
	if (i >=0 && j >= 0)
		return lhs.data[i] - rhs.data[j];
	return 0;
}

bool operator < (const bignum& lhs, const bignum& rhs)
{
	return compbignum(lhs, rhs) < 0;
}

bool operator > (const bignum& lhs, const bignum& rhs)
{
	return compbignum(lhs, rhs) > 0;
}

bool operator == (const bignum& lhs, const bignum& rhs)
{
	return compbignum(lhs, rhs) == 0;
}

bignum operator * (const bignum& lhs, const bignum& rhs)
{
	int c, i, j;
	bignum ans;
	for (i = 0; i < rhs.len; ++i)
	{
		c = 0;
		for (j = 0; j < lhs.len; ++j)
		{
			char& sum = ans.data[i+j];
			sum += rhs.data[i] * lhs.data[j] + c;
			c = sum / 10;
			sum %= 10;
		}
		if (c > 0)
			ans.data[i+j] = c;
	}
	ans.len = lhs.len + rhs.len - 1;
	if (ans.data[ans.len] > 0)
		ans.len++;
	while (ans.len > 1 && ans.data[ans.len-1] == 0)
		--ans.len;
	return ans;
}

bignum operator + (const bignum& lhs, const bignum& rhs)
{
	bignum ans;
	ans.len = lhs.len;
	if (rhs.len > ans.len)
		ans.len = rhs.len;
	int c = 0;
	for (int i = 0; i < ans.len; ++i)
	{
		int s = lhs.data[i] + rhs.data[i] + c;
		ans.data[i] = s % 10;
		c = s / 10;
	}
	if (c > 0)
		ans.data[ans.len++] = c;
	return ans;
}

istream& operator >> (istream& in, bignum& num)
{
	memset(num.data, 0, sizeof(num.data));
	string line;
	in >> line;
	int len = line.length();
	int i = 0;
	while (i < len && line[i] == '0')
		++i;
	for (int j = 0; j < len-i; ++j)
		num.data[j] = line[len-1-j]-'0';
	num.len = len - i;
	if (num.len <= 0)
		num.len = 1;
	return in;
}
ostream& operator << (ostream& out, const bignum& num)
{
	for (int i = num.len-1; i >= 0; --i)
		cout << (int)num.data[i];
	return out;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	string d;

	while (cin >> d >> n)
	{
		int pos = 0;
		int i = d.find('.');
		while (d.length() > 1 && d[d.length()-1] == '0')
			d.erase(d.end()-1);
		if (i != string::npos)
		{
			pos = d.length() - i - 1;
			d.erase(d.begin() + i);
		}

		bignum exp(1), bigd(d.c_str());
		pos *= n;
		while (n--)
		{
			exp = exp * bigd;
		}
		for (int i = exp.len-1; i >= pos; --i)
			cout << (int)exp.data[i];
		cout << ".";
		for (int i = pos-1; i >= 0; --i)
			cout << (int)exp.data[i];
		cout << endl;
	}

	return 0;
}