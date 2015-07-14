/*
 * File:	tree.h
 * Author:	Luke Godfrey
 */

#ifndef TREE_H
#define TREE_H

#include <string>
using namespace std;

struct Node
{
	Node(int time, string day, Node *left = NULL, Node *right = NULL)
	: time(time), day(day), left(left), right(right) {}

	int time;
	string day;
	Node *left, *right;
};

class BinaryTree
{
	public:
		BinaryTree() : root(NULL) {}
		BinaryTree(const BinaryTree &bt);
		~BinaryTree();

		void insert(int k, string v);
		void remove(int k);
		bool search(int k, string &v) const;
		int size() const;
		int height() const;
		void print() const;

	private:
		void copyNode(const Node *n);
		void deleteNode(Node *&n);
		void insert(int k, string v, Node *&n);
		void remove(int k, Node *&n);
		bool search(int k, string &v, Node *n) const;
		int size(Node *n) const;
		int height(Node *n) const;
		void print(Node *n) const;

		Node *root;
};

#endif
