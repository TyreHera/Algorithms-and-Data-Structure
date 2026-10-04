#include <iostream>

using namespace std;

double f(double x, double a, double b, double c, double d) {
	return a*x*x*x + b*x*x + c*x + d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double left = -2000;
	double right = 2000;
	double x;
	for (int i = 0; i < 100; i++) {
		x = (left + right) / 2;
		if ((f(left, a, b, c, d) > 0) == (f(x, a, b, c, d) > 0)) {
			left = x;
		}
		else right = x;
	}
	cout << fixed;
	cout.precision(5);
	cout << x;
}