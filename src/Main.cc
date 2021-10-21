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
  cout << "\n\tPushdown Automata -> Acceptance by final state" << endl;
  try {
    string inputFileName, inputString, menuRepeated;
    cout << "\nPlease, introduce the input file path of the automata formal definition: ";
    cin >> inputFileName;
    do {
      cout << "Enter the input string for the automata: ";
      cin >> inputString;

      PDA PDA(inputFileName);
      PDA.start(inputString);

      cout << "\nDo you want to repeat the process [y/n]: ";
      cin >> menuRepeated;
    } while ((menuRepeated == "y") || (menuRepeated == "Y"));
    
     
  } catch(const string error) {
    cerr << error << endl;
  }
}