#include <iostream>

using namespace std;

bool good(long long diploms, long long w, long long h, long long x) {
	return (x / w) * (x / h) >= diploms;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long w, h, n;
	cin >> w >> h >> n;
	
	long long left = 0;
	long long right = n * max(w, h) + 1;
	while (left + 1 < right) {
		long long mid = (left + right) / 2;
		if (good(n, w, h, mid)) {
			right = mid;
		}
		else left = mid;
	}
	cout << right;
}