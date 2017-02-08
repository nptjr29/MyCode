#include "BST.h"

	//default constructor
BST::BST()
{
	root = NULL;
	count = 0;
}

	//destructor
BST::~BST()
{
	destroy(root);
}

	//destroyTree
void  BST::destroyTree()
{
	destroy(root);
	count = 0;
}

//destroy
void  BST::destroy(Node* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

	//recursiveInorder
void BST::recursiveInorder() const
{
	if (root == NULL)
		cerr << "There is no tree.";
	else
	{
		recursiveInorder(root);
	}
	cout << endl;
}

//recursiveInorder
void BST::recursiveInorder(Node *p) const
{
	if (p != NULL)
	{
		recursiveInorder(p->llink);
		cout << p->data << " ";
		recursiveInorder(p->rlink);
		
	}
}

//recursivePreorder
void BST::recursivePreOrder() const
{
	if (root == NULL)
		cerr << "There is no tree.";
	else
		recursivePreOrder(root);

	cout << endl;
}

void BST::recursivePreOrder(Node *p) const
{
	if (p != NULL)
	{
		cout << p->data << " ";
		recursivePreOrder(p->llink);
		recursivePreOrder(p->rlink);
	}

}

//recursive PostOrder
void BST::recursivePostOrder() const
{
	if (root == NULL)
		cerr << "There is no tree.";
	else
		recursivePostOrder(root);

	cout << endl;
}

void BST::recursivePostOrder(Node *p) const
{
	if (p != NULL)
	{
		recursivePostOrder(p->llink);
		recursivePostOrder(p->rlink);
		cout << p->data << " ";
	}
}

	//totalNodes
int BST::totalNodes() const
{
	return count;
}


/***************************************************************************************************

	Functions to implement:
			- insert (non-recursive)	
			- insert (recursive)		
			- search (recursive)		
			- deleteNode (recursive)	
			- recursivePreOrder			
			- recursivePostOrder		
			- nonRecursiveInorder		
			- nonRecursivePreorder		
			- nonRecursivePostorder		

***************************************************************************************************/
void BST::insertRecursive(int item)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = item;
		root->llink = NULL;
		root->rlink = NULL;
		++count;
	}
	else
		insertRecursiv(item, root);
}

void BST::insertRecursiv(int item, Node *p)
{
	if (item == p->data)
		cerr << "The item to insert is already in the list.Duplicates are not allowed." << endl;
	else if (item < p->data)
	{
		if (p->llink != NULL)
			insertRecursiv(item, p->llink);
		else
		{
			p->llink = new Node;
			p->llink->data = item;
			p->llink->llink = NULL;
			p->llink->rlink = NULL;
			++count;
		}
	}
	else
	{
		if (p->rlink != NULL)
			insertRecursiv(item, p->rlink);
		else
		{
			p->rlink = new Node;
			p->rlink->data = item;
			p->rlink->llink = NULL;
			p->rlink->rlink = NULL;
			++count;
		}
	}

}

//insert (non-recursive)
void BST::insert(int item)
{
	
	//if tree is empty
	if (root == NULL)
	{
		root = new Node;
		root->data = item;
		root->llink = NULL;
		root->rlink = NULL;
		++count;
	}
	//if tree is not empty
	else
	{
	
		bool found = false;

		Node * newNode = new Node;
		newNode->data = item;
		newNode->llink = NULL;
		newNode->rlink = NULL;

		Node * parent = root;
		Node * temp = root;
		while ((parent != NULL) && (!found))
		{
			if (item == parent->data)
			{
				found = true;
				cerr << "The item to insert is already in the list. Duplicates are not allowed.";
			}
			else if (item < parent->data)
			{
				temp = parent;
				parent = parent->llink;
			}
			else
			{
				temp = parent;
				parent = parent->rlink;
			}
		}

		if (!found)
		{
			if (item < temp->data)
				temp->llink = newNode;
			else
				temp->rlink = newNode;

			++count;
		}

	}

}

Node* BST::search(int item) const
{
	Node *p = NULL;
	if (root == NULL)
		cerr << "There is no tree." << endl;
	else if (item == root->data)
	{
		//cout << "Item is at the root." << endl;
		p = root;
	}
	else
	{
		p = search(item, root);
	}

	return p;
}

Node* BST::search(int item, Node *p) const
{
	Node * result = NULL;
	if (p == NULL)
		cerr << "Item is NOT found." << endl;
	else if (item == p->data)
	{
		//cout << "Item is found." << endl;
		result = p;
		return result;
	}	
	else if (item < p->data)
		return search(item, p->llink);
	else if (item > p->data)
		return search(item, p->rlink);
}

//nonRecursiveInorder

