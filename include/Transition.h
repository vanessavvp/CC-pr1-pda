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
    Transition(State& currentState, Symbol symbolToRead, Symbol topStackSymbol, State& nextState, vector<Symbol> symbolsToIntroduce);
    void setCurrentState(State& currentState);
    void setSymbolToRead(Symbol symbolToRead);
    void setTopStackSymbol(Symbol topStackSymbol);
    void setNextState(State& nextState);
    void setSymbolsToIntroduce(vector<Symbol> symbolsToIntroduce);
    State* getCurrentState();
    Symbol getSymbolToRead();
    Symbol getTopStackSymbol();
    State* getNextState();
    vector<Symbol> getSymbolsToIntroduce();
    void printTransition();
    bool isPossibleToTransit(string symbolToRead, Symbol topStackSymbol);

  private:
    State* currentState_;
    Symbol symbolToRead_;
    Symbol topStackSymbol_;
    State* nextState_;
    vector<Symbol> symbolsToIntroduce_;
};

#endif // !TRANSITION_H
