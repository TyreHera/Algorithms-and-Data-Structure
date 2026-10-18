#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	char buffer;
	stack<int> my_stack;
	while (cin >> buffer) {
		if (!isdigit(buffer)) {
			int b = my_stack.top();
			my_stack.pop(); 
			int a = my_stack.top();
			my_stack.pop();
			int res;
			if (buffer == '+') {
				res = a + b;
			}
			else if (buffer == '-') {
				res = a - b;
			}
			else if (buffer == '*') {
				res = a * b;
			}
			my_stack.push(res);
		}
		else {
			my_stack.push(buffer - '0');
		}
	}
	cout << my_stack.top();
}