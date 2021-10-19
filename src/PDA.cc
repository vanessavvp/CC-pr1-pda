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
    stringstream state(lineInfo);
    while (getline(state, token, ' ')) {
      cout << "Estado: " << token << endl;
    }
    
    // PDA Alphabet
    getline(file, lineInfo);
    stringstream symbol(lineInfo);
    set<Symbol> symbols;
    while (getline(symbol, token, ' ')) {
      Symbol PDASymbol(token);
      cout << "Símbolo alfabeto PDA: " << PDASymbol.getSymbol() << endl;
      symbols.insert(PDASymbol);
    }
    Alphabet PDAAlphabet(symbols);
    PDAAlphabet.printAlphabet();

    // Stack Alphabet
    getline(file, lineInfo);
    stringstream stackSymbol(lineInfo);
    set<Symbol> stackSymbols;
    while (getline(stackSymbol, token, ' ')) {
      Symbol stackSymbol(token);
      cout << "Símbolo alfabeto pila: " << stackSymbol.getSymbol() << endl;
      stackSymbols.insert(stackSymbol);
    }
    Alphabet stackAlphabet(stackSymbols);
    stackAlphabet.printAlphabet();
  }
}