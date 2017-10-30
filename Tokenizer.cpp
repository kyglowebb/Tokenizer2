#include <iostream>
#include <string>
#include "Tokenizer.hpp" 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>


using namespace std;

string* Tokenizer::GetTokens(){

	char buffer[256];
	char token[256];

	int count = 0;
	int t = 0;
	int quit = 0;
	int numTokens = 0;
	int firstToken = 0;
	int secondToken = 0;
	int limit = 0;
	
	
	
	string* tokensToReturn = new string[2];
	
	tokensToReturn[0] = "";
	tokensToReturn[1] = "";
	


	
	int i = 0;
	for(i = 0; ; i++) {		// limit is for sure 2 and a string
	
	
	
		numTokens = 0;  // This resets the tokens each loop
		t = 0;  	// resets the total count each loop to zero
		count = 0;	// resets the total count each loop to zero
		
	
		printf("> ");			// prompts user for input
		fgets(buffer, 256, stdin);	// takes in user input
		
		numTokens = countTokens(buffer);			// so the function could be applied for another task
		
		
		/*
		if(numTokens == 1)					// it checks if there is only one token
		{
			sscanf(buffer+t," %s %n", token, &count);	
			if(strcasecmp(token, "quit") == 0)		
			{						
				break;					
			}
		}
		*/
		
		
		t = 0;							// t and count are reset to 0 to get new tokens after each input
		count = 0;
		
		if((numTokens < 1 || numTokens > 2)) 
		{
			
			
			printf("ERROR! Incorrect number of tokens found.");
		
	
			t = 0;							// reset t and count to zero to re-count tokens at proper time
			count = 0;
		}
		
			sscanf(buffer+t," %s %n", token, &count); 		// counting the bytes read
			t = t + count;
			
			
			if(numTokens == 1 && isNum(token) == 1){		// if the 1st token == str
				//printf("STR ");
				tokensToReturn[0] = token;
				return tokensToReturn;
			}
			else if(numTokens == 1 && isNum(token) == 0){		// if the 1st token == int
				printf("ERROR! Expected STR.");
			}
			
			if(numTokens == 2){					// if there are 2 overall tokens
				firstToken = isNum(token);
				tokensToReturn[0] = token;
				sscanf(buffer+t," %s %n", token, &count);
				secondToken = isNum(token);
				if( firstToken == 0) 				// if 1st token == int 
				{
					printf("ERROR! Expected STR INT.");
				}
				else if( firstToken == 1 && secondToken == 0)   // if 1st token == str &&  2nd token == int
				{
					//printf("STR INT ");
					
					tokensToReturn[1] = token;
					return tokensToReturn;	
				}
				else if( firstToken == 1 && secondToken == 1)	// if 1st token == str && 2nd token == str
				{
					printf("ERROR! Expected STR INT.");
				}
			}
		printf("\n");	
	}


}


int Tokenizer::isNum(char *token)   		// Finds out if it is a number or a string
{

for(int i = 0; i < strlen(token); i++)
	{
		if(!isdigit(token[i]))		// if it is not a digit, return false.
			return 1;		// 1 is for string
	}
	
	return 0;				// 0 is for number 


}
	
	
int Tokenizer::countTokens(char *line)		// Counts how many tokens there are
{

        int numTokens = 0;
	char token[256];
	int count = 0;
	int t = 0;
	while(line[t] != '\0') 					// while pointer to the counter
	{
		if(strlen(line) - 1 == 0)			// if string length is less than 1
			return 0;				// return true
		sscanf(line+t," %s %n", token, &count);		// Take in the string and put it into token
		t = t + count;					// counter
		numTokens++;					// increase the tokens
	}
		return numTokens;

}	

 
 	
 	
 	
 	
 	
 	

