all:	main single_main

main:	main.cpp
	clang++ -o main -std=c++17 main.cpp

single_main:	single_main.cpp
	clang++ -o single_main -std=c++17 single_main.cpp
