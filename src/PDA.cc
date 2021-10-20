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
    cout << "State -> " << state.getIdentifier() << " Initial:" << state.isInitial() << " Acceptation:" << state.isAcceptation() << endl;
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


bool PDA::hasState(string stateIdentifier, vector<State> states) {
  for (auto state: states) {
    if (state.getIdentifier() == stateIdentifier) {
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
    vector<State> states;
    while (getline(element, token, ' ')) {
      State state(token, false, false);
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
      for (auto &state : states) {
        if (state.getIdentifier() == lineInfo) {
          state.setInitial(true);
          this->currentState_ = state;
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
    } else {
      this->stack_.push(symbol);
    }


    // Acceptation
    getline(file, lineInfo);
    stringstream ss(lineInfo); 
    while (ss >> token) {
      if (hasState(token, states) == true) {
        for (auto &state: states) {
          if (state.getIdentifier() == token) { 
            state.setAcceptation(true);
          }
          // this->states_.insert(state);
        }
      } else {
        error = "The readed state is not part of the PDA's states\n";
        throw error;
      }
    }
    

    // Transitions
    vector<string> tempStack;
    Transition transition;
    getline(file, lineInfo);
    while (!lineInfo.empty()) {
      stringstream ss(lineInfo); 

      // Current state
      ss >> token;
      // cout << token << " ";
      State state(token);
      vector<State>::iterator it = find(states.begin(), states.end(), state);
      if (it != states.end()) {
        transition.setCurrentState(state.getIdentifier());
      } else {
        error = "The readed state is not part of the PDA's states\n";
        throw error;
      }

      // Input symbol
      ss >> token;
      // cout << token << " ";
      transition.setSymbolToRead(token);

      // Stack top
      ss >> token;
      // cout << token << " ";
      transition.setTopStackSymbol(token);

      // Next State
      ss >> token;
      // cout << token << " ";
      State nextState(token);
      it = find(states.begin(), states.end(), nextState);
      if (it != states.end()) {
        transition.setNextState(nextState.getIdentifier());
      } else {
        error = "The readed state is not part of the PDA's states\n";
        throw error;
      }

      // Stack Input
      vector<Symbol> inputSymbols;
      while (ss >> token) {
        // cout << token << " ";
        Symbol symbol(token);
        inputSymbols.push_back(token);
      }
      transition.setSymbolsToIntroduce(inputSymbols);
      // cout << endl;
      getline(file, lineInfo);

      // Including transitions to a state
      it = find(states.begin(), states.end(), State(transition.getCurrentState()));
      if (it != states.end()) {
        (*it).addTransition(transition);
      }
    }
    for (auto state: states) {
      auto it = find(states.begin(), states.end(), state);
      this->states_.insert(*it);
      // cout << "Estado " << state.getIdentifier() << endl;
    }
    /*for (auto state: states_) {
      vector<Transition> transitions = state.getTransitions();
      for (auto transition: transitions) {
        transition.printTransition();
      }
    }*/
  }
}


void PDA::start(string inputString) {
  int headerPos = 0;
  if (recursiveStart(inputString, headerPos, currentState_, stack_)) {
    cout << "\nInput string is accepted!\n";
  } else {
    cout << "\nInput string is rejected!\n";
  }
}


void PDA::printStack(stack<Symbol>& stack) {

}


bool PDA::recursiveStart(string symbol, int headerPos, State& currentState, stack<Symbol> stack) {
  // cout << "conjunto de estados size " << states_.size() << endl;
  auto current = find(states_.begin(), states_.end(), currentState);
  cout << "Current state: " << current->getIdentifier() << " Tape: " << symbol << " Stack: ";
  if ((headerPos >= symbol.length()) && (current->isAcceptation())) {
    return true;
  }
  vector<Transition> possibleTransitions = current->getTransitions();
  for (auto transition: possibleTransitions) {
    //Symbol top(stack.top());
    cout << "top " << stack.top().getSymbol() << endl;
    transition.printTransition();
    if (transition.isPossibleToTransit(string(1, symbol[headerPos]), stack.top())) {
      // Cosas con la pila
    }
  }
  return false;
}