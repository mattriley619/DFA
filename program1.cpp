// Name: Matt Riley
// File Name: program1.cpp
// Date: 3-4-24
// Description: This program reads info from a file and constructs a DFA. 
//              It then takes input symbols from the user and determines whether that string is accepted or rejected.


#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

#include "dfa.h"


using namespace std;

int main(int argc, char* argv[]) 
{
    ifstream inFile;
    string fileName;
    string inString;
    DFA dfa;
    char inChar;

    if(argc == 1)
    {
        cout << "usage: <prog_name> <file_name>" << endl;
        exit(1);
    }
    else if(argc == 2)
    {
        fileName = argv[1];
        inFile.open(fileName);

        if(!inFile.is_open())
        {
            cout << "Automata file could not be opened!" << endl;
            exit(1);
        }

        getline(inFile, inString);  // <states>

        getline(inFile, inString); // first state
        while(inString != "<alphabet>")
        {
            dfa.addState(inString);
            getline(inFile, inString);
        }

        getline(inFile, inString); //first alphabet symbol
        while(inString != "<transitions>")
        {
            inChar = inString.front();
            dfa.addAlphabetSymbol(inChar);
            getline(inFile, inString);
        }

        getline(inFile, inString); //first transition
        while(inString != "<initial state>")
        {
            dfa.addTransition(inString);
            getline(inFile, inString);
        }

        getline(inFile, inString); // initial state
        dfa.setInitialState(inString);

        getline(inFile, inString);// <final states>

        getline(inFile, inString);
        while(!inFile.eof())
        {
            dfa.addFinalState(inString);
            getline(inFile, inString);
        }
        dfa.addFinalState(inString);
       
       inFile.close();
     }

    string processStr;
    int flag = 0;

    dfa.displayDFA();

    while(true)
    {
        dfa.setCurrentToInitial();

        cout << "Enter a string to process (Ctrl^C to end): ";
        getline(cin, processStr);
        cout << endl << endl << "[" << dfa.currentState << "]";

        for(int i = 0; i < processStr.size(); i++)
        {
            if(processStr == "")
            {
                cout << " : Rejected";
                flag = 1;
                break;
            }


            if(dfa.isValid(processStr[i]))
            {
                dfa.makeTransition(processStr[i]);

            }
            else
            {
                cout << "-" << processStr[i] << "-> ? : Rejected" << endl << endl;
                flag = 1;
                break;
            }


        }
        
        if(flag == 0)
        {
            if(dfa.isFinal(dfa.currentState))
                cout << " : Accepted" << endl << endl;
            else
                cout << " : Rejected" << endl << endl;
        }

        flag = 0;
        


    }







}