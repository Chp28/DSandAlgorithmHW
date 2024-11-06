#include <iostream>
#include "AvlTree.h"
using namespace std;

void testAvlTree() {
	AvlTree<int> bst;
	bst.insert(10);
	bst.insert(5);
	bst.insert(15);
	bst.insert(3);
	bst.insert(7);
	bst.insert(12);
	bst.insert(18);
	bst.insert(11);
	bst.insert(13);
	bst.insert(14);
	bst.insert(19);
	bst.insert(2);
	cout << "Initial Tree" << endl;
	bst.printTree();
	
	bst.remove(10);
	cout << "Tree after removing 10:" << endl;
	bst.printTree();
}

int main(){
	testAvlTree();
	return 0;
}
