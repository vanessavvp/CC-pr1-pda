/**
 * PROJECT HEADER
 * @file Main.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#include "../include/PDA.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  cout << "\n\tPushdown Automata" << endl;
  string inputFileName = argv[1];
  PDA PDA(inputFileName);
}