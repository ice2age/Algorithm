#include <iostream>
using namespace std;

int n, c[30], height[30];

bool increase(int a, int b) {
	return a <= b;
}

bool decrease(int a, int b) {
	return b <= a;
}

template<class Func>
int longestSequence(Func f) {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int mx = 0;
		for (int j = 0; j < i; ++j) {
			if (f(height[j], height[i]) && c[j] > mx)
				mx = c[j];
		}
		c[i] = mx + 1;
			if (c[i] > ans) ans = c[i];
	}
	return ans;
}



int main() {
	int h;
	n = 0;
	while(cin >> h)
		height[n++] = h;
	cout << longestSequence(decrease) << "\n" 
		 << longestSequence(increase) << endl;
	return 0;
}