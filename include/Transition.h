/**
 * PROJECT HEADER
 * @file Transition.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 19/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <vector>

#include "./Symbol.h"
#include "./State.h"

using namespace std;
#pragma once

class State;
class Transition {
  public:
    Transition() {};
    Transition(string currentState, Symbol symbolToRead, Symbol topStackSymbol, string nextState, vector<Symbol> symbolsToIntroduce);
    void setCurrentState(string currentState);
    void setSymbolToRead(Symbol symbolToRead);
    void setTopStackSymbol(Symbol topStackSymbol);
    void setNextState(string nextState);
    void setSymbolsToIntroduce(vector<Symbol> symbolsToIntroduce);
    string getCurrentState();
    Symbol getSymbolToRead();
    Symbol getTopStackSymbol();
    string getNextState();
    vector<Symbol> getSymbolsToIntroduce();
    void printTransition();
    bool isPossibleToTransit(string symbolToRead, Symbol topStackSymbol);

  private:
    string currentState_;
    Symbol symbolToRead_;
    Symbol topStackSymbol_; 
    string nextState_;
    vector<Symbol> symbolsToIntroduce_;
};

#endif // !TRANSITION_H
