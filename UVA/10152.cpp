#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
	const int MAX_N = 200;
	int n, c;  
	char f[MAX_N], initial[MAX_N][100], final[MAX_N][100];  
	cin>>c;  
	for(int e=0; e<c; e++)  
	{
		cin >> n;
		getchar();
		for(int i = 0; i < n; i++)
			gets(initial[i]); 
		for(int i = 0; i < n; i++)
			gets(final[i]);
		memset(f, 0, sizeof(f));
		int j = n - 1;
		for(int i = n-1; i >= 0; --i)
		{
			if(strcmp(initial[i], final[j])==0)
			{
				f[j]=1;
				j--;
			}
		}
		for(; j >= 0; --j)
			if(f[j] == 0)
				puts(final[j]);
		puts("");
	}
	return 0;
}