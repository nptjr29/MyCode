#include "BST.h"

#include <iostream>
#include <fstream>
using namespace std;

void processTree(BST&,char fileName[]);

void testTree(BST& bst);

int main()
{
	cout << "TESTING: int_1 BST\n\n";
	BST int1BST;
	char fileNameInt1[] = "data_int_1.txt";
	processTree(int1BST,fileNameInt1);
	testTree(int1BST);

	//cout << "\n\n---------------------------------------------------\n";
	//cout << "TESTING: int_2 BST\n\n";
	//BST int2BST;
	//char fileNameInt2[] = "data_int_2.txt";
	//processTree(int2BST,fileNameInt2);
	//testTree(int2BST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Deleting tree...\n\n";
	int1BST.destroyTree();
	testTree(int1BST);

	cout << endl << endl;
	system("Pause");
	return 0;
}

void processTree(BST& bst, char fileName[])
{
	ifstream infile;
	infile.open(fileName);

	if(!infile)
        cerr << "Cannot open the input file." << endl;
	else
	{
		int data;	
		infile >> data;
		
		while (data != -999)
        {
			 bst.insertRecursive(data); 	
			 infile >> data;	
        }

		infile.clear(); //reset eof for next input
     }

     infile.close();
}

void testTree(BST& bst)
{

	//TEST: inorder traversal (recursive)
	cout << "Inorder traversal (recursive):\n      ";
	bst.recursiveInorder();

	//TEST: inorder traversal (non-recursive)
	cout << "\nInorder traversal (non-recursive):\n      ";
	bst.nonRecursiveInorder();

	//TEST: preorder traversal (recursive)
	cout << "\nPreorder traversal (recursive):\n      ";
	bst.recursivePreOrder();

	//TEST: preorder traversal (non-recursive)
	cout << "\nPreorder traversal (non-recursive):\n      ";
	bst.nonRecursivePreorder();

	//TEST: postorder traversal (recursive)
	cout << "\nPostorder traversal (recursive):\n      ";
	bst.recursivePostOrder();

	//TEST: postorder traversal (non-recursive)
	cout << "\nPostorder traversal (non-recursive):\n      ";
	bst.nonRecursivePostorder();

	////TEST: Search for an item in the tree
	//cout << "\nSearching for 13:\n      ";
	//bst.search(13);
	//cout << "\nSearching for 999:\n      ";
	//bst.search(999);
	//cout << "\nSearching for 16:\n      ";
	//bst.search(16);
	//cout << "\nSearching for 10:\n      ";
	//bst.search(10);
	//cout << "\nSearching for 50:\n      ";
	//bst.search(50);
	//cout << "\nSearching for 12:\n      ";
	//bst.search(12);

	//TEST: Deleting an item from the tree...
	cout << "\nDeleting an item from the tree:\n      ";
	bst.deleteItem(2);

	//TEST: inorder traversal (non-recursive)
	cout << "\nInorder traversal (non-recursive):\n      ";
	bst.nonRecursiveInorder();


	//TEST: totalNodes
	cout << "\nTotal nodes: " << bst.totalNodes();
}
