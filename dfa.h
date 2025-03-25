// Name: Matt Riley
// File Name: dfa.h
// Date: 3-4-24
// Description: This program stores the declarations of methods for the DFA class.



#ifndef DFA_H
#ifndef DFA_H   //I have no idea why I need two of these but I do for some reason.
#define DFA_H

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class DFA 
{
    public:

    vector<string> states;
    vector<char> alphabet;
    map<pair<string, char>, string> transitions; // (string state | char inputSymbol) , string nextState
    string initialState;
    vector<string> finalStates;
    string currentState;

    DFA();
    

    void addState(string state);

    void addAlphabetSymbol(char symbol);

    void addTransition(string transition);

    void setInitialState(string initial);

    void addFinalState(string final);

    void displayDFA();

    void setCurrentToInitial();

    void makeTransition(char symbol);

    string getCurrentState();

    bool isValid(char symbol);

    bool isFinal(string state);









};

#endif
#endif  // Similar issue with this. I have no idea.
