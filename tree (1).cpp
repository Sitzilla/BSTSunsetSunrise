/*
 * File:	tree.cpp
 * Author:	Luke Godfrey
 */

#include <iostream>
#include "tree.h"
using namespace std;

BinaryTree::BinaryTree(const BinaryTree &bt)
{
	copyNode(bt.root);
}

BinaryTree::~BinaryTree()
{
	deleteNode(root);
}

void BinaryTree::insert(int k, int v)
{
	insert(k, v, root);
}

void BinaryTree::remove(int k)
{
	remove(k, root);
}

bool BinaryTree::search(int k, int &v) const
{
	return search(k, v, root);
}

int BinaryTree::size() const
{
	return size(root);
}

int BinaryTree::height() const
{
	return height(root);
}

void BinaryTree::print() const
{
	print(root);
}

// MARK: Private methods

void BinaryTree::copyNode(const Node *n)
{
	if(n != NULL)
	{
		insert(n->key, n->value);
		copyNode(n->left);
		copyNode(n->right);
	}
}

void BinaryTree::deleteNode(Node *&n)
{
	if(n != NULL)
	{
		deleteNode(n->left);
		deleteNode(n->right);
		delete n;
		n = NULL;
	}
}

void BinaryTree::insert(int k, int v, Node *&n)
{
	if(n == NULL)
	{
		n = new Node(k, v);
	}
	else if(k < n->key)
	{
		insert(k, v, n->left);
	}
	else if(k > n->key)
	{
		insert(k, v, n->right);
	}
	else
	{
		n->value = v;
	}
}

void BinaryTree::remove(int k, Node *&n)
{
	if(n != NULL)
	{
		if(k < n->key)
		{
			remove(k, n->left);
		}
		else if(k > n->key)
		{
			remove(k, n->right);
		}
		else if(n->left != NULL && n->right != NULL)
		{
			Node *successor = n->right;
			while(successor->left != NULL)
			{
				successor = successor->left;
			}
			n->key = successor->key;
			n->value = successor->value;
			remove(successor->key, successor);
		}
		else if(n->left != NULL)
		{
			Node *left = n->left;
			delete n;
			n = left;
		}
		else if(n->right != NULL)
		{
			Node *right = n->right;
			delete n;
			n = right;
		}
		else
		{
			delete n;
			n = NULL;
		}
	}
}

bool BinaryTree::search(int k, int &v, Node *n) const
{
	if(n == NULL)
	{
		return false;
	}
	else if(k < n->key)
	{
		return search(k, v, n->left);
	}
	else if(k > n->key)
	{
		return search(k, v, n->right);
	}
	else
	{
		v = n->value;
		return true;
	}
}

int BinaryTree::size(Node *n) const
{
	if(n == NULL)
	{
		return 0;
	}
	else
	{
		return size(n->left) + size(n->right) + 1;
	}
}

int BinaryTree::height(Node *n) const
{
	if(n == NULL)
	{
		return 0;
	}
	else
	{
		return max(height(n->left), height(n->right)) + 1;
	}
}

void BinaryTree::print(Node *n) const
{
	if(n != NULL)
	{
		cout << "(";
		print(n->left);
		cout << n->key << ":" << n->value;
		print(n->right);
		cout << ")";
	}
}

int main()
{
	BinaryTree bt;
	bt.insert(5, 5);
	bt.insert(1, 1);
	bt.insert(2, 2);
	bt.insert(3, 3);
	bt.insert(6, 6);
	bt.insert(7, 7);
	bt.insert(8, 8);
	bt.print();
	cout << endl;
	return 0;
}
