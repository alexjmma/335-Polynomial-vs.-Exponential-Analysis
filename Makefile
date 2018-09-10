
GXX49_VERSION := $(shell g++-4.9 --version 2>/dev/null)

ifdef GXX49_VERSION
	CXX_COMMAND := g++-4.9
else
	CXX_COMMAND := g++
endif

CXX = ${CXX_COMMAND} -std=c++14 -Wall

all: test exhaustive_subsequence_timing

headers: rubrictest.hpp timer.hpp exhaustive_subsequence.hpp

exhaustive_subsequence_test: headers exhaustive_subsequence_test.cpp
	${CXX} exhaustive_subsequence_test.cpp -o exhaustive_subsequence_test

test: exhaustive_subsequence_test
	./exhaustive_subsequence_test

exhaustive_subsequence_timing: headers exhaustive_subsequence_timing.cpp
	${CXX} exhaustive_subsequence_timing.cpp -o exhaustive_subsequence_timing

clean:
	rm -f exhaustive_subsequence_test exhaustive_subsequence_timing
