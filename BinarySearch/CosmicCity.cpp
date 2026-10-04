#include <iostream>

using namespace std;

bool good(uint64_t n, uint64_t a, uint64_t b, uint64_t w, uint64_t h, uint64_t d) {
	uint64_t mod_a = a + 2 * d;
	uint64_t mod_b = b + 2 * d;
	return (((w / mod_a) * (h / mod_b) >= n) || ((w / mod_b) * (h / mod_a) >= n));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	uint64_t n, a, b, w, h;
	cin >> n >> a >> b >> w >> h;
	uint64_t left = 0;
	uint64_t right = 1;
	while (good(n, a, b, w, h, right)) {
		right *= 2;
	}
	while (left + 1 < right) {
		uint64_t mid = (left + right) / 2;
		if (good(n, a, b, w, h, mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << left;
}