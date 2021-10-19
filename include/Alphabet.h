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

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>

#include "./Symbol.h"

using namespace std;
#pragma once

class Alphabet {
  public:
    Alphabet() {};
    Alphabet(set<Symbol>& symbols);
    void setAlphabet(set<Symbol>& symbols);
    set<Symbol> getAlphabet() const;
    void addSymbol(Symbol& symbol);
    int getSize() const;
    void printAlphabet();

  private:
    set<Symbol> alphabet_;

};

#endif // ALPHABET_H