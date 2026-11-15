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
	
	int height_node(Node<T>* node) {
		if (node == nullptr) {
			return 0;
		}
		return 1 + max(height_node(node->left.get()), height_node(node->right.get()));
	}
	
	bool is_balance_node(Node<T>* node) {
		if (node == nullptr) {
			return true;
		}
		bool condition1 = abs(height_node(node->left.get()) - height_node(node->right.get())) <= 1;
		bool condition2 = is_balance_node(node->left.get()) && is_balance_node(node->right.get());
		return condition1 && condition2;
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
	
	bool is_balance() {
		return is_balance_node(root.get());
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
	if (tree.is_balance()) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}