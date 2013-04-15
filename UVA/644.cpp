#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long long Loong;

char words[8][11];

int strcomp(const void* a, const void* b)
{
    char* pa = (char*)a;
    char* pb = (char*)b;
    int la = strlen(pa);
    int lb = strlen(pb);
    if (la != lb)
        return la - lb;
    else
        return strcmp(pa, pb);
}

bool prefix(const char* sml, const char* big)
{
    while (*sml == *big)
    {
        ++sml;
        ++big;
    }
    return *sml == 0;
}

bool solve (int n)
{
    qsort(words, n, sizeof(words[0]), strcomp);

    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if (prefix(words[i], words[j]))
                return false;
    return true;
}

int main(void)
{
#ifdef NOT_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    char line[11];
    int t = 0, n = 0;
    while (gets(line))
    {
        if (line[0] == '9')
        {
            ++t;
            if(solve(n))
                printf ("Set %d is immediately decodable\n", t);
            else
                printf ("Set %d is not immediately decodable\n", t);
            n = 0;
        }
        else
        {
            strcpy(words[n++], line);
        }
    }
    return 0;
}
