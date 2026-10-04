#include <iostream>

using namespace std;

bool good(int* ropes, int num_ropes, int houses, int len) {
	int k = 0;
	for (int i = 0; i < num_ropes; i++) {
		k += ropes[i] / len;
	}
	return k >= houses;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int* ropes = new int[n];
	for (int i = 0; i < n; i++)
		cin >> ropes[i];
		
	int left = 0;
	int right = 10000001;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (good(ropes, n, k, mid)) {
			left = mid;
		}
		else right = mid;
	}
	cout << left;
	delete [] ropes;
}