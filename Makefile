all: hello-cpp-world hello-c-world Part1.0.cpp Part2.cpp Part4.cpp Part3.cpp

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@

