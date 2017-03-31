//Tom Grossman
//CS4280 - Program Translation (Compilers)
//Project 0
//02/27/17
//Copyright © 2017 Tom Grossman. All Rights Reserved.

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

struct Node {
	char data;
	struct Node *leftNode;
	struct Node *rightNode;
	std::vector<std::string> midNode;
	int level;
};

#endif