#include <iostream>
#include <iterator>
using namespace std;

int main() {
	int n, d[100][100];
	cin >> n;
	int i = n >> 1, j = n >> 1;
	d[i][j] = 1;
	//right 0, up 1, left 2, down 3
	int dir = 0, sum = 1, step = 1, num = 2;
	while (num <= n*n) {
		int s = step;
		while (s--) {
			switch(dir) {
				case 0:	++j; break;
				case 1:	--i; break;
				case 2:	--j; break;
				case 3:	++i; break;
			}
			if (i == j || i+j == n-1)
				sum += num;
			d[i][j] = num;
		}
		dir = (dir+1) % 4;
		if (dir == 0 || dir == 2)
			step++;
	}
	for (int i = 0; i < n; ++i){
		copy(d[i], d[i]+n, ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	cout << sum << endl;
	return 0;
}