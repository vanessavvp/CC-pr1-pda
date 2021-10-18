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

#include <iostream>
#include <string>

using namespace std;

class Symbol {
  public:
    Symbol(string symbol);
    string getSymbol();
    void setSymbol(string symbol);
    void print();
    
  private:
    string symbol_;
};