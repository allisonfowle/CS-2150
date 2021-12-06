# Allison Fowle
# CS 2150 - lab 104 (12:30)

CXX=clang++
CXXFLAGS= -Wall -O2
OBJECTS= AVLNode.o AVLPathTest.o AVLTree.o

a.out: $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o a.out
	@echo "Compiled"
AVLNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLPathTest.cpp
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
	$(CXX) -c AVLTree.cpp
.PHONY: clean
clean:
	-rm -f *.o *~ a.out