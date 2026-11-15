#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* parent;
    unique_ptr<Node> left, right;
	
	Node(const T& data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
	unique_ptr<Node<T>> root;
	
public:
	BinarySearchTree() : root(nullptr) {}
	~BinarySearchTree() = default;
	
	int insert(const T& data) {
		if (!root) {
            root = make_unique<Node<T>>(data);
            return 0;
        }
		Node<T>* node = root.get();
		Node<T>* parent_node = nullptr;
		while (node != nullptr) {
			parent_node = node;
			if (data < node->data) {
				node = node->left.get();
			}
			else if (data > node->data) {
				node = node->right.get();
			}
			else {
				return 1;
			}
		}
		auto new_node = make_unique<Node<T>>(data);
		new_node->parent = parent_node;
		if (parent_node->data > data) {
			parent_node->left = move(new_node);
		}
		else {
			parent_node->right = move(new_node);
		}
		return 0;
	}
	
	T next(const T& i) {
		Node<T>* temp = root.get();
		Node<T>* min_node = nullptr;
		while (temp != nullptr) {
			if (temp->data >= i) {
				min_node = temp;
				temp = temp->left.get();
			}
			else {
				temp = temp->right.get();
			}
		}
		if (min_node == nullptr) {
			return -1;
		}
		return min_node->data;
	}
	
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	BinarySearchTree<int> tree = BinarySearchTree<int>();
	int n, temp;
	bool flag = false;
	char buffer[1024];
	cin >> n;
	cin.ignore();
	for (int k = 0; k < n; k++) {
        cin.getline(buffer, sizeof(buffer));
    	if (buffer[0] == '+') {
    	    if (!flag) {
    	        tree.insert(strtoll(buffer + 2, nullptr, 10));
            }
            else {
            	tree.insert((strtoll(buffer + 2, nullptr, 10) + temp) % 1000000000);
                flag = false;
            }
        }
        else if (buffer[0] == '?') {
        	temp = tree.next(strtoll(buffer + 2, nullptr, 10));
            cout << temp << '\n';
            flag = true;
        }
    }
}