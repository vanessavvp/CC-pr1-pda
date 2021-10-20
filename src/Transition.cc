/**
 * PROJECT HEADER
 * @file Transition.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 19/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#include "../include/Transition.h"

Transition::Transition(string currentState, Symbol symbolToRead, Symbol topStackSymbol, string nextState,
                      vector<Symbol> symbolsToIntroduce) {
  currentState_ = currentState;
  symbolToRead_ = symbolToRead;
  topStackSymbol_ = topStackSymbol;
  nextState_ = nextState;
  symbolsToIntroduce_ = symbolsToIntroduce;
}


void Transition::setCurrentState(string currentState) {
  currentState_ = currentState;
}


void Transition::setSymbolToRead(Symbol symbolToRead) {
  symbolToRead_ = symbolToRead;
}


void Transition::setTopStackSymbol(Symbol topStackSymbol) {
  topStackSymbol_ = topStackSymbol;
}


void Transition::setNextState(string nextState) {
  nextState_ = nextState;
}


void Transition::setSymbolsToIntroduce(vector<Symbol> symbolsToIntroduce) {
  symbolsToIntroduce_ = symbolsToIntroduce;
}


string Transition::getCurrentState() {
  return currentState_;
}


Symbol Transition::getSymbolToRead() {
  return symbolToRead_;
}


Symbol Transition::getTopStackSymbol() {
  return topStackSymbol_;
}


string Transition::getNextState() {
  return nextState_;
}


vector<Symbol> Transition::getSymbolsToIntroduce() {
  return symbolsToIntroduce_;
}


void Transition::printTransition() {
  cout << "Current state: " << currentState_ << endl;
  cout << "Symbol to read: " << symbolToRead_.getSymbol() << endl;
  cout << "Top stack symbol: " << topStackSymbol_.getSymbol() << endl;
  cout << "Next state: " << nextState_ << endl;
  cout << "Symbol to read: \n"; 
  for (auto symbol : symbolsToIntroduce_) {
    cout << " " << symbol.getSymbol() << endl;
  }
  cout << endl;
}


bool Transition::isPossibleToTransit(string symbolToRead, Symbol topStackSymbol) {
  if (((symbolToRead == this->symbolToRead_.getSymbol()) || (symbolToRead == ".")) &&
      ((topStackSymbol == this->topStackSymbol_) || (topStackSymbol.getSymbol() == "."))) {
    cout << "Is possible to transit!\n";
    return true;
  }
  cout << "Is not possible to transit!\n";
  return false;
}

