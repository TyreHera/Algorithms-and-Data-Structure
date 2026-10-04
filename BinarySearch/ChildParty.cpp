#include <iostream>

using namespace std;

int compute_count_balls(int t, int z, int y, int time) {
	int cycle_time = t * z + y;
	int remain_time = min(time % cycle_time, t * z);
	return (time / cycle_time) * z + remain_time / t;
}

bool good(int m, int n, int* t, int* z , int* y, int time) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		k += compute_count_balls(t[i], z[i], y[i], time);
		if (k >= m) {
		    return true;
		}
	}
	return k >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	int* t = new int[n];
	int* z = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> z[i] >> y[i];
	}
	int left = -1;
	int right = 1;
	while (!good(m, n, t, z, y, right)) {
		right *= 2;
	}
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (good(m, n, t, z, y, mid)) {
			right = mid;
		}
		else {
			left = mid;
		}
	}
	cout << right << '\n';
	int remaining_m = m;
	for (int i = 0; i < n; i++) {
		int can_inflate = compute_count_balls(t[i], z[i], y[i], right);
		int actual_inflated = min(remaining_m, can_inflate); 
		cout << actual_inflated << ' ';
		remaining_m -= actual_inflated;
	}
	delete [] t;
	delete [] z;
	delete [] y;
}