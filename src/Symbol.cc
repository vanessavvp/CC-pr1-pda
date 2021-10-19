/**
 * PROJECT HEADER
 * @file symbol.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#include "../include/Symbol.h"

Symbol::Symbol(string symbol) {
  symbol_ = symbol;
}


string Symbol::getValue() {
  return symbol_;
}


void Symbol::setValue(string symbol) {
  symbol_ = symbol;
}


void Symbol::print() {
  cout << "Symbol: " << symbol_ << endl;
}