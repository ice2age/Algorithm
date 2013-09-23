#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
using namespace std;

char* multiple[] = {"", "","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple", "decuple"};
char* single[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

void say(const char* str, int n) {
	for (int i = 0; i < n;) {
		int j;
		for (j = i+1; j < n && str[j] == str[i]; ++j)
			;
		int cnt = j-i;
		if (cnt == 1 || cnt > 10)
		{
			for (int k = i; k < j; ++k)
				printf (" %s", single[str[k]-'0']);
		} else {
			printf (" %s", multiple[cnt]);
			printf (" %s", single[str[i]-'0']);
		}
		i = j;
	}
}

int main() {
	int T, n;
	cin >> T; getchar();
	char num[101], *str;
	string line;
	for (int t = 1; t <= T; ++t) {
		getline(cin, line);
		istringstream in(line);
		in >> num >> n;
		str = num;
		printf ("Case #%d: ", t);
		say(str, n);
		str += n;
		char minus;
		while (in >> minus >> n) {
			say(str, n);
			str += n;
		}
		puts("");
	}
	return 0;
}