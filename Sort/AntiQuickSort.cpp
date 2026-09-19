#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
    	arr[i] = i+1;
    }
    
    for (int i = 2; i < n; i++) {
    	swap(arr[i], arr[i/2]);
    }
    
    for (int i = 0; i < n; i++) {
    	cout << arr[i] << " ";
    }
    
    return 0;
}
