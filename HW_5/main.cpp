#include <iostream>
#include "BST.h"
using namespace std;

void testBinarySearchTree() {
	BinarySearchTree<int> bst;
	bst.insert(10);
	bst.insert(5);
	bst.insert(15);
	bst.insert(3);
	bst.insert(7);
	bst.insert(12);
	bst.insert(18);
	bst.insert(11);
	bst.insert(13);
	cout << "Initial Tree" << endl;
	bst.printTree();
	
	cout << "Minimum element: " << bst.findMin() << endl;
	cout << "Maximum element: " << bst.findMax() << endl;
	
	cout << "Contains 7? " << (bst.contains(7) ? "Yes" : "No") << endl;
	cout << "Contains 20? " << (bst.contains(20) ? "Yes" : "No") << endl;
	
	bst.remove(10);
	cout << "Tree after removing 10:" << endl;
	bst.printTree();
	
	bst.remove(11);
	cout << "Tree after removing 11:" << endl;
	bst.printTree();
	
	bst.makeEmpty();
	cout << "Tree after making empty:" << endl;
	bst.printTree();
	
	cout << "Is tree empty? " << (bst.isEmpty() ? "Yes":"No") << endl;
	
	BinarySearchTree<int> bst2;
	bst2.insert(1);
	bst2.insert(3);
	bst2.insert(2);
	
	BinarySearchTree<int> bst3(bst2);
	cout << "Copied Tree (bst3):" << endl;
	bst3.printTree();
	
	BinarySearchTree<int> bst4;
	bst4 = bst2;
	cout << "Assigned Tree (bst4):" << endl;
	bst4.printTree();
	
	BinarySearchTree<int> bst5(move(bst2));
	cout << "Moved Tree (bst5):" << endl;
	bst5.printTree();
	
	BinarySearchTree<int> bst6;
	bst6 = move(bst5);
	cout << "Move Assigned Tree (bst6):" << endl;
	bst6.printTree();
	
	BinarySearchTree<int> bst7;
	bst7.findMax();
}

int main(){
	testBinarySearchTree();
	return 0;
}


