//Tom Grossman
//CS4280 - Program Translation (Compilers)
//Project 0
//02/27/17
//Copyright © 2017 Tom Grossman. All Rights Reserved.

#ifndef BUILDTREE_H
#define BUILDTREE_H

#include "node.h"

// Structure for the tree/traversals is from the CS1250/2250 textbook
class BuildTree {
	private:
		void insert(Node *&, Node *&);
	
	public: 
		Node *root;
		
		BuildTree() 
			{ root = NULL; }
		
		void insertNode(char, std::string, int);
		int searchTree(char, Node *, std::string);
};

#endif