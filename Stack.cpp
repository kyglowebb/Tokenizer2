#include <iostream>       // std::cout
#include "Stack.hpp"      // std::stack
#include <string>
#include <vector>


using namespace std;

// Create a vector containing integers
vector<int> expandArray;

void Stack::Push(int data)	// Pushes on a variable on to the top of 					// the stack and to the last element of the array.
{


	expandArray.push_back(data); // Adds a new element at the end of the vector, after its current 					     // last element
	
}

int Stack::Pop()				// Pops off the variable that is on the top of the stack
{
	
	int data;			// We want data to hold the number that will be popped off
	
	if(expandArray.empty())		// check to see if expandArray is empty, if it is end program.
	{ 
	 	return -1;
	}
	
	
	
	data = expandArray.back();	// Moves the data to be last thing
	

	expandArray.pop_back();		// pops off the last element

		return data;
}
		
		
void Stack::Print()				// sideChick takes the data from expandArray and stores it there
{					// in order for it later to be able to swap int positions 
					// correctly
	
	int sideChick[expandArray.size()]; //sideChick will be initialized
					   //to whatever expandArray's size
	cout << "[ ";
	int i = 0;
	while(!expandArray.empty())	// while expandArray is NOT empty do the while loop
	{
		sideChick[i] = this->Pop(); // giving us the last value as it deletes it
					   // when dealing with pointers, you point to the func. you want
					   // to use
		i++;		   
	}
	
	
	int p = i-1;			   // The int p is going to equal the index - 1
	
	while(p > -1)
	{
		cout << sideChick[p] << " ";
		p--;
	}
	cout << "]" << endl;
	
}

   
 
 
