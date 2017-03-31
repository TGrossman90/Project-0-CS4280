//Tom Grossman
//CS4280 - Program Translation (Compilers)
//Project 0
//02/27/17
//Copyright © 2017 Tom Grossman. All Rights Reserved.

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include "node.h"
#include "buildTree.h"
#include "traversals.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	// Initialize tree
	BuildTree tree;	
	ifstream oldFile;
	
	// If the program has executed before, this will remove old output files
	printf("\nRemoving old output files if they exist...\n");
	string command = "rm ";
	string pathIn = "*.inorder";
	string pathPre = "*.preorder";
	string pathPost = "*.postorder";
	system(command.append(pathIn).c_str());
	command = "rm ";
	system(command.append(pathPre).c_str());
	command = "rm ";
	system(command.append(pathPost).c_str());
	printf("Removing of old files complete.\n\n");
	
	// Checks if a file is being redirected or arguments being passed
	if (isatty(STDIN_FILENO)) {
		
		// If no arguments, prompt for userinput
		if(argc == 1) {
			string userInput;
			printf("Please enter some data to sort into the binary tree, then press Enter to submit.\n >> "); 
			getline(cin, userInput);	
			
			// Open a temp file to store userinput
			ofstream tempFile;
			tempFile.open("temp.txt");
			tempFile << userInput;
			tempFile.close();
			
			ifstream tmpFile;
			tmpFile.open("temp.txt");
			
			// Take tempfile and go through it word by word and search the tree for a match.
			// If match, take word and add it to the node vector.
			// If no match, create node based on first letter of word and store entire word in vector
			string word;
			while(tmpFile >> word) {
			int size = word.size();
				char wordArry[size];
				strcpy(wordArry, word.c_str());
				
				int rslt = tree.searchTree(wordArry[0], tree.root, word);
				//printf("Result: %i\n", rslt);
			}
			
			// Traverse tree and output files
			//printf("\nIn Order\n");
			printInOrder(tree.root, "out.inorder");
			//printf("\nPre Order\n");
			printPreOrder(tree.root, "out.preorder");
			//printf("\nPost Order\n");
			printPostOrder(tree.root, "out.postorder");
			//printf("\n");
			
			// Remove the temp file
			remove("temp.txt");
			
		// If there is one argument passed to the project...			
		} else if(argc == 2) {
			// To deal with implicit file names, I've implemented a way to open a file without an extension
			// and without limiting extensions.
			// To start, create a command line argument in the form of
			// ls argv[1]*
			string command;
			command = "ls ";
			command.append(argv[1]);
			command.append("*");
			
			// Run the command with the popen() function which returns the outstream of the system command
			int BUFFSIZ = 150;
			char buff[BUFSIZ];
			FILE *fp = popen(command.c_str(),"r");
			while (fgets( buff, BUFSIZ, fp) != NULL );
			pclose(fp);
			
			// Figure out how many characters are in the filename + extension
			int len = 0;
			for(int c = 0; c < BUFFSIZ; c++) {
				if((isalnum(buff[c])))
					len++;
			}
			len++;
			
			// Change the filename from a char array into a string 
			string name;
			for(int c = 0; c < len; c++)
				name += buff[c];
			
			// Open file
			ifstream tempFile;
			tempFile.open(name.c_str());
			
			// If the file opens, place new node/edit existing node
			if(tempFile.good()) {
				string word;
				while(tempFile >> word) {
					int size = word.size();
					char wordArry[size];
					strcpy(wordArry, word.c_str());
					
					int rslt = tree.searchTree(wordArry[0], tree.root, word);
				}
				
				// Create filenames for file outputs that program creates
				string inOrderFile = name;
				string::size_type i = inOrderFile.rfind('.', inOrderFile.length());
				if (i != string::npos) {
					inOrderFile.replace(i+1, 7, "inorder");
				}
				
				string preOrderFile = name;
				i = preOrderFile.rfind('.', preOrderFile.length());
				if (i != string::npos) {
					preOrderFile.replace(i+1, 8, "preorder");
				}
				
				string postOrderFile = name;
				i = postOrderFile.rfind('.', postOrderFile.length());
				if (i != string::npos) {
					postOrderFile.replace(i+1, 9, "postorder");
				}
				
				// Create output files
				//printf("\nIn Order\n");
				printInOrder(tree.root, inOrderFile);
				//printf("\nPre Order\n");
				printPreOrder(tree.root, preOrderFile);
				//printf("\nPost Order\n");
				printPostOrder(tree.root, postOrderFile);
				//printf("\n");	
			
			// If the file cannot be opened/doesn't exist
			} else {
				printf("\nERROR: File could not be opened.\n");
			}
			
		// If too many arguments were passed to the program
		} else if(argc > 2) {
			printf("\nERROR: You've entered too many arguments. Please try again.\n\n");
		}
		
	// If the program was run with a file being redirected to it
	} else {
		
		// Capture redirection
		string userInput;
		getline(cin, userInput);

		// Put redirected file into a temp file
		ofstream tempFile;
		tempFile.open("temp.txt");
		tempFile << userInput;
		tempFile.close();
		
		ifstream tmpFile;
		tmpFile.open("temp.txt");
		
		// Go through temp file word by word and add it to the tree
		string word;
		while(tmpFile >> word) {
		int size = word.size();
			char wordArry[size];
			strcpy(wordArry, word.c_str());
			
			int rslt = tree.searchTree(wordArry[0], tree.root, word);
		}
		
		// Traverse tree and ouput files
		//printf("\nIn Order\n");
		printInOrder(tree.root, "out.inorder");
		//printf("\nPre Order\n");
		printPreOrder(tree.root, "out.preorder");
		//printf("\nPost Order\n");
		printPostOrder(tree.root, "out.postorder");
		//printf("\n");
		
		// Remove the temp file
		remove("temp.txt");
	}
	
	return 0;
}
