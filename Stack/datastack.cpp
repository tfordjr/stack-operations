// CS 2250 Project 4 - Stack - Terry Ford
// Implementation file for the Stack Class

#include "datastack.h"
#include <iomanip>

Stack::~Stack()
{
	StackNode* nodePtr = nullptr, * nextNode = nullptr;
	nodePtr = top;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void Stack::push(char delim, int line, int charCount)
{
	StackNode* newNode = nullptr;  // ptr to new node

	newNode = new StackNode;
	newNode->character = delim;
	newNode->lineNum = line;
	newNode->position = charCount;

	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

void Stack::pop(char &leftDelim, char rightDelim, int line, int charCount)
{
	StackNode* temp = nullptr;

	if(isEmpty())               // ensure stack isn't empty    EMPTY ERROR MESSAGE HERE
	{
		cout << "ERROR: Stack is Empty, Right delimiter " << rightDelim << " found at line " << line << " char " << charCount + 1 << " has no left delimiter" << endl;
	}
	else                       
	{
		compare(rightDelim, line, charCount);   // compare

		leftDelim = top->character;         // pop value
		temp = top->next;
		delete top;
		top = temp;
	}
}

void Stack::compare(char rightDelim, int line, int charCount)           // COMPARE, IF DELIMS DO NOT MATCH, DETAILED ERROR MESSAGE
{		
	if (top->character == '[' && rightDelim != ']' || top->character == '(' && rightDelim != ')' || top->character == '{' && rightDelim != '}')
	{
		cout << "ERROR: Mismatched delimiter " << top->character << " found at line " << top->lineNum << ", char " << top->position + 1;
		cout << " does not match " << rightDelim << " found at line " << line << ", char " << charCount + 1 << endl;
	}	
}

void Stack::unload()
{
	StackNode* temp = nullptr;

	cout << "ERROR: Left delimiter " << top->character << " at line " << top->lineNum << ", char " << top->position + 1 << " had no right delimiter." << endl;
	temp = top->next;
	delete top;
	top = temp;
}

bool Stack::isEmpty()
{
	bool status;

	if (!top)
		status = true;
	else
		status = false;

	return status;
}