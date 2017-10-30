#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include "Tokenizer.hpp" 


using namespace std;



int isNum(char *token);
	
int main(int argc, char *argv[])
{
	Tokenizer prototype;

	printf("Assignment #2-2, Kylee Webb, kawebb@sdsu.edu\n");
	
	char buffer[256];
	char token[256];

	int count = 0;
	int t = 0;
	int quit = 0;
	int numTokens = 0;
	int firstToken = 0;
	int secondToken = 0;
	int limit = 0;
	int i;
	
		
	
	if(argc == 2)
	{									 
		if(isNum(argv[1]) == 0)						// If the 2nd token in terminal is an integer... continue on
		{						
			limit = atoi(argv[1]);					// atoi converts the first command line to an integer		
			
			for(i = 0; i < limit ; i++)
			{	

				string* tokens = prototype.GetTokens();		
				
				if(tokens[1] == "") 
				{					// If the first argument == whitespace
					if(strcasecmp(tokens[0].c_str(), "quit") == 0)
					{
						return 0;
					}
					printf("STR \n");
				
				}
				else
				{ 
					printf("STR INT \n");
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
	return 0;	
}


//Finds out if it is a str or int
int isNum(char *token)
{


	for(int i = 0; i < strlen(token); i++)
	{
		if(!isdigit(token[i]))		// if it is not a digit, return false.
			return 1;		// 1 is for string
	}
	
	return 0;				// else return true because it is a digit.
} 


