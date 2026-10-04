#include <iostream>

using namespace std;

bool good(int* wires, int num_wires, int count, int len) {
	int k = 0;
	for (int i = 0; i < num_wires; i++) {
		k += wires[i] / len;
	}
	return k >= count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int* wires = new int[n];
	for (int i = 0; i < n; i++)
		cin >> wires[i];
		
	int left = 0;
	int right = 10000001;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (good(wires, n, k, mid)) {
			left = mid;
		}
		else right = mid;
	}
	cout << left;
	delete [] wires;
}