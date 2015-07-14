/*
 * File:	tree.cpp
 * Author:	Luke Godfrey
 */

#include <iostream>
#include "tree.h"
#include "day.h"
using namespace std;

BinaryTree::BinaryTree() : root(NULL) {
	dayCount = 0;
}

BinaryTree::BinaryTree(const BinaryTree &bt)
{
	dayCount = 0;
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

void BinaryTree::print()
{
	dayCount = 0;
	print(root);
	cout << "Total Number of Days in Timerange: " << dayCount << endl;
}

void BinaryTree::printBefore(int k)
{
	dayCount = 0;
	printBefore(root, k);
	cout << "Total Number of Days in Timerange: " << dayCount << endl;
}

void BinaryTree::printAfter(int k)
{
	dayCount = 0;
	printAfter(root, k);
	cout << "Total Number of Days in Timerange: " << dayCount << endl;
}

void BinaryTree::printBetween(int after, int until)
{
	dayCount = 0;
	printBetween(root, after, until);
	cout << "Total Number of Days in Timerange: " << dayCount << endl;
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

void BinaryTree::print(Node *n)
{
	if(n != NULL)
	{
		print(n->left);
		dayCount += 1;
		n->day.print();
		print(n->right);
	}
}

void BinaryTree::printBefore(Node *n, int k)
{
	if(n != NULL)
	{
		printBefore(n->left, k);
		if(n->time < k) {
			dayCount += 1;
			n->day.print();
		}
		printBefore(n->right, k);
	}
}

void BinaryTree::printAfter(Node *n, int k)
{
	if(n != NULL)
	{
		printAfter(n->left, k);
		if(n->time > k) {
			dayCount += 1;
			n->day.print();
		}
		printAfter(n->right, k);
	}
}

void BinaryTree::printBetween(Node *n, int after, int until)
{
	if(n != NULL)
	{
		printBetween(n->left, after, until);
		if((n->time >= after) && (n->time <= until)) {
			dayCount += 1;
			n->day.print();
		}
		printBetween(n->right, after, until);
	}
}