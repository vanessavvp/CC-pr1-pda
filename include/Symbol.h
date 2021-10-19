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
    Symbol(string symbol);
    string getValue();
    void setValue(string symbol);
    void print();
    
  private:
    string symbol_;
};

#endif // !SYMBOL_H