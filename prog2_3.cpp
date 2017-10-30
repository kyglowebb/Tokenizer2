#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include "Tokenizer.hpp" 
#include "Stack.hpp"

using namespace std;

int isNum(string token);
	
int main(int argc, char *argv[])
{
	printf("Assignment #2-3, Kylee Webb, kawebb@sdsu.edu\n");

	Tokenizer prototype;
	string *tokens = new string[2];
	string tokenOne;
	string tokenTwo;
	
	Stack *myStack = new Stack();
	int numTokens = 0;
	int limit = 0;
	
	
	
	
	if(argc == 2)
	{						
		if(isNum(argv[1]) == 0)				// If the 2nd token in terminal is an integer... continue on
		{						
			limit = atoi(argv[1]);			// atoi converts the string entered by user to an int		
			
			for(int i = 0; i < limit ; i++)
			{	
		
				
				string *tokens = prototype.GetTokens();	
				tokenOne = tokens[0];
				tokenTwo = tokens[1];
				
				if(tokens[1] == "" ) 		// tokens holds the array of strings returned from Tokenizer not the command line arg
				{					
					if(strcasecmp(tokens[0].c_str(), "quit") == 0)
					{
						myStack->Print();
					
						return 0;
					}
					
					else if(strcmp(tokens[0].c_str(), "pop") == 0)
					{
						  myStack->Pop();
						
					}
					
					
					
				}
				else 
				{ 
				
					if(strcasecmp(tokens[0].c_str(), "push") == 0 && isNum(tokenTwo) == 0)
					{
						
						int value = atoi(tokenTwo.c_str());
						myStack->Push(value);
						
					}	

				}
			} 
		}
		else
		{
			printf("ERROR! Expected integer argument.");
		}
	}
	else
	{
		printf("ERROR! Program 6 accepts 1 command line argument.");
	}	
	myStack->Print();			
	return 0;	
}




//Finds out if it is a str or int
int isNum(string token)
{
	for(int i = 0; i < token.length(); i++)
	{
		if(!isdigit(token[i]))		// if it is not a digit, return false.
			return 1;		// == 1 is for string
	}
	
	return 0;				// if it isNum return 0 or == 0 is for int
} 


