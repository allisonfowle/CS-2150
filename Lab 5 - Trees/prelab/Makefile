# Allison Fowle
# CS 2150 - lab 104 (12:30)

CXX=clang++
CXXFLAGS= -Wall -O2
OBJECTS= TreeCalc.o TreeNode.o TreeCalcTest.o

a.out: $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o a.out
	@echo "Compiled"
		
TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalc.cpp
TreeNode.o: TreeNode.cpp TreeNode.h
	$(CXX) -c TreeNode.cpp
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
	$(CXX) -c TreeCalcTest.cpp
.PHONY: clean
clean:
	-rm -f *.o *~ a.out