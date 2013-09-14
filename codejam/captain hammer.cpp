#include <math.h>
#include <stdio.h>

const double G = 9.8;
const double PI = 3.1415926535898;
const double TERM = 90.0 / PI;
int main() {
	int n;
	double v, d;
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lf %lf", &v, &d);
		double arc = G*d/v/v;
		if (arc > 1.0) arc = 1.0;
		double ans = TERM*asin(arc);
		if (ans < 0) ans = 0.0;
		printf ("Case #%d: %.7f\n", i, ans);
	}
	return 0;
}