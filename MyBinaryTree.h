#pragma once
#include<iostream>
using namespace std;

#define ERROR -1

class NODE  // represent the vertex of Binary tree
{
private:
	int data;
	NODE* left, * right;

public:
	NODE() { data = 0; left = right = NULL; }
	NODE(int n) { data = n; left = right = NULL; }
	int getData() { return data; }
	NODE* getLeft() { return left; }
	NODE* getRight() { return right; }
	void setData(int x) { data = x; }
	void setLeft(NODE* p) { left = p; }
	void setRight(NODE* p) { right = p; }
};

class MyBinaryTree  // represent the Binary tree
{
private:
	NODE* root;
	void destroy(NODE*);
	NODE* add_node(NODE*, NODE*);
	ostream& printLVR(ostream&, NODE*);
	int height_node(NODE*);
	NODE* find_node(NODE*, int);
	bool is_balanced(NODE*);
	void printK(NODE*, int);
	void printValueR(NODE*, int, int);

public:
	MyBinaryTree() { root = NULL; }
	MyBinaryTree(int);
	~MyBinaryTree();
	void insert(int);
	friend ostream& operator <<(ostream&, MyBinaryTree&);
	int height(int);
	bool isBalansed();
	void printSumNodesK(int);
	void inValueRange(int, int);
	void inLevelRange(int, int);  // first level = 0
};

int menu();
int takeData();