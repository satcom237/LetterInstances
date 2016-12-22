/*************************************************************************************************
 *Program: 	driver.cpp
 *Author: 	Sathya Ramanathan
 *Date: 	11/01/2015
 *Description:	Takes user input for a file and counts the number of occurrences of each letter.
		Then asks user for a file to save the results
*************************************************************************************************/ 

#include <iostream>
#include <fstream>
#include <string>
#include "letters.h"

using namespace std;

int main (){
	cout << "Welcome to letter count" << endl;
	char FileName[256];
	cout << "Enter a file name: ";
	cin >> FileName;
	string lineBuffer;
    	ifstream inMyStream (FileName); 
	count_letters(inMyStream, lineBuffer);

	return 0;
}


