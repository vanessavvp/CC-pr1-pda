/**
 * PROJECT HEADER
 * @file symbol.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

using namespace std;

class Symbol {
  public:
    Symbol() {};
    Symbol(string symbol);
    string getSymbol();
    void setSymbol(string symbol);
    void print();
    bool operator<(Symbol const& other) const;
    
  private:
    string symbol_;
};

#endif // !SYMBOL_H