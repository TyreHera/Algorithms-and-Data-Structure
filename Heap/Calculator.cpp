#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	long long num;
        cin >> num;
        heap.push(num);
    }
    long long sum = 0;
    while (heap.size() > 1) {
    	long long a = heap.top(); heap.pop();
        long long b = heap.top(); heap.pop();
        sum += (a + b);
        heap.push(a + b);
    }
    double cost = sum * 0.05;
    cout << fixed << setprecision(2) << cost << "\n";

    return 0;
}