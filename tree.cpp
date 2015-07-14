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

void BinaryTree::insert(int k, string v)
{
	insert(k, v, root);
}

void BinaryTree::remove(int k)
{
	remove(k, root);
}

bool BinaryTree::search(int k, string &v) const
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
		insert(n->time, n->day);
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

void BinaryTree::insert(int k, string v, Node *&n)
{
	if(n == NULL)
	{
		n = new Node(k, v);
	}
	else if(k < n->time)
	{
		insert(k, v, n->left);
	}
	else if(k > n->time)
	{
		insert(k, v, n->right);
	}
	else
	{
		n->day = v;
	}
}

void BinaryTree::remove(int k, Node *&n)
{
	if(n != NULL)
	{
		if(k < n->time)
		{
			remove(k, n->left);
		}
		else if(k > n->time)
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
			n->time = successor->time;
			n->day = successor->day;
			remove(successor->time, successor);
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

bool BinaryTree::search(int k, string &v, Node *n) const
{
	if(n == NULL)
	{
		return false;
	}
	else if(k < n->time)
	{
		return search(k, v, n->left);
	}
	else if(k > n->time)
	{
		return search(k, v, n->right);
	}
	else
	{
		v = n->day;
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
		cout << n->time << ":" << n->day;
		print(n->right);
		cout << ")";
	}
}