#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* previous;
	
	Node(const int data) : data(data), next(nullptr), previous (nullptr) {}
	Node(const int data, Node* next, Node* previous) : data(data), next(next), previous(previous) {}
};

class Deque {
private:
	Node *head, *tail;
	uint length;
	
public:
	Deque() : head(nullptr), tail(nullptr), length(0) {}
	~Deque() {clear();}
	const uint size() const {return length;}
	void push_back(int n) {
		length++;
		if (!head) {head = tail = new Node(n); return;}
		tail->next = new Node(n, nullptr, tail);
		tail = tail->next;
	}
	void push_front(int n) {
		length++;
		if (!head) {head = tail = new Node(n); return;}
		head->previous = new Node(n, head, nullptr);
		head = head->previous;
	}
	void pop_front() {
		if (length == 0) return;
		if (length == 1) {length = 0; delete head; head = tail = nullptr; return;}
		Node* temp = head;
		length--;
		head = head->next;
		head->previous = nullptr;
		delete temp;
		if (length == 0) tail = nullptr;
		return;
	}
	void pop_back() {
		if (length == 0) return;
		if (length == 1) {length = 0; delete head; head = tail = nullptr; return;}
		Node* temp = tail;
		length--;
		tail = tail->previous;
		tail->next = nullptr;
		delete temp;
		if (length == 0) tail = nullptr;
		return;
	}
	int front() {return head->data;}
	int back() {return tail->data;}
	void clear() {
		for (uint i = 0; i < length; i++){
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		head = tail = nullptr;
		length = 0;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	Deque deque = Deque();
	char buffer[4096];
    while (cin.getline(buffer, sizeof(buffer))) {
    	if (strstr(buffer, "push_front") != nullptr) {
    	    deque.push_front(strtoll(buffer + 11, nullptr, 10));
            cout << "ok\n";
        }
        else if (strstr(buffer, "push_back") != nullptr) {
    	    deque.push_back(strtoll(buffer + 10, nullptr, 10));
            cout << "ok\n";
        }
        else if (strstr(buffer, "pop_front") != nullptr) {
        	if (deque.size() == 0) {
                cout << "error\n";
            }
            else {
            	cout << deque.front() << "\n";
                deque.pop_front();
            }
        }
        else if (strstr(buffer, "pop_back") != nullptr) {
        	if (deque.size() == 0) {
                cout << "error\n";
            }
            else {
            	cout << deque.back() << "\n";
                deque.pop_back();
            }
        }
        else if (strstr(buffer, "front") != nullptr) {
            if (deque.size() == 0) {
                cout << "error\n";
            }
            else cout << deque.front() << "\n";
        }
        else if (strstr(buffer, "back") != nullptr) {
            if (deque.size() == 0) {
                cout << "error\n";
            }
            else cout << deque.back() << "\n";
        }
        else if (strstr(buffer, "size") != nullptr) {
            cout << deque.size() << "\n";
        }
        else if (strstr(buffer, "clear") != nullptr) {
            deque.clear();
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