/**
 * PROJECT HEADER
 * @file State.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#ifndef STATE_H
#define STATE_H


#include <iostream>
#include <string>
#include <vector>

#include "./Transition.h"

using namespace std;

#pragma once

class Transition;
class State {
  public:
    State();
    State(string identifier);
    State(string identifier, bool isAcceptation, bool isInitial);
    string getIdentifier() const;
    bool getIsAcceptation() const;
    bool getIsInitial() const;
    vector<Transition> getTransitions() const;
    void setAcceptation(bool isAcceptation);
    void setInitial(bool isInitial);
    void setTransitions(vector<Transition>& transitions);
    void addTransition(Transition& transition);
    bool operator<(State const& other) const;

  private:
    string identifier_;
    bool isAcceptation_;
    bool isInitial_;
    vector<Transition> transitions_;
};

#endif // !STATE_H