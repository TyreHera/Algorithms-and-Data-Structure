#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node {
	unique_ptr<Node> left, right;
	Node* parent;
	int count;
	T data;
	
	Node(T data) : left(nullptr), right(nullptr), parent(nullptr), count(1), data(move(data)) {}
};

template <typename T>
class BinarySearchTree {
private:
	unique_ptr<Node<T>> root;
	
	void print_node(Node<T>* node) {
		if (node == nullptr) {
			return;
		}
		print_node(node->left.get());
		cout << node->data << ' ' << node->count << '\n';
		print_node(node->right.get());
	}
	
public:
	BinarySearchTree() : root(nullptr) {}
	~BinarySearchTree() = default;
	
	void insert(T data) {
		if (!root) {
            root = make_unique<Node<T>>(move(data));
            return;
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
				node->count++;
				break;
			}
		}
		auto new_node = make_unique<Node<T>>(move(data));
		new_node->parent = parent_node;
		if (parent_node->data > data) {
			parent_node->left = move(new_node);
		}
		else if (parent_node->data < data) {
			parent_node->right = move(new_node);
		}
	}
	
	void print() {
		print_node(root.get());
	}
	
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	BinarySearchTree<int> tree = BinarySearchTree<int>();
	int num;
	while (cin >> num) {
		if (num == 0) {
			break;
		}
		tree.insert(num);
	}
	tree.print();
}