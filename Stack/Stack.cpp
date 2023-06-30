// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

// CS 2250 Project 4 - Stack - Terry Ford
// Main Project File

#include "datastack.h"
#include "datastack.cpp"

int main()
{
    int line = 0, count;      
    string input;
    Stack delimStack;

    cout << "This Program will match left and right delimeters: Parenthesis, Curly Braces, and Brackets.\n";
    cout << "Please enter your input below\n";

    while (input != "DONE")
    {
        char leftDelim = 'a';     // leftDelim variable set at beginning of while loop prevents stale data
        line++;
        cout << "Line " << line << ": " ;
        getline(cin, input);

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '[' || input[i] == '(' || input[i] == '{')                 // LEFT DELIM FOUND
            {                
                delimStack.push(input[i], line, i);
            }
            else if (input[i] == ']' || input[i] == ')' || input[i] == '}')           // RIGHT DELIM FOUND
            {                
                delimStack.pop(leftDelim, input[i], line, i);                                               // EMPTY ERROR IN POP FUNCTIONS TO COMBAT STALE DATA                                                                                                                                                        
            }
        }
        cout << endl;
    }                                                                                                                               // DONE    
                                                                                                                                   
    while (!delimStack.isEmpty())                     // PRODUCE ERROR MESSAGES IF LEFT DELIMS ARE UNRESOLVED
    {
        delimStack.unload();
    }        
}

