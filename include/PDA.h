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


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

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

  private:
    set<State*> states_;
    Alphabet alphabet_;
    Alphabet stackAlphabet_;
    State initialState_;
    Symbol inialStackSymbol_;
    stack<Symbol> stack_;
    set<State*> acceptationStates_;
};

#endif // PDA_H