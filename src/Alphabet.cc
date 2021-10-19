/**
 * PROJECT HEADER
 * @file Alphabet.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 19/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#include "../include/Alphabet.h"

Alphabet::Alphabet(set<Symbol>& alphabet) {
  this->setAlphabet(alphabet);
}


void Alphabet::setAlphabet(set<Symbol>& alphabet) {
  alphabet_ = alphabet;
}


set<Symbol> Alphabet::getAlphabet() const {
  return alphabet_;
}


void Alphabet::addSymbol(Symbol& symbol) {
  alphabet_.insert(symbol);
}



int Alphabet::getSize() const {
  return alphabet_.size();
}


void Alphabet::printAlphabet() {
  cout << "Alphabet -> ";
  for (auto symbol : alphabet_)
    cout << symbol.getSymbol() << " ";
  cout << endl;
}
