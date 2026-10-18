#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> k;
        vector<float> stack;
        stack.reserve(k);
        float num;
        bool flag = true;
        float tail = -INFINITY;
        cin >> num;
        stack.push_back(num);
        for (int j = 1; j < k; j++) {
        	cin >> num;
            if (num <= stack.back()) {
            	stack.push_back(num);
            }
            else {
            	int ind = stack.size() - 1;
                for (; ind >= 0; ind--) {
                	if (stack[ind] >= num) {
                	    break;
                    }
                	if (stack[ind] >= tail) {
                	    tail = stack[ind];
                    }
                    else {
                    	flag = false;
                        break;
                    }
                }
                stack.resize(ind + 1);
                stack.push_back(num);
            }
        }
        if (flag) {
        	if (stack.back() >= tail || tail == -INFINITY) {
        	    cout << "1\n";
            }
            else {
	        	cout << "0\n";
	        }
        }
        else {
        	cout << "0\n";
	    }
    }
}