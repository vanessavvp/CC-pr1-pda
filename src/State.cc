/**
 * PROJECT HEADER
 * @file State.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 18/10/2021
 * Subject: Complejidad Computacional
 * Practice: Number º1
 * Purpose: Implementing a Pushdown Automata
 */

#include "../include/State.h"

State::State() {
  // state_ = NULL;
  identifier_ = "0";
  isAcceptation_ = false;
  isInitial_ = false;
}


State::State(string identifier) {
  // state_ = NULL;
  identifier_ = identifier;
}


State::State(string identifier, bool isAcceptation, bool isInitial) {
  // state_ = NULL;
  identifier_ = identifier;
  isAcceptation_ = isAcceptation;
  isInitial_ = isInitial;
}


/*State* State::getState() const {
  return state_;
}*/


string State::getIdentifier() const {
  return identifier_;
}


/*vector<Transition> State::getTransitions() const {
  return transitions_;
}*/


bool State::getIsAcceptation() const {
  return isAcceptation_;
}


bool State::getIsInitial() const {
  return isInitial_;
}


/*void State::setState(State* state) {
  state_ = state;
}*/


void State::setAcceptation(bool isAcceptation) {
  isAcceptation_ = isAcceptation;
}


void State::setInitial(bool isInitial) {
  isInitial_ = isInitial;
}


/*void State::setTransitions(vector<Transition> transitions) {
  transitions_ = transitions;
}*/


/*void State::addTransition(Transition transition) {
  transitions_.push_back(transition);
}
*/

/*bool State::operator<(State const& other) const {
  if (other.state_ < this->state_) 
    return true;
  return false;
}*/
