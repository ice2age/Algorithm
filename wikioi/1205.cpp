#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void go() {
	string word;
	if (cin >> word) {
		go();
		cout << word << " ";
	}
	
}

int main() {
	go();
	return 0;
}