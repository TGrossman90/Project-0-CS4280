//Tom Grossman
//CS4280 - Program Translation (Compilers)
//Project 0
//02/27/17
//Copyright © 2017 Tom Grossman. All Rights Reserved.

#include <string>
#include <fstream>
#include "traversals.h"

using namespace std;

// Structure for the tree/traversals is from the CS1250/2250 textbook
void printInOrder(Node *nodePtr, string fileName) {
	if(nodePtr) {
		printInOrder(nodePtr->leftNode, fileName);
		print(nodePtr, fileName);
		printInOrder(nodePtr->rightNode, fileName);
	}
}

void printPreOrder(Node *nodePtr, string fileName) {
	if(nodePtr) {
		print(nodePtr, fileName);
		printPreOrder(nodePtr->leftNode, fileName);
		printPreOrder(nodePtr->rightNode, fileName);
	}
}

void printPostOrder(Node *nodePtr, string fileName) {
	if(nodePtr) {
		printPostOrder(nodePtr->leftNode, fileName);
		printPostOrder(nodePtr->rightNode, fileName);
		print(nodePtr, fileName);
	}
}

// Print function indents two spaces per level of the node it is printing
// ex. Root node is indented 0 spaces, while root's child is indented 2 spaces,
// and root's grandchild is indented 4 spaces
void print(Node *nodePtr, string fileName) {
			
	string line;
	for(int i = 0; i < nodePtr->level; i++)
		line.append("  ");
	
	line += nodePtr->data;
	line.append(": ");
	
	for(int i = ((nodePtr->midNode.size()) - 1); i >= 0 ; i--) {
		line.append(nodePtr->midNode[i]);
		line.append(" ");
	}
	
	line.append("\n");
	
	ofstream outFile;
	outFile.open(fileName.c_str(), ios_base::app);
	outFile << line;
	//cout << line;
	outFile.close();
}
	