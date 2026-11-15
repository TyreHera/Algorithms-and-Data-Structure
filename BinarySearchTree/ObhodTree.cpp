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
	
	void print_node(Node<T>* node) {
		if (node == nullptr) {
			return;
		}
		print_node(node->left.get());
		cout << node->data << '\n';
		print_node(node->right.get());
	}
	
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