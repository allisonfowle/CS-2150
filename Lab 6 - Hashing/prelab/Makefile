#Allison Fowle

CXX=clang++
CXXFLAGS=-Wall -O2
OBJECTS = hashTable.o timer.o wordPuzzle.o


a.out: $(OBJECTS)
	 $(CXX) $(CXXFLAGS) $(OBJECTS) -o a.out 
	 @echo "Compiled"
hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp 
timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
	$(CXX) -c wordPuzzle.cpp
.PHONY: clean
clean:
	-rm -f *.o *~ a.out