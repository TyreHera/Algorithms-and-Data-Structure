#include <iostream>
#include <algorithm>

using namespace std;

int* get_occurrence_counts(int* arr_n, int n, int* arr_m, int m) {
	int* occ = new int[m];
	for (int i = 0; i < m; i++) {
		int left = -1;
		int right = n;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (arr_n[mid] < arr_m[i]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		if ((right == n) || (arr_n[right] != arr_m[i])) {
		    occ[i] = 0;
		    continue;
		}
		occ[i] = -right;
		left = -1;
		right = n;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (arr_n[mid] <= arr_m[i]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		occ[i] += left + 1;
	}
	return occ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n;
	int* arr_n = new int[n];
	for (int i = 0; i < n; i++) 
		cin >> arr_n[i];
	cin >> m;
	int* arr_m = new int[m];
	for (int i = 0; i < m; i++) 
		cin >> arr_m[i];
	sort(arr_n, arr_n + n);
	int* occ = get_occurrence_counts(arr_n, n, arr_m, m);
	for (int i = 0; i < m; i++) 
		cout << occ[i] << " ";
	delete [] arr_n;
	delete [] arr_m;
	delete [] occ;
}