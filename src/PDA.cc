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
  for (auto state : states_)
    cout << "State -> " << state->getIdentifier() << " Initial:" << state->getIsInitial() << " Acceptation:" << state->getIsAcceptation() << endl;
  cout << endl;
}


void PDA::printPDATuple() {

}


bool PDA::isComment(string lineInfo) {
  if (lineInfo.front() == '#') return true; 
  return false;
}


void PDA::setTapeAlphabet(string lineInfo) {
  stringstream symbol(lineInfo);
  set<Symbol> symbols;
  string token;
  while (getline(symbol, token, ' ')) {
    Symbol PDASymbol(token);
    symbols.insert(PDASymbol);
  }
  this->tapeAlphabet_.setAlphabet(symbols);
}


bool PDA::hasState(string stateIdentifier, vector<State*> states) {
  for (auto state: states) {
    if (state->getIdentifier() == stateIdentifier) {
      return true;
    }
  }
  return false;
}


void PDA::setStackAlphabet(string lineInfo) {
  stringstream stackSymbol(lineInfo);
  set<Symbol> stackSymbols;
  string token;
  while (getline(stackSymbol, token, ' ')) {
    Symbol stackSymbol(token);
    stackSymbols.insert(stackSymbol);
  }
  this->stackAlphabet_.setAlphabet(stackSymbols);
}


void PDA::readFile(string inputFileName) {
  ifstream file(inputFileName);
  string lineInfo;
  string error;

  if (!file.is_open()) {
    error = "\nERROR: The inputfile  " + inputFileName + " could not be opened\n";
    throw error;
  } else {
    cout << "\tThe inputfile " << inputFileName << " was successfully readed...\n";


    // Comments control
    getline(file, lineInfo);
    while (this->isComment(lineInfo)) {
      getline(file, lineInfo);
    }


    // Auxiliar set of states
    string token;
    stringstream element(lineInfo);
    vector<State*> states;
    while (getline(element, token, ' ')) {
      State* state = new State(token, false, false);
      states.push_back(state);
    }


    // PDA Alphabet
    getline(file, lineInfo);
    this->setTapeAlphabet(lineInfo);


    // Stack Alphabet
    getline(file, lineInfo);
    this->setStackAlphabet(lineInfo);


    // Initial state
    getline(file, lineInfo);
    if (hasState(lineInfo, states)) {
      for (auto state : states) {
        if (state->getIdentifier() == lineInfo) {
          state->setInitial(true);
        }
      }
    } else {
      error = "The readed state is not part of the PDA's states\n";
      throw error;
    }


    // Initial stack symbol
    getline(file, lineInfo);
    Symbol symbol(lineInfo);
    if (!this->stackAlphabet_.hasSymbol(symbol)) {
      error = "The readed symbol is not part of the stack alphabet\n";
      throw error;
    }


    // Acceptation
    getline(file, lineInfo);
    stringstream ss(lineInfo); 
    while (ss >> token) {
      if (hasState(token, states) == true) {
        for (auto state: states) {
          if (state->getIdentifier() == token) { 
            state->setAcceptation(true);
          }
          this->states_.insert(state);
        }
      } else {
        error = "The readed state is not part of the PDA's states\n";
        throw error;
      }
    }
    this->printStates();
    

    // Transitions
    Transition transition;
    getline(file, lineInfo);
    while (!lineInfo.empty()) {
      stringstream ss(lineInfo); 

      // Current state
      ss >> token;
      cout << token << " ";
      State* state = new State(token);
      auto it = this->states_.find(state);
      // cout << "actual " << state->getIdentifier() << " viejo " << (*it)->getIdentifier();
      if (it != this->states_.end()) {
        transition.setCurrentState(state);
      } else {
        error = "The readed state is not part of the PDA's states\n";
        throw error;
      }

      // Input symbol
      ss >> token;
      cout << token << " ";

      // Stack top
      ss >> token;
      cout << token << " ";

      stringstream elements(lineInfo); 
      while (elements >> token) {
        cout << token << " ";
      }
      cout << endl;
      getline(file, lineInfo);
    }
  }
}