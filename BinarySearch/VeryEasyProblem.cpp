#include <iostream>

using namespace std;

bool good(long long copies, long long x, long long y, int time) {
	return time / x + time / y >= copies;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n, x ,y;
	cin >> n >> x >> y;
	if (n == 1) {
	    cout << min(x, y);
	    return 0;
	}
	long long left = min(x, y) - 1;
	long long right = min(x, y) * n;
	while (left + 1 < right) {
		long long mid = (left + right) / 2;
		if (good(n-1, x, y, mid)) {
			right = mid;
		}
		else left = mid;
	}
	cout << right + min(x, y);
}