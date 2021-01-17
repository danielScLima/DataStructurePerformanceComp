Data Structure Performance Comparator
====================
Build with AppVeyor: [![Build status](https://ci.appveyor.com/api/projects/status/cuw1o4xx5t2y0i9q?svg=true)](https://ci.appveyor.com/project/DanielSLima/datastructureperformancecomp)

Build witth Travis: [![Build Status](https://www.travis-ci.com/danielScLima/DataStructurePerformanceComp.svg?branch=master)](https://www.travis-ci.com/danielScLima/DataStructurePerformanceComp)

This repository has a project with the implementation of a Data Structure Performance Comparator.
It was divided in two parts: a gui and a core. This repo is the gui and the core was created as a submodule.

It is written in C++.

It has several data structures that are compared, considering insertion, remove and search.

All of the data structures are written in C++ and are independent of platform. Each one is fully tested,
using unit tests. The library used to make the Unit Test is the Catch v2.12.3.
The code is already in this repository.

Each library is in this github account. They are already configured as submodules. Once you clone this repo,
you must execute the following command:

git submodule update --init --recursive

After that, go until the submodule created (teh core) and execute the same command. It wil download all of the data structures.

This project uses the gnuplot, to generate graphs. Install this tool in your computer before use this software.


Full list of data structure: 
====================

* [Stack;](#markdown-header)
* [Queue;](#markdown-header)
* [Lists;](#markdown-header)
	* [List;](#markdown-header-emphasis)
	* [List circular;](#markdown-header-emphasis)
	* [DoubledLinkedList;](#markdown-header-emphasis)
	* [DoubledLinkedListCircular;](#markdown-header-emphasis)
* [TREEs;](#markdown-header)
	* [Avl tree;](#markdown-header-emphasis)
	* [Binary Tree;](#markdown-header-emphasis)
	* [BPlus Tree;](#markdown-header-emphasis)
	* [BStar Tree;](#markdown-header-emphasis)
	* [BTree;](#markdown-header-emphasis)	
	* [Radix Tree;](#markdown-header-emphasis)
	* [RedBlackTree;](#markdown-header-emphasis)
	* [Splay Tree;](#markdown-header-emphasis)
	* [Ternary search tree;](#markdown-header-emphasis)
	* [Tree 23;](#markdown-header-emphasis)
* [TRIEs;](#markdown-header)
	* [PatriciaTreeBinarySameLenKeys;](#markdown-header-emphasis)
	* [PatriciaTreeStoreBinaryDifferentLenKeys;](#markdown-header-emphasis)
	* [Trie or Prefix tree;](#markdown-header-emphasis)
* [Heaps.](#markdown-header)
	* [Binomial heap;](#markdown-header-emphasis)
	* [Fibonacci heap;](#markdown-header-emphasis)
	* [Leftist heap;](#markdown-header-emphasis)
	* [Max heap;](#markdown-header-emphasis)
	* [Min heap;](#markdown-header-emphasis)
	* [MinMax heap;](#markdown-header-emphasis)
	* [Skew heap;](#markdown-header-emphasis)



- - -

Sample images: 
====================

## Main gui:

![Alt text](images/1.png)

## Main gui with data structures categories expanded:

![Alt text](images/2.png)

## You can select which data structures you want to compare.

![Alt text](images/3.png)

## This is the gui, when the user selects the desired structures and clicks in make test of insertion.

![Alt text](images/4.png)

## If some data structure is not able of execute such function, a message is shown. For instance: the stack data structure does not have the search operation.

![Alt text](images/5.png)

## This is a image of the comparisson of insert

![Alt text](images/6.png)

