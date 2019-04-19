all: build
clear:
	rm knapsack

build:
	gcc	knapsack.c	-o	knapsack