#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double C) {
	return x * x + sqrt(x) - C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	double C;
	cin >> C;
	double left = 0;
	double right = sqrt(C);
	double x;
	for (int i = 0; i < 100; i++) {
		x = (left + right) / 2;
		if (f(x, C) < 0) {
			left = x;
		}
		else right = x;
	}
	cout << fixed;
	cout.precision(7);
	cout << x;
}