class Node:
	def __init__(self, data = None):
		self.data = data
		self.parent = None
		self.left = None
		self.right = None
		self.color = "RED"

class RedBlackTree:
	def __init__(self):
		self.NIL = Node()
		self.NIL.color = "BLACK"
		self.NIL.left = self.NIL
		self.NIL.right = self.NIL
		self.root = self.NIL
	
	
	def find(self, data):
		node = self.root
		while node != self.NIL:
			if node.data == data:
				return True
			elif data < node.data:
				node = node.left
			else:
				node = node.right
		return False
			
	
	def insert(self, data):
		new_node = Node(data)
		new_node.left = self.NIL
		new_node.right = self.NIL
		if self.root == self.NIL:
			self.root = new_node
			self.root.color = "BLACK"
			return
		node = self.root
		y = None
		while node != self.NIL:
			y = node
			if data < node.data:
				node = node.left
			else:
				node = node.right
		new_node.parent = y
		if data < y.data:
			y.left = new_node
		else:
			y.right = new_node
		
		if y.color == "RED":
			self.fix_insert(new_node)
	
	
	def fix_insert(self, node):
		while node.parent.color == "RED":
			father = node.parent
			grandpa = father.parent
			if grandpa.left == father:
				uncle = grandpa.right
				if uncle.color == "RED":
					grandpa.color = "RED"
					father.color = "BLACK"
					uncle.color = "BLACK"
					node = grandpa
				else:
					if father.left == node:
						self.right_rotate(grandpa)
						father.color = "BLACK"
						grandpa.color = "RED"
					else:
						self.left_rotate(father)
						self.right_rotate(grandpa)
						node.color = "BLACK"
						grandpa.color = "RED"
					break
			else:
				uncle = grandpa.left
				if uncle.color == "RED":
					grandpa.color = "RED"
					father.color = "BLACK"
					uncle.color = "BLACK"
					node = grandpa
				else:
					if father.right == node:
						self.left_rotate(grandpa)
						father.color = "BLACK"
						grandpa.color = "RED"
					else:
						self.right_rotate(father)
						self.left_rotate(grandpa)
						node.color = "BLACK"
						grandpa.color = "RED"
					break
			if node == self.root:
				break
		self.root.color = "BLACK"
	
				
	def right_rotate(self, x):
		y = x.left
		x.left = y.right
		if y.right != self.NIL:
			y.right.parent = x
		y.right = x
		y.parent = x.parent
		if x.parent is None:
			self.root = y
		elif x.parent.right == x:
			x.parent.right = y
		else:
			x.parent.left = y
		x.parent = y
		
	def left_rotate(self, x):
		y = x.right
		x.right = y.left
		if y.left != self.NIL:
			y.left.parent = x
		y.left = x
		y.parent = x.parent
		if x.parent is None:
			self.root = y
		elif x.parent.right == x:
			x.parent.right = y
		else:
			x.parent.left = y
		x.parent = y
		
		
	def transplant(self, x, y):
		if x.parent is None:
			self.root = y
		elif x.parent.left == x:
			x.parent.left = y
		else:
			x.parent.right = y
		y.parent = x.parent
		
		
	def delete(self, data):
		node = self.root
		while node != self.NIL:
			if data == node.data:
				break
			if data < node.data:
				node = node.left
			else:
				node = node.right
		else:
			return
		original_color = node.color
		balance = self.NIL
		if node.left == self.NIL:
			balance = node.right
			self.transplant(node, node.right)
		elif node.right == self.NIL:
			balance = node.left
			self.transplant(node, node.left)
		else:
			max_node = node.left
			while max_node.right != self.NIL:
				max_node = max_node.right
			original_color = max_node.color
			balance = max_node.left
			if node.left == max_node:
				balance.parent = max_node
			else:
				self.transplant(max_node, max_node.left)
				max_node.left = node.left
				max_node.left.parent = max_node
			self.transplant(node, max_node)
			max_node.right = node.right
			max_node.right.parent = max_node
			max_node.color = node.color
		
		if original_color == "BLACK":
			self.fix_delete(balance)
			
			
	def fix_delete(self, node):
		while node != self.root and node.color == "BLACK":
			father = node.parent
			if father.left == node:
				brother = father.right
				if brother.color == "RED":
					brother.color = "BLACK"
					father.color = "RED"
					self.left_rotate(father)
					brother = father.right
				if brother.left.color == "BLACK" and brother.right.color == "BLACK":
					brother.color = "RED"
					node = father
				else:
					if brother.right.color == "BLACK":
						brother.color = "RED"
						brother.left.color = "BLACK"
						self.right_rotate(brother)
						brother = father.right
					brother.color = father.color
					father.color = "BLACK"
					brother.right.color = "BLACK"
					self.left_rotate(father)
					node = self.root
			else:
				brother = father.left
				if brother.color == "RED":
					brother.color = "BLACK"
					father.color = "RED"
					self.right_rotate(father)
					brother = father.left
				if brother.left.color == "BLACK" and brother.right.color == "BLACK":
					brother.color = "RED"
					node = father
				else:
					if brother.left.color == "BLACK":
						brother.right.color = "BLACK"
						brother.color = "RED"
						self.left_rotate(brother)
						brother = father.left
					brother.color = father.color
					father.color = "BLACK"
					brother.left.color = "BLACK"
					self.right_rotate(father)
					node = self.root
		node.color = "BLACK"
		
		
	def inorder(self, node):
		if node == self.NIL:
			return "|"
		if node == self.root:
			return f"{self.inorder(node.left)} Корень:({node.data})[{node.color}] {self.inorder(node.right)}"
		return f"{self.inorder(node.left)} ({node.data})[{node.color}] {self.inorder(node.right)}"
			
			
	def __str__(self):
		return self.inorder(self.root)