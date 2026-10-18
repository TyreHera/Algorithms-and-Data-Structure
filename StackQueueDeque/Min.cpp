#include <iostream>

using namespace std;

int arr[150000];
int deque[150000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int head = 0;
    int tail = 0;
    
    for (int i = 0; i < n; i++) {
        if (head < tail && deque[head] <= i - k) {
            head++;
        }

        while (head < tail && arr[deque[tail - 1]] >= arr[i]) {
            tail--;
        }

        deque[tail++] = i;

        if (i >= k - 1) {
            cout << arr[deque[head]] << '\n';
        }
    }
    return 0;
}
