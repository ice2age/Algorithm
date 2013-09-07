#include <stdio.h>
#include <string.h>

int search(const char* a, const char* b) {
	int la = strlen(a), lb = strlen(b), j;
	for (int i = 0; i <= la-lb; ++i) {
		for (j = 0; j < lb; ++j){
			if (a[i+j] != b[j])
				break;
		}
		if (j == lb) return i;
	}
	return -1;
}

int main() {
	char a[100], b[100];
	scanf ("%s %s", a, b);
	
	printf ("%d\n", search(a, b)+1);
			
	return 0;
}