#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>
#include <utility>

using namespace std;

typedef long long Loong;

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	string digit;

	cin >> n;
	while (n--)
	{
		cin >> digit;
		int len = digit.length();
		if (digit == "1" || digit == "4" || digit == "78")
			cout << "+" << endl;
		else if (len > 1 && digit[len-2] == '3' && digit[len-1] == '5')
			cout << "-" << endl;
		else if (len > 1 && digit[0] == '9' && digit[len-1] == '4')
			cout << "*" << endl;
		else
			cout << "?" << endl;
	}

	return 0;
}