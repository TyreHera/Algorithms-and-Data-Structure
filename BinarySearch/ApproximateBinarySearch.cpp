#include <iostream>

using namespace std;

int approximate_binary_search(int* arr, int num, int start, int end) {
    int l = start - 1;
    int r = end + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] == num) {
            return arr[mid];
        }
        if (arr[mid] < num) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
   if (l == start - 1) l = start;
   if (r == end + 1) r = end;
    if (num - arr[l] <= arr[r] - num) 
    	return arr[l];
    return arr[r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    cin >> k;
    int* arr_n = new int[n];
    int* arr_k = new int[k];
    for (int i = 0; i < n; i++)
        cin >> arr_n[i];
    for (int i = 0; i < k; i++)
        cin >> arr_k[i];
    
    for(int i = 0; i < k; i++) {
        cout << approximate_binary_search(arr_n, arr_k[i], 0, n-1) << '\n';
    }
    delete [] arr_n;
    delete [] arr_k;
}
