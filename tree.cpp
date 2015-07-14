/*
 * File:	tree.cpp
 * Author:	Luke Godfrey
 */

#include <iostream>
#include "tree.h"
#include "day.h"
using namespace std;

BinaryTree::BinaryTree(const BinaryTree &bt)
{
	copyNode(bt.root);
}

BinaryTree::~BinaryTree()
{
	deleteNode(root);
}

void BinaryTree::insert(int k, Day v)
{
	insert(k, v, root);
}

void BinaryTree::print() const
{
	print(root);
}

void BinaryTree::printBefore(int k) const
{
	printBefore(root, k);
}

void BinaryTree::printAfter(int k) const
{
	printAfter(root, k);
}

void BinaryTree::printBetween(int after, int until) const
{
	printBetween(root, after, until);
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

void BinaryTree::insert(int k, Day v, Node *&n)
{
	if(n == NULL)
	{
		n = new Node(k, v);
	}
	else if(k <= n->time)
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

void BinaryTree::print(Node *n) const
{
	if(n != NULL)
	{
		print(n->left);
		n->day.print();
		print(n->right);
	}
}

void BinaryTree::printBefore(Node *n, int k) const
{
	if(n != NULL)
	{
		printBefore(n->left, k);
		if(n->time < k) {
			n->day.print();
		}
		printBefore(n->right, k);
	}
}

void BinaryTree::printAfter(Node *n, int k) const
{
	if(n != NULL)
	{
		printAfter(n->left, k);
		if(n->time > k) {
			n->day.print();
		}
		printAfter(n->right, k);
	}
}

void BinaryTree::printBetween(Node *n, int after, int until) const
{
	if(n != NULL)
	{
		printBetween(n->left, after, until);
		if((n->time >= after) && (n->time <= until)) {
			n->day.print();
		}
		printBetween(n->right, after, until);
	}
}