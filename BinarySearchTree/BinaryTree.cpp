#include <iostream>
#include <memory>
#include <cstring>
#include <cstdlib>

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
	
	unique_ptr<Node<T>> transplant (Node<T>* x, unique_ptr<Node<T>>& y) {
		if (y != nullptr) {
			y->parent = x->parent;
		}
		unique_ptr<Node<T>> removed;
		if (x->parent == nullptr) {
			removed = move(root);
			root = move(y);
		}
		else if (x->parent->left.get() == x) {
			removed = move(x->parent->left);
			x->parent->left = move(y);
		}
		else {
			removed = move(x->parent->right);
			x->parent->right = move(y);
		}
		return removed;
	}
	
	void print_tree(Node<T>* node, int level) {
		if (node == nullptr) {
			return;
		}
		print_tree(node->left.get(), level+1);
		for (int i = 0; i < level; i++) {
			cout << '.';
		}
		cout << node->data << '\n';
		print_tree(node->right.get(), level+1);
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
	
	int erase(const T& data) {
		Node<T>* node = root.get();
		while (node != nullptr && node->data != data) {
			if (data < node->data) {
				node = node->left.get();
			}
			else {
				node = node->right.get();
			}
		}
		if (node == nullptr) {
			return 1;
		}
		if (node->left == nullptr) {
			auto garbage = transplant(node, node->right);
		}
		else if (node->right == nullptr) {
			auto garbage = transplant(node, node->left);
		}
		else {
			Node<T>* max_node = node->left.get();
			while (max_node->right != nullptr) {
				max_node = max_node->right.get();
			}
			unique_ptr<Node<T>> moved_max;
			if (node->left.get() != max_node) {
				moved_max = transplant(max_node, max_node->left);
				max_node->left = move(node->left);
				max_node->left->parent = max_node;
			}
			else {
				moved_max = move(node->left);
			}
			max_node->right = move(node->right);
			if (max_node->right != nullptr) {
				max_node->right->parent = max_node;
			}
			auto garbage = transplant(node, moved_max);
		}
		return 0;
	}
	
	bool find(const T& data) {
		Node<T>* node = root.get();
		while (node != nullptr) {
			if (node->data == data) {
				return true;
			}
			else if (data < node->data) {
				node = node->left.get();
			}
			else {
				node = node->right.get();
			}
		}
		return false;
	}
	
	void print() {
		print_tree(root.get(), 0);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	BinarySearchTree<int> tree = BinarySearchTree<int>();
	char buffer[1024];
    while (cin.getline(buffer, sizeof(buffer))) {
    	if (strstr(buffer, "ADD") != nullptr) {
    	    if (tree.insert(strtoll(buffer + 4, nullptr, 10)) == 0) {
    	        cout << "DONE\n";
    	    }
            else {
            	cout << "ALREADY\n";
            }
        }
        else if (strstr(buffer, "DELETE") != nullptr) {
        	if (tree.erase(strtoll(buffer + 7, nullptr, 10)) == 0) {
    	        cout << "DONE\n";
    	    }
            else {
            	cout << "CANNOT\n";
            }
        }
        else if (strstr(buffer, "SEARCH") != nullptr) {
            if (tree.find(strtoll(buffer + 7, nullptr, 10))) {
    	        cout << "YES\n";
    	    }
            else {
            	cout << "NO\n";
            }
        }
        else if (strstr(buffer, "PRINTTREE") != nullptr) {
            tree.print();
        }
    }
}
