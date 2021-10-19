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
    //Transition(State currentState, Symbol symbolToRead, Symbol topStackSymbol, State nextState, vector<Symbol> symbolsToIntroduce);

  private:
    //State currentState_;
    Symbol symbolToRead_;
    Symbol topStackSymbol_;
    //State nextState_;
    vector<Symbol> symbolsToIntroduce_;
};

#endif // !TRANSITION_H
