#include "MyBinaryTree.h"
#include<queue>

void MyBinaryTree::destroy(NODE* _root)
{
	if (_root == NULL) return;
	destroy(_root->getLeft());
	destroy(_root->getRight());
	delete _root;
	root = NULL;
}

NODE* MyBinaryTree::add_node(NODE* _root, NODE* n)
{
	if (_root == NULL) { _root = n; return _root; }
	if (n->getData() < _root->getData())
		_root->setLeft(add_node(_root->getLeft(), n));
	else
		_root->setRight(add_node(_root->getRight(), n));
	return _root;
}

ostream& MyBinaryTree::printLVR(ostream& os, NODE* _root)
{
	if (_root == NULL) return os;
	if (_root->getLeft() != NULL) printLVR(os, _root->getLeft());
	os << _root->getData() << "  ";
	if (_root->getRight() != NULL) printLVR(os, _root->getRight());
	return os;
}

int MyBinaryTree::height_node(NODE* _root)
{
	if (_root == NULL) return 0;
	int L, R;
	L = height_node(_root->getLeft());
	R = height_node(_root->getRight());
	if (L > R) return L + 1;
	else return R + 1;
}

NODE* MyBinaryTree::find_node(NODE* _root, int x)
{
	if (_root == NULL) return NULL;
	if (_root->getData() == x) return _root;
	if (x < _root->getData()) return find_node(_root->getLeft(), x);
	else return find_node(_root->getRight(), x);
}

bool MyBinaryTree::is_balanced(NODE* _root)
{
	int bf; bool L, R, V;
	if (_root == NULL) return true;
	bf = height_node(_root->getRight()) - height_node(_root->getLeft());
	if (bf == -1 || bf == 0 || bf == 1) V = true; 
	else { V = false, cout << "\n   Balance criteria violated at node " << _root->getData() << ", bf(" << _root->getData() << ") = " << bf << endl; }
	L = is_balanced(_root->getLeft());
	R = is_balanced(_root->getRight());
	return L && R && V;
}

void MyBinaryTree::printK(NODE* _root, int k)
{
	if (_root == NULL) return;
	if ((_root->getLeft() == NULL) && (_root->getRight() == NULL)) return;
	if (_root->getLeft() == NULL)
	{
		if (_root->getRight()->getData() == k) cout << _root->getData() << "  ";
		printK(_root->getRight(), k);
	}
	else if (_root->getRight() == NULL)
	{
		if (_root->getLeft()->getData() == k) cout << _root->getData() << "  ";
		printK(_root->getLeft(), k);
	}
	else 
	{
		if (_root->getLeft()->getData() + _root->getRight()->getData() == k) cout << _root->getData() << "  ";
		printK(_root->getLeft(), k);
		printK(_root->getRight(), k);
	}
}

void MyBinaryTree::printValueR(NODE* _root, int r1, int r2)
{
	if (_root == NULL) return;
	printValueR(_root->getLeft(), r1, r2);
	if (_root->getData() >= r1 && _root->getData() <= r2) cout << _root->getData() << "  ";
	printValueR(_root->getRight(), r1, r2);
}

//void MyBinaryTree::printLevelR(NODE* _root, int l1, int l2, int curr = 0)        ----->  another way (not tidy)
//{
//	if (_root == NULL) return;
//	if (curr >= l1 && curr <= l2) cout << _root->getData() << "  ";
//	printLevelR(_root->getLeft(), l1, l2, curr + 1);
//	printLevelR(_root->getRight(), l1, l2, curr + 1);
//}

MyBinaryTree::MyBinaryTree(int x)
{
	NODE* n = new NODE(x);
	root = n;
}

MyBinaryTree::~MyBinaryTree()
{
	destroy(root);
}

void MyBinaryTree::insert(int x)
{
	NODE* n = new NODE(x);
	root = add_node(root, n);
}

int MyBinaryTree::height(int k)
{
	NODE* n = find_node(root, k);
	if (n == NULL) return ERROR;  // error -1 not found
	else return height_node(n) - 1;
}

bool MyBinaryTree::isBalansed()
{
	return is_balanced(root);
}

void MyBinaryTree::printSumNodesK(int k)
{
	printK(root, k);
}

void MyBinaryTree::inValueRange(int r1, int r2)
{
	printValueR(root, r1, r2);
}

void MyBinaryTree::inLevelRange(int l1, int l2)  // first level = 0
{
	// printLevelR(root, l1, l2);    ---->  another way  (not tidy)
	if (root == NULL) return;
	if (l1 >= height_node(root)) { cout << "\n   There are no levels within this range in the tree."; return; }
	queue <NODE*> Q;
	NODE* n;
	n = root;
	Q.push(n);
	int Qsize, level(0);
	while (!Q.empty())
	{
		Qsize = Q.size();
		if (level >= l1 && level <= l2)cout << "\n   level #" << level << " : ";
		while (Qsize)
		{
			n = Q.front(); Q.pop();

			if (level >= l1 && level <= l2)
				cout << n->getData() << "  ";

			if (n->getLeft() != NULL)Q.push(n->getLeft());
			if (n->getRight() != NULL)Q.push(n->getRight());
			--Qsize;
		}
		if (level >= l1 && level <= l2)cout << endl;
		++level;
	}
}

ostream& operator<<(ostream& os, MyBinaryTree& BST)
{
	if (BST.root == NULL) { cout << "\n   empty"; return os; }
	return BST.printLVR(os, BST.root);
}

int menu()
{
	int choice;
	cout << "\t\t\t           ####  Binary Search Tree (BST) Program  #### " << endl;
	cout << "\n   Description : This program deals with Binary Search Trees \n   and provides many operations on them." << endl;
	cout << "   -------------------------------------------------------------" << endl;
	cout << "\n    ____________________________ MENU ____________________________"
		<< "\n   |                                                              |"
		<< "\n   |  1) Read nodes from file.                                    |"
		<< "\n   |  2) insert a node.                                           |"
		<< "\n   |  3) print the tree (LVR).                                    |"
		<< "\n   |  4) find the height of a node.                               |"
		<< "\n   |  5) check if the tree is balanced.                           |"
		<< "\n   |  6) print nodes whose childrens sum equal a certain number.  |"
		<< "\n   |  7) prints nodes in a specific range of data.                |"
		<< "\n   |  8) prints nodes in a specific range of levels.              |"
		<< "\n   |  9) Exit.                                                    |"
		<< "\n   |______________________________________________________________|" << endl;
	cout << "\n   Choose from the list : "; cin >> choice;
	while (cin.fail() || choice < 1 || choice > 9)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n   Invalid input .. choose from the list : "; cin >> choice;
	}
	return choice;
}

int takeData()
{
	int data;
	cin >> data;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n   Invalid input , enter again : "; cin >> data;
	}
	return data;
}