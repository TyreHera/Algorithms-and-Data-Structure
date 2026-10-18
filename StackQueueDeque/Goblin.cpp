#include <iostream>
#include <deque>

using namespace std;

void balance(deque<int>& left, deque<int>& right) {
	if (left.size() < right.size()) {
		left.push_back(right.front());
		right.pop_front();
	}
	if (left.size() > right.size() + 1) {
		right.push_front(left.back());
		left.pop_back();
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> left;
    deque<int> right;
    int n;
    cin >> n;
    char op;
	for (int i = 0; i < n; i++) {
	    cin >> op;
	    if (op == '+' || op == '*') {
	        int id;
	        cin >> id; 
	        if (op == '+') {
	            right.push_back(id);
	        } else {
	            right.push_front(id);
	        }
	        balance(left, right);
	    } else if (op == '-') {
	        cout << left.front() << '\n';
	        left.pop_front();
	        balance(left, right);
	    }
	}
}
