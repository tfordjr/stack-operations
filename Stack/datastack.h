#pragma once
// CS 2250 Project 4 - Stack - Terry Ford                
// Specification File for Stack Class

#include <iostream>
#include <string>
using namespace std;
#ifndef DATASTACK_H
#define DATASTACK_H

class Stack
{
private:
	struct StackNode
	{
		char character;
		int lineNum,
			position;
		StackNode* next;       // ptr to next node 
	};
	StackNode* top;

public:
	Stack()
		{   top = nullptr;  }     // Constructor
	~Stack();                     // Destructor

	void push(char, int, int);              // Stack Operations
	void pop(char&, char, int, int);
	void compare(char, int, int);
	void unload();
	bool isEmpty();
};
#endif