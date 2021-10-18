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
    while (getline(symbol, token, ' ')) {
      cout << "Símbolo alfabeto PDA: " << token << endl;
    }

    // Stack Alphabet
    getline(file, lineInfo);
    stringstream stackSymbol(lineInfo);
    while (getline(stackSymbol, token, ' ')) {
      cout << "Símbolo alfabeto pila: " << token << endl;
    }

    

  }
  /*ifstream file;

  file.open(inputFile);
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    exit(1);
  }
  string line;
  int i = 0;
  while (getline(file, line)) {
    if (i == 0) {
      stringstream ss(line);
      string token;
      while (getline(ss, token, ' ')) {
        if (token == "Q") {
          getline(ss, token, ' ');
          this->Q = stoi(token);
        } else if (token == "Sigma") {
          getline(ss, token, ' ');
          this->Sigma = stoi(token);
        } else if (token == "Delta") {
          getline(ss, token, ' ');
          this->Delta = stoi(token);
        } else if (token == "Q0") {
          getline(ss, token, ' ');
          this->Q0 = stoi(token);
        } else if (token == "F") {
          getline(ss, token, ' ');
          this->F = stoi(token);
        }
      }
    } else {
      stringstream ss(line);
      string token;
      while (getline(ss, token, ' ')) {
        if (token == "q") {
          getline(ss, token, ' ');
          this->q.push_back(stoi(token));
        } else if (token == "sigma") {
          getline(ss, token, ' ');
          this->sigma.push_back(token);
        } else if (token == "delta") {
          getline(ss, token, ' ');
          this->delta.push_back(stoi(token));
        } else if (token == "q0") {
          getline(ss, token, ' ');
          this->q0 = stoi(token);
        } else if (token == "f") {
          getline(ss, token,
      */
}