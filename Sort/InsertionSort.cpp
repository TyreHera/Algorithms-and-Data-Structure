#include <iostream>
#include <vector>
#include <string>

void InsertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i;
        while (j >= 1 && arr[j - 1] > key) {
            arr[j] = arr[j-1];
            j -= 1;
        }
        arr[j] = key;
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

    InsertionSort(arr);

    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 == arr.size() ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
