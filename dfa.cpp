// Name: Matt Riley
// File Name: dfa.cpp
// Date: 3-4-24
// Description: This program performs all of the tasks of the DFA.

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

#include "dfa.h"


using namespace std;

    vector<string> states;
    vector<char> alphabet;
    map<pair<string, char>, string> transitions; // (string state | char inputSymbol) , string nextState
    string initialState;
    vector<string> finalStates;
    string currentState;

    DFA :: DFA()
    {

    }


    void DFA :: addState(string state)
    {
        states.insert(states.end(), state);
    }

    void DFA :: addAlphabetSymbol(char symbol)
    {
        alphabet.insert(alphabet.end(), symbol);
    }

    void DFA :: addTransition(string transition)
    {
        string firstState;
        char symbol;
        string symbolStr;
        string secondState;

        firstState = transition.substr(0,2);

        symbolStr = transition.substr(3,1);
        symbol = symbolStr.front();

        secondState = transition.substr(5,2);

        transitions[make_pair(firstState, symbol)] = secondState;
    }

    void DFA :: setInitialState(string initial)
    {
        initialState = initial;
    }

    void DFA :: addFinalState(string final)
    {
        finalStates.insert(finalStates.end(), final);
    }

    void DFA :: displayDFA() //Display DFA description
    {
        cout << "----------D F A----------" << endl 
             << "<states>" << endl;
        for(int i = 0; i < states.size(); i++)
            cout << states[i] << " ";
        cout << endl
             << "<alphabet>" << endl;
        for(int i = 0; i < alphabet.size(); i++)
            cout << alphabet[i] << " ";
        cout << endl
             << "<transitions>" << endl;
        for(const auto& pair : transitions)
        {
            const auto& key = pair.first;
            const auto& value = pair.second;

            cout << "(" << key.first << ", " << key.second << ") -> " << value << endl;
        }
        cout << "<initial state>" << endl
             << initialState << endl
             << "<final states>" << endl;
        for(int i = 0; i < finalStates.size(); i++)
            cout << finalStates[i] << " ";
        cout << endl << "--------------------------" << endl << endl;
    }

    void DFA :: setCurrentToInitial() //Set current state to initial state
    {
        currentState = initialState;
    }

    void DFA :: makeTransition(char symbol) //Make transition from current state to the next state for given input symbol
    {
        pair<string, char> tempKey = make_pair(currentState, symbol);
        auto element = transitions.find(tempKey);

        currentState = element->second;

        cout << "-" << symbol << "->[" << currentState << "]";

    }

    string DFA :: getCurrentState() 
    {
        return currentState;
    }

    bool DFA :: isValid(char symbol) //Check if symbol is valid
    {
        pair<string, char> testKey = make_pair(currentState, symbol);

        return transitions.find(testKey) != transitions.end();
    }

    bool DFA :: isFinal(string state) //Check if state is a final state
    {
        for(int i = 0; i < finalStates.size(); i++)
        {
            if(finalStates[i] == state)
                return true;

        }

        return false;
    }












