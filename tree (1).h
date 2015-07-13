/*
 * File:	tree.h
 * Author:	Luke Godfrey
 */

#ifndef TREE_H
#define TREE_H

struct Node
{
	Node(int key, int value, Node *left = NULL, Node *right = NULL)
	: key(key), value(value), left(left), right(right) {}

	int key, value;
	Node *left, *right;
};

class BinaryTree
{
	public:
		BinaryTree() : root(NULL) {}
		BinaryTree(const BinaryTree &bt);
		~BinaryTree();

		void insert(int k, int v);
		void remove(int k);
		bool search(int k, int &v) const;
		int size() const;
		int height() const;
		void print() const;

	private:
		void copyNode(const Node *n);
		void deleteNode(Node *&n);
		void insert(int k, int v, Node *&n);
		void remove(int k, Node *&n);
		bool search(int k, int &v, Node *n) const;
		int size(Node *n) const;
		int height(Node *n) const;
		void print(Node *n) const;

		Node *root;
};

#endif
