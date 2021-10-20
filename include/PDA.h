/**
 * PROJECT HEADER
 * @file PDA.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#ifndef PDA_H
#define PDA_H


#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <algorithm>
#include <utility>

#include "./Alphabet.h"
#include "./State.h"
#include "./Transition.h"

using namespace std;

#pragma once
class PDA {
  public:
    PDA(string inputFileName);
    void readFile(string inputFileName);
    void printStates();
    void printPDATuple();
    bool isComment(string lineInfo);
    void setTapeAlphabet(string lineInfo);
    void setStackAlphabet(string lineInfo);
    bool hasState(string stateIdentifier, vector<State> states);
    void start(string inputString);
    bool recursiveStart(string symbol, int headerPos, State& currentState, stack<Symbol> stack);
    void printStack(stack<Symbol>& stack);

  private:
    set<State> states_;
    Alphabet tapeAlphabet_;
    Alphabet stackAlphabet_;
    State currentState_;
    Symbol initialStackSymbol_;
    stack<Symbol> stack_;
};

#endif // PDA_H