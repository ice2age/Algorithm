#include <iostream>
using namespace std;

int d[17][2];
void pre(int t) {
	if (t) {
		cout << t << " ";
		pre(d[t][0]);
		pre(d[t][1]);
	}	
}

void in(int t) {
	if (t) {
		in(d[t][0]);
		cout << t << " ";
		in(d[t][1]);
	}	
}

void post(int t) {
	if (t) {
		post(d[t][0]);
		post(d[t][1]);
		cout << t << " ";
	}	
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> d[i][0] >> d[i][1];
	}
	pre(1); cout << endl;
	in(1); cout << endl;
	post(1); cout << endl;
	return 0;
}