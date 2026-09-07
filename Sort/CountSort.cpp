#include <iostream>
#include <vector>

void CountSort(std::vector<int> &arr) {
	int count[100] = {0};

    for (int num : arr) {
        count[num]++;
    }

    int index = 0;

    for (int num = 0; num <= 100; num++) {
        while (count[num] > 0) {
            arr[index] = num;
            index++;
            count[num]--;
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
    
    CountSort(arr);

    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 == arr.size() ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}