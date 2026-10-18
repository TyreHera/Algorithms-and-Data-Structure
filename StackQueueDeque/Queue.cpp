#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node* next;
	
	Node(const int data) : data(data), next(nullptr) {}
	Node(const int data, Node* next) : data(data), next(next) {}
};

class Queue {
private:
	Node *head, *tail;
	uint length;
	
public:
	Queue() : head(nullptr), tail(nullptr), length(0) {}
	~Queue() {clear();}
	const uint size() const {return length;}
	void push(int n) {
		length++;
		if (!head) {head = tail = new Node(n); return;}
		tail->next = new Node(n);
		tail = tail->next;
	}
	void pop() {
		if (length == 0) return;
		if (length == 1) {length = 0; delete head; head = tail = nullptr; return;}
		Node* temp = head;
		length--;
		head = head->next;
		delete temp;
		if (length == 0) tail = nullptr;
		return;
	}
	int front() {return head->data;}
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
	Queue queue = Queue();
	char buffer[1024];
    while (cin.getline(buffer, sizeof(buffer))) {
    	if (strstr(buffer, "push") != nullptr) {
    	    queue.push(strtoll(buffer + 5, nullptr, 10));
            cout << "ok\n";
        }
        else if (strstr(buffer, "pop") != nullptr) {
        	if (queue.size() == 0) {
                cout << "error\n";
            }
            else {
            	cout << queue.front() << "\n";
                queue.pop();
            }
        }
        else if (strstr(buffer, "front") != nullptr) {
            if (queue.size() == 0) {
                cout << "error\n";
            }
            else cout << queue.front() << "\n";
        }
        else if (strstr(buffer, "size") != nullptr) {
            cout << queue.size() << "\n";
        }
        else if (strstr(buffer, "clear") != nullptr) {
            queue.clear();
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