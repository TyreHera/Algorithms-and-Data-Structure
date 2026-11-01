#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
	vector<int> arr;
	
	int ind_max(int ind) {
		if (ind*2 == arr.size()) {
			return ind*2;
		}
		if (arr[ind*2 - 1] > arr[ind*2]) {
			return ind*2;
		}
		return ind*2 + 1;
	}
	
	void balance_up(int ind) {
		while (ind > 1) {
			if (arr[ind/2 - 1] < arr[ind - 1]) {
				swap(arr[ind/2 - 1], arr[ind - 1]);
				ind = ind / 2;
			}
			else {
				break;
			}
		}
	}
	
	void balance_down(int ind) {
		while (ind*2 <= arr.size()) {
			int temp = ind_max(ind);
			if (arr[ind - 1] < arr[temp - 1]) {
				swap(arr[ind - 1], arr[temp - 1]);
				ind = temp;
			}
			else {
				break;
			}
		}
	}
	
public:
	void insert(int k) {
		arr.push_back(k);
		balance_up(arr.size());
	}
	
	int extract() {
		int maximum = arr[0];
		swap(arr[0], arr.back());
		arr.pop_back();
		balance_down(1);
		return maximum;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Heap heap = Heap();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int command, num;
        cin >> command;
        if (command == 0) {
        	cin >> num;
            heap.insert(num);
        }
        else if (command == 1) {
        	cout << heap.extract() << '\n';
        }
    }
}
