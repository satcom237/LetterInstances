/*************************************************************************************************
 *Program: 	letters.cpp
 *Author: 	Sathya Ramanathan
 *Date: 	11/01/2015
 *Description:	Takes user input for a file and counts the number of occurrences of each letter.
		Then asks user for a file to save the results
*************************************************************************************************/ 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "letters.h"

using namespace std;

void output_letters(int upperCaseCount[], int lowerCaseCount[]){
        ofstream User;
        char UserFile[256];
        cout << "Enter an output file name: ";
        cin >> UserFile;
        User.open(UserFile); 
	for (int i= 0; i < 26; i++){
                User << char(i + 65) << ": " << upperCaseCount[i] + lowerCaseCount[i] << endl;
        }
	cout << "Letter count saved to " << UserFile << endl;
	User.close();
}

void count_letters(ifstream &inMyStream, string lineBuffer){
    if (inMyStream.is_open()) 
    {
       
       int upperCaseCount[26] = {0};
           int lowerCaseCount[26] = {0};

       //read the text file
       while (!inMyStream.eof() )
       {
    	   //get a line of text
           getline (inMyStream, lineBuffer);
           //read through each letter in the lineBuffer
           char oneLetter;
           for(unsigned n = 0; n < lineBuffer.length(); ++n){
   		oneLetter = char( lineBuffer[n] ); // get a letter
   		if (oneLetter >= 'A' && oneLetter <='Z') {
     			upperCaseCount[int(oneLetter)- 'A']++;
   		}
   		else if (oneLetter >= 'a' && oneLetter <='z') { 
     			lowerCaseCount[int(oneLetter)- 'a']++;
   			}
	   }
        }
	output_letters(upperCaseCount, lowerCaseCount);	
}
        else cout << "File Error: Open Failed" << endl;
}

