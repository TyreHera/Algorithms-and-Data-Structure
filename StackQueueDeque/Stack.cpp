#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

class Stack {
private:
    vector<int> arr;

public:
    void push(int n) {
    	arr.push_back(n);
    }
    
    void pop() {
    	arr.pop_back();
    }
    
    int back() {
    	return arr.back();
    }
    
    uint size() {
    	return arr.size();
    }
    
    void clear() {
    	arr.clear();
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char buffer[1024];
    Stack stack = Stack();
    while (cin.getline(buffer, sizeof(buffer))) {
    	if (strstr(buffer, "push") != nullptr) {
    	    stack.push(strtoll(buffer + 5, nullptr, 10));
            cout << "ok\n";
        }
        else if (strstr(buffer, "pop") != nullptr) {
        	if (stack.size() == 0) {
                cout << "error\n";
            }
            else {
            	cout << stack.back() << "\n";
                stack.pop();
            }
        }
        else if (strstr(buffer, "back") != nullptr) {
            if (stack.size() == 0) {
                cout << "error\n";
            }
            else cout << stack.back() << "\n";
        }
        else if (strstr(buffer, "size") != nullptr) {
            cout << stack.size() << "\n";
        }
        else if (strstr(buffer, "clear") != nullptr) {
            stack.clear();
            cout << "ok\n";
        }
        else if (strstr(buffer, "exit") != nullptr) {
            cout << "bye\n";
            return 0;
        }
        else {
        	return 1;
        }
    }
}
