//Tom Grossman
//CS4280 - Program Translation (Compilers)
//Project 0
//02/27/17
//Copyright © 2017 Tom Grossman. All Rights Reserved.

#include <cstddef>
#include <vector>
#include "buildTree.h"
#include "node.h"

// Structure for the tree/traversals is from the CS1250/2250 textbook
void BuildTree::insertNode(char ch, std::string str, int index) {
	Node *newNode = NULL;
	
	newNode = new Node;
	newNode->data = ch;
	newNode->leftNode = newNode->rightNode = NULL;
	newNode->midNode.push_back(str);
	newNode->level = index;
	
	insert(root, newNode);
}

void BuildTree::insert(Node *&nodePtr, Node *&newNode) {
	if(nodePtr == NULL) {
		nodePtr = newNode;
	} else if(newNode->data < nodePtr->data) {
		insert(nodePtr->leftNode, newNode);
	} else {
		insert(nodePtr->rightNode, newNode);
	}
}

// Modified CS1250/2250 search function to search for if a node already exists
// and if it does, to just add the new string to the existing node. If a node does
// not exist, by first searching the tree for an existing node, the function can keep track
// of how many levels deep the new node will be placed
int BuildTree::searchTree(char ch, Node *root, std::string word) {
	Node *nodePtr = root;
	int index = 0;
	
	while(nodePtr) {
		if(nodePtr->data == ch) {
			nodePtr->midNode.push_back(word);
			return 1;
		}
		else if(ch < nodePtr->data) {
			nodePtr = nodePtr->leftNode;
			index++;
		}
		else {
			nodePtr = nodePtr->rightNode;
			index++;
		}
	}
	insertNode(ch, word, index);
	return 0;
}