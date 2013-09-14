#include <cstdio>
#include <iostream>
using namespace std;

int n, num[11];
bool visited[11];

void solve(int i) {
	if (i > n){
		for (int j = 1; j < n; ++j)
			printf ("%d ", num[j]);
		printf ("%d\n", num[n]);
		return;
	}
	
	for (int j = 1; j <= n; ++j) {
		if (!visited[j]){
			visited[j] = true;
			num[i] = j;
			solve(i+1);
			visited[j] = false;
		}
	}
}

int main() {
	cin >> n;
	solve(1);
	
	return 0;
}