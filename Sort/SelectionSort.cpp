#include <iostream>
#include <vector>
#include <string>
#include <utility>

void SelectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[ind]) {
                ind = j;
            }
        }
        if (ind != i) {
            std::swap(arr[i], arr[ind]);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> arr;
    int num;

    while (std::cin >> num) {
        arr.push_back(num);
    }
    
    SelectionSort(arr);

    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 == arr.size() ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
