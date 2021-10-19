/**
 * PROJECT HEADER
 * @file PDA.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#include "../include/PDA.h"

PDA::PDA(string inputFileName) {
  readFile(inputFileName);
}


void PDA::printStates() {
  cout << "States -> ";
  for (auto state : states_)
    cout << state->getIdentifier() << " IsInitial: " << state->getIsInitial() << " ";
  cout << endl;
}


void PDA::readFile(string inputFileName) {
  ifstream file(inputFileName);
  string lineInfo;

  if (!file.is_open()) {
    cerr << "\nERROR: The inputfile  " << inputFileName << " could not be opened\n";
    exit(1);
  } else {
    cout << "\tThe inputfile " << inputFileName << " was successfully readed...\n";

    // Comments control
    getline(file, lineInfo);
    while (lineInfo.front() == '#') {
      getline(file, lineInfo);
    }

    // Set of states
    string token;
    stringstream element(lineInfo);
    //set<State*> states; 
    vector<State*> states;
    while (getline(element, token, ' ')) {
      State* state = new State(token, false, false);
      // cout << "Estado: " << token << endl;
      // states.insert(state);
      states.push_back(state);
    }
    // this->states_ = states;
    // this->printStates();

    // PDA Alphabet
    getline(file, lineInfo);
    stringstream symbol(lineInfo);
    set<Symbol> symbols;
    while (getline(symbol, token, ' ')) {
      Symbol PDASymbol(token);
      // cout << "Símbolo alfabeto PDA: " << PDASymbol.getSymbol() << endl;
      symbols.insert(PDASymbol);
    }
    this->alphabet_.setAlphabet(symbols);
    this->alphabet_.printAlphabet();

    // Stack Alphabet
    getline(file, lineInfo);
    stringstream stackSymbol(lineInfo);
    set<Symbol> stackSymbols;
    while (getline(stackSymbol, token, ' ')) {
      Symbol stackSymbol(token);
      // cout << "Símbolo alfabeto pila: " << stackSymbol.getSymbol() << endl;
      stackSymbols.insert(stackSymbol);
    }
    this->stackAlphabet_.setAlphabet(stackSymbols);
    this->stackAlphabet_.printAlphabet();

    // Initial state
    getline(file, lineInfo);
    bool found = false;
    for (auto state : states) {
      if (state->getIdentifier() == lineInfo) {
        state->setInitial(true);
        found = true;
      }
      this->states_.insert(state);
    }
    if (!found) cerr << "The readed state is not part of the PDA's states\n";
    this->printStates();
  }
}