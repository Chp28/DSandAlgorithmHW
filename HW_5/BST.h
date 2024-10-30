#include <iostream>

class UnderflowException { };
class IllegalArgumentException { };
class ArrayIndexOutOfBoundsException { };
class IteratorOutOfBoundsException { };
class IteratorMismatchException { };
class IteratorUninitializedException { };

template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree() : root{ nullptr } {}
	BinarySearchTree(const BinarySearchTree &rhs) : root{ clone(rhs.root) } {}
	BinarySearchTree(BinarySearchTree &&rhs) noexcept : root{ rhs.root } {
		rhs.root = nullptr;
	}
	~BinarySearchTree() {
		makeEmpty();
	}
	const Comparable &findMin() const {
		if( isEmpty() )
			throw UnderflowException{ };
		return findMin(root)->element;
	}
	const Comparable &findMax() const {
		if( isEmpty() )
			throw UnderflowException{ };
		return findMax(root)->element;
	} 
	bool contains(const Comparable &x) const {
		return contains(x,root);
	}
	bool isEmpty() const {
		return root == nullptr;
	}
	void printTree(std::ostream &out = std::cout) const {
		if(isEmpty()) {
			out << "Empty tree" << std::endl;
		}else{
			printTree(root, out);
		}
	}
	void makeEmpty() {
		makeEmpty(root);
	}
	void insert(const Comparable &x) {
		insert(x, root);
	}
	void insert(Comparable &&x) {
		insert(std::move(x), root);
	}
	void remove(const Comparable &x) {
		remove(x, root);
	}
	BinarySearchTree &operator=(const BinarySearchTree &rhs){
		if(this != &rhs){
			BinarySearchTree temp(rhs);
			std::swap(root, temp.root);
		}
		return *this;
	}
	BinarySearchTree &operator=(BinarySearchTree &&rhs) noexcept {
		std::swap(root, rhs.root);
		return *this;
	}
private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt) : element{theElement}, left{lt}, right{rt} {}
	};
	BinaryNode *root;
	BinaryNode  *findMin(BinaryNode *t) const {
		if(t==nullptr) {
			return nullptr;
		}
		if(t->left==nullptr){
			return t;
		}
		return findMin(t->left);
	}
	BinaryNode *findMax(BinaryNode *t) const{
		if(t!=nullptr){
			while(t->right != nullptr){
				t = t->right;
			}
		}
		return t;
	}
	bool contains(const Comparable &x, BinaryNode *t) const{
		if(t==nullptr) {
			return false;
		}
		if(x < t->element){
			return contains(x, t->left);
		}
		else if(x > t->element){
			return contains(x, t->right);
		}
		else{
			return true;
		}
	}
	void printTree(BinaryNode *t, std::ostream &out) const {
		if(t!=nullptr){
			printTree(t->left, out);
			out << t->element << std::endl;
			printTree(t->right, out);
		}
	}
	void makeEmpty(BinaryNode * &t){
		if(t!=nullptr){
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
			t = nullptr;
		}
	}
	void insert(const Comparable &x,BinaryNode * &t){
		if(t==nullptr){
			t = new BinaryNode{x,nullptr,nullptr};
		}else if(x < t->element){
			insert(x,t->left);
		}else if(x > t->element){
			insert(x,t->right);
		}else{}
	}
	void insert(Comparable &&x,BinaryNode * &t) {
		if(t==nullptr){
			t = new BinaryNode{std::move(x),nullptr,nullptr};
		}else if(x < t->element){
			insert(std::move(x),t->left);
		}else if(x > t->element){
			insert(std::move(x),t->right);
		}else{}
	}
	BinaryNode* detachMin(BinaryNode* &t){
		BinaryNode* parent = t;
		BinaryNode* cur = t->right;
		while(cur->left != nullptr){
			parent = cur;
			cur = cur->left;
		}
		parent->left = cur->right;
		cur->left = t->left;
		cur->right = t->right;
		delete t;
		return cur;
	}
	void remove(const Comparable &x, BinaryNode * &t){
		if(t==nullptr){
			return;
		}
		if(x < t->element){
			remove(x,t->left);
		}else if(x > t->element){
			remove(x,t->right);
		}
		else if(t->left !=nullptr && t->right !=nullptr){
			t = detachMin(t);
		}else{
			BinaryNode *oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete oldNode;
		}
	}
	BinaryNode *clone(BinaryNode *t) const{
		if(t==nullptr) {
			return nullptr;
		}
		return new BinaryNode{t->element, clone(t->left), clone(t->right)};
	}
};


