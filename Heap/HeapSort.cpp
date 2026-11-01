#include <iostream>
#include <vector>

using namespace std;

void balance_down(int* arr, int n, int ind) {
	while (ind*2 <= n) {
		int temp;
		if (ind*2 == n) {
			temp = ind*2;
		}
		else if (arr[ind*2 - 1] > arr[ind*2]) {
			temp = ind*2;
		}
		else temp = ind*2 + 1;
		if (arr[ind - 1] < arr[temp - 1]) {
			swap(arr[ind - 1], arr[temp - 1]);
			ind = temp;
		}
		else break;
	}
}

void heap_sort(int* arr, int n) {
	for (int i = n/2; i > 0; i--) {
		balance_down(arr, n, i);
	}
	
	for (int i = 1; i < n; i++) {
		swap(arr[0], arr[n - i]);
		balance_down(arr, n-i, 1);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    heap_sort(arr, n);
    for (int i = 0; i < n; i++) {
    	cout << arr[i] << ' ';
    }
    delete [] arr;
}