void BST::nonRecursiveInorder() const
{
	if (root == NULL)
	{
		cerr << "There is no tree." << endl;
	}
	else
	{
		Node * current = root;
		stack<Node *> s;

		while ((current != NULL) || (!s.empty()))
		{
			if (current != NULL)
			{
				s.push(current);
				current = current->llink;
			}
			else
			{
				current = s.top();
				s.pop();
				cout << current->data << " ";
				current = current->rlink;
			}
		}
	}	
	
	cout << endl;
}



//nonRecursivePreorder

void BST::nonRecursivePreorder() const
{
	if (root == NULL)
	{
		cerr << "There is no tree." << endl;
	}
	else
	{
		Node * current = root;
		stack<Node *> s;

		while ((current != NULL) || (!s.empty()))
		{
			if (current != NULL)
			{
				s.push(current);
				cout << current->data << " ";
				current = current->llink;
			}
			else
			{
				current = s.top();
				s.pop();
				current = current->rlink;
			}
		}
	}

	cout << endl;
}


//nonRecursivePostorder
void BST::nonRecursivePostorder() const
{
	if (root == NULL)
	{
		cerr << "There is no tree." << endl;
	}
	else
	{
		stack<Node *> s;
		stack<int> v;

		Node * current = root;
		int value = 0;

		s.push(current);
		v.push(1);
		current = current->llink;

		while ((!s.empty()) || (!v.empty()))
		{
			if ((current != NULL) && (value == 0))
			{
				s.push(current);
				v.push(1);
				current = current->llink;
			}
			else
			{
				current = s.top();
				s.pop();
				value = v.top();
				v.pop();

				if (value == 1)
				{
					s.push(current);
					v.push(2);
					current = current->rlink;
					value = 0;
				}
				else
				{
					cout << current->data << " ";
				}
			}
		}
	}	

	cout << endl;
}

void BST::deleteItem(int item)
{
	if (root == NULL)
		cerr << "There is no tree." << endl;
	else
	{
		Node *p = search(item);
		deleteNode(p);
		--count;
	}
}

void BST::deleteNode(Node *d)
{
	Node * temp = d;

	if (d->llink == NULL && d->rlink == NULL)
	{
		delete d;
	}
	else if (d->llink == NULL)
	{
		d = d->rlink;
		delete temp;
		temp = NULL;
	}
	else if (d->rlink == NULL)
	{
		d = d->llink;
		delete temp;
		temp = NULL;
	}
	else
	{
		temp = d->llink;
		while (temp->rlink != NULL)
		{
			temp = temp->rlink;
		}
		d->data = temp->data;
		deleteItem(temp->data);
	}
}


//Node* BST::rightMost(Node *p) const
//{
//	Node * result = NULL;
//	result = p->llink;
//	while (p->rlink != NULL)
//	{
//		result = p->rlink;
//	}
//	return result;
//}

//void BST::deleteNode(int item)
//{
//	Node *p = search(item);
//
//	//Case 0: Node is not found
//	if (p == NULL)
//		cerr << "Item NOT found." << endl;	
//	else
//	{
//		//Case 1: Node is a leaf
//		if (p->llink == NULL && p->rlink == NULL)
//		{
//			delete p;
//			p = NULL;
//		}
//		//Case 2: Node has no left subtree
//		else if (p->llink == NULL)
//		{
//			Node * parent = searchParent(item);
//			Node * temp = p;
//			parent->llink = temp->rlink;
//			delete p;
//			p = NULL;
//		}
//		//Case 3: Node has no right subtree
//		else if (p->rlink == NULL)
//		{
//			Node * parent = searchParent(item);
//			Node * temp = p;
//			parent->rlink = temp->llink;
//			delete p;
//			p = NULL;
//		}
//		//Case 4: Node has BOTH left and right subtree
//		else
//		{
//			Node * successor = rightMost(p);
//			p->data = successor->data;
//
//			deleteNode(successor->data);
//		}
//
//	}
//
//}
//
//Node* BST::searchParent(int item) const
//{
//	Node * result = NULL;
//	//if tree is empty
//	if (root == NULL)
//	{
//		cerr << "Tree is empty." << endl;
//	}
//	//if tree is not empty
//	else
//	{
//
//		bool found = false;
//
//		Node * parent = root;
//		Node * temp = root;
//		while ((parent != NULL) && (!found))
//		{
//			if (item == parent->data)
//			{
//				found = true;
//				result = temp;
//			}
//			else if (item < parent->data)
//			{
//				temp = parent;
//				parent = parent->llink;
//			}
//			else
//			{
//				temp = parent;
//				parent = parent->rlink;
//			}
//		}
//
//		if (!found)
//		{
//			cerr << "Item is not found." << endl;
//		}
//
//	}
//	return result;
//}

