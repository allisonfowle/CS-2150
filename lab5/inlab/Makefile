# Allison Fowle
# CS 2150 - lab 104 (12:30)

CXX=clang++
CXXFLAGS= -Wall -O2
OBJECTS= BSTPathTest.o BinaryNode.o BinarySearchTree.o

a.out: $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o a.out
	@echo "Compiled"	
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTPathTest.cpp
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
	$(CXX) -c BinarySearchTree.cpp
.PHONY: clean
clean:
	-rm -f *.o *~ a.out