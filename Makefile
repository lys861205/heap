CXX=g++
CX=gcc
CXXFLAGS=-g -std=c++11
CXFLAGS=-g


test_heap: test_heap.o
	$(CXX) test_heap.o -o $@ 

test_heap.o:test_heap.cc
	$(CXX) -c $<  $(CXXFLAGS)

clean:
	rm -f test_heap.o test_heap

