#include <stdio.h>
#include <string.h>

char name[100][101];
int index[100], temp[100];

inline bool comp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}

int merge(int* index, int l, int r) {
	int n = l + r;
	int i = 0, j = l, c = 0, ans = 0;
	while (i < l && j < n) {
		if (comp(index[i], index[j])) {
			temp[c++] = index[i++];
		} else {
			temp[c++] = index[j++];
			ans += i+1;
		}
	}
	if (i < l) {
		ans += (l-i-1)*r;
		memcpy(temp+c, index+i, (l-i)*sizeof(index[0]));
	}
	if (j < n) memcpy(temp+c, index+j, (n-j)*sizeof(index[0]));
	memcpy(index, temp, n*sizeof(index[0]));
	return ans;
}

int mergeSort(int* index, int n) {
	if (n <= 1) return 0;
	int l = n >> 1;
	int r = n - l;
	int a = mergeSort(index, l);
	int b = mergeSort(index+l, r);
	return a+b+merge(index, l, r);	
}

int selectSort(int* index, int n) {
	int maxI = 0, ans = 0;
	for (int i = 1; i < n; ++i) {
		if (comp(index[i], index[maxI]))
			ans++;
		else
			maxI = i;
	}
	return ans;
}

int main() {
	int T, n;
	scanf ("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf ("%d", &n);
		getchar();
		for (int i = 0; i < n; ++i){
			gets(name[i]);
			index[i] = i;
		}
		printf ("Case #%d: %d\n", t, selectSort(index, n));
	}
	return 0;
}