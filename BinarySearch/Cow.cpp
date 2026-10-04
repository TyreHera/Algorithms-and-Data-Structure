#include <iostream>

using namespace std;

bool good(int* boxes, int num_boxes, int cows, int distance) {
	int k = 1;
	int last_box = boxes[0];
	for (int i = 1; i < num_boxes; i++) {
		if (last_box + distance <= boxes[i]) {
			last_box = boxes[i];
			k++;
		}
	}
	return k >= cows;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int* boxes = new int[n];
	for (int i = 0; i < n; i++)
		cin >> boxes[i];
	
	int left = 0;
	int right = boxes[n-1] - boxes[0] + 1;
	int dist;
	while (left + 1 < right) {
		dist = (left + right) / 2;
		if (good(boxes, n, k, dist)) {
			left = dist;
		}
		else right = dist;
	}
	cout << left;
	delete [] boxes;
}