#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string buffer;
	cin >> buffer;
	int len = buffer.size();
	stack<char> my_stack;
	for (int i = 0; i < len; i++) {
		if (buffer[i] % 4 != 1) {
			my_stack.push(buffer[i]);
			continue;
		}
		if ((my_stack.size() != 0) && (((buffer[i] == ')') && (my_stack.back() == '(')) ||
                                                     ((buffer[i] == '}') && (my_stack.back() == '{')) ||
                                                     ((buffer[i] == ']') && (my_stack.back() == '[')))) {
            my_stack.pop();
            continue;
        }
        else {
        	cout << "no";
            return 0;
        }
	}
	if (my_stack.size() == 0)
	    cout << "yes";
	else cout << "no";
	return 0;
}