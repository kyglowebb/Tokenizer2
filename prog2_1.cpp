#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>


using namespace std;

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

// Checks how many tokens there are
int countTokens (char *line)
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

	
int main(int argc, char *argv[])
{
	printf("Assignment #2-1, Kylee Webb, kawebb@sdsu.edu\n");
	
	char buffer[256];
	char token[256];

	int count = 0;
	int t = 0;
	int quit = 0;
	int numTokens = 0;
	int firstToken = 0;
	int secondToken = 0;
	int numRuns = 0;


	int i;
		if(argc != 2) 	//it needs to count 1 filename & 1 argument but if it is not equal to 2 this happens	
		{
			printf("ERROR! Program 6 accepts 1 command line argument.");
			return 0;
		}
		else if (argc == 2 && isNum(argv[1]) == 1)	// counts argument and is == string	
		{
			printf("ERROR! Expected integer argument.");
			return 0;
		}
		
		numRuns = atoi(argv[1]);	// we know it has to be 2 (file and argument1) and it has to be a string
						// it casts int and makes it take strings
		
	
	
	
	for(i = 0; i < numRuns; i++) {		// numRuns is for sure 2 and a string
	
	//while ((strlen(buffer) != (strcasecmp(token, "quit") == 0))) {
       

	
	
	
		numTokens = 0;  // This resets the tokens each loop
		t = 0;  	// resets the total count each loop to zero
		count = 0;	// resets the total count each loop to zero
		
	
		printf("> ");			// prompts user for input
		fgets(buffer, 256, stdin);	// takes in user input
		
		numTokens = countTokens(buffer);			// so the function could be applied for another task
		
		if(numTokens == 1)					// it checks if there is only one token
		{
			sscanf(buffer+t," %s %n", token, &count);	//  reads input from a char string passed as the 1st argument
			if(strcasecmp(token, "quit") == 0)		//  strcasecmmp compares two strings irrespective of the case of characters
			{						// sees if the input from the user == the word quit == true
				break;					// if it does, it exits the while(1) loop and terminates
			}
		}
		t = 0;							// t and count are reset to 0 to get new tokens after each input
		count = 0;
		
		if((numTokens < 1 || numTokens > 2) || strlen(buffer) > 66){
		//while((numTokens < 1 || numTokens > 2) || strlen(buffer) > 66){		// if one of these conditions apply then enter while loop
			if(strlen(buffer) > 66){
				printf("ERROR! Input string too long.");
			}
			
			else if(numTokens < 1 || numTokens > 2){
				printf("ERROR! Incorrect number of tokens found.");
			}
	
			/*printf("> ");	
			fgets(buffer, 256, stdin);
			numTokens = countTokens(buffer);
			if(numTokens == 1 ){							// then after conditions for errors are checked
				sscanf(buffer+t," %s %n", token, &count);			// check if the user inputs quit 
				if(strcasecmp(token, "quit") == 0 && strlen(buffer) < numRuns){
					return 0;
				}
			}
			*/
			t = 0;							// reset t and count to zero to re-count tokens at proper time
			count = 0;
		}
		
			sscanf(buffer+t," %s %n", token, &count); 		// counting the bytes read
			t = t + count;
			if(numTokens == 1 && isNum(token) == 1){		// if the 1st token == str
				printf("STR ");
			}
			else if(numTokens == 1 && isNum(token) == 0){		// if the 1st token == int
				printf("ERROR! Expected STR.");
			}
			
			if(numTokens == 2){					// if there are 2 overall tokens
				firstToken = isNum(token);
				sscanf(buffer+t," %s %n", token, &count);
				secondToken = isNum(token);
				if( firstToken == 0) 				// if 1st token == int 
				{
					printf("ERROR! Expected STR INT.");
				}
				else if( firstToken == 1 && secondToken == 0)   // if 1st token == str &&  2nd token == int
				{
					printf("STR INT ");	
				}
				else if( firstToken == 1 && secondToken == 1)	// if 1st token == str && 2nd token == str
				{
					printf("ERROR! Expected STR INT.");
				}
			}
		printf("\n");	
	}
	
	
	return 0;	// ends main
}
	

			
