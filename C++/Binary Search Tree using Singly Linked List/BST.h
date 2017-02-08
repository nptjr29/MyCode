#ifndef BST_H
#define BST_H

#include <string>		
#include <iostream>
#include <stack>
using namespace std;

class Node
{
	friend class BST;
public:
	Node(){}
	~Node(){}
private:
    int data;
    Node *rlink, *llink;
};

class BST
{
public:

	BST();
		//Default constructor

	~BST();   
		//Destructor  

    void destroyTree();
		//Deallocates the memory space occupied by the BST

	void recursiveInorder() const;
		//Prints nodes of the BST in the inorder sequence	

	void recursivePreOrder() const;

	void recursivePostOrder() const;
	
	int totalNodes() const;
		//Returns the number of nodes in the BST	
	
	// Declaration of insert
		//Inserts a given item in the BST (non-recursive)
	void insert(int item);

	void insertRecursive(int item);

	Node* search(int item) const;

	//Node* searchParent(int item) const;
		
	// Declaration of function nonRecursiveInorder
		//Prints nodes of the BST in an inorder sequence (non-recursive)
	void nonRecursiveInorder() const;

	// Declaration of function nonRecursivePreorder
		//Prints nodes of the BST in an preorder sequence (non-recursive)
	void nonRecursivePreorder() const;
	
	// Declaration of function nonRecursivePostorder
		//Prints nodes of the BST in an postorder sequence (non-recursive)
	void nonRecursivePostorder() const;

	void deleteItem(int item);

	//Node* rightMost(Node *p) const;
			 
private:	
	Node *root; //pointer to the root
	int count;  //number of nodes

	void destroy(Node* &p);
		//Destroy the BST to which p points
	
    void recursiveInorder(Node *p) const;
		//Prints the inorder traversal of the BT to which p points

	void recursivePreOrder(Node *p) const;

	void recursivePostOrder(Node *p) const;

	void insertRecursiv(int item, Node *p);

	Node* search(int item, Node *p) const;

	void deleteNode(Node* p);

	//Node* searchParent(int item, Node *p) const;


};

#endif