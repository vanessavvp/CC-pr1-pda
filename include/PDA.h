/**
 * PROJECT HEADER
 * @file PDA.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#ifndef PDA_H
#define PDA_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class PDA {
  public:
    PDA(string inputFileName);

  private:
    void readFile(string inputFileName);
};

#endif // PDA_H