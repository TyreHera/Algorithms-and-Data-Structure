#include <iostream>
#include <vector>
#include <utility>

int BubbleSort(int n, std::vector<int>& arr) {
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                cnt++;
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int swaps_count = BubbleSort(n, arr);
    std::cout << swaps_count << "\n";

    return 0;
}
