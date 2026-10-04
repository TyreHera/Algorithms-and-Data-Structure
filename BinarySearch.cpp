#include <iostream>

using namespace std;

bool binary_search(int* arr, int num, int l, int r) {
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] == num) {
            return true;
        }
        if (arr[mid] < num) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return false;
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
        if (binary_search(arr_n, arr_k[i], -1, n)) 
            cout << "YES\n";
        else cout << "NO\n";
    }
    delete [] arr_n;
    delete [] arr_k;
}
