/*
 * File:	tree.h
 * Author:	Luke Godfrey
 */

#ifndef TREE_H
#define TREE_H

#include <string>
#include "day.h"
using namespace std;

struct Node
{
	Node(int time, Day day, Node *left = NULL, Node *right = NULL)
	: time(time), day(day), left(left), right(right) {}

	int time;
	Day day;
	Node *left, *right;
};

class BinaryTree
{
	public:
		BinaryTree();
		BinaryTree(const BinaryTree &bt);
		~BinaryTree();

		void insert(int k, Day v);
		void print();
		void printBefore(int k);
		void printAfter(int k);
		void printBetween(int after, int until);



	private:
		void copyNode(const Node *n);
		void deleteNode(Node *&n);
		void insert(int k, Day v, Node *&n);
		void print(Node *n);
		void printBefore(Node *n, int k);
		void printAfter(Node *n, int k);
		void printBetween(Node *n, int after, int until);

		int dayCount;
		Node *root;
};

#endif
