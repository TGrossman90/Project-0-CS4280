all: p0 clear readme

p0: buildTree.o traversals.o app.o
	g++ -o p0 buildTree.o traversals.o app.o 

app.o: app.cpp
	g++ -c app.cpp

buildTree.o: buildTree.cpp
	g++ -c buildTree.cpp

traversals.o: traversals.cpp
	g++ -c traversals.cpp

clean: remove clear success

remove:
	rm *.o p0 *.*order

clear: 
	clear
	
success: 
	$(info SUCCESS)
	
readme:
	cat README.txt
