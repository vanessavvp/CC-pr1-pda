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
  state_ = NULL;
  identifier_ = "0";
  isAcceptation_ = false;
  isInitial_ = false;
}


State::State(string identifier, bool isAcceptation, bool isInitial) {
  state_ = NULL;
  identifier_ = "0";
  isAcceptation_ = false;
  isInitial_ = false;
}


State* State::getState() const {
  return state_;
}


string State::getIdentifier() const {
  return identifier_;
}


vector<Transition> State::getTransitions() const {
  return transitions_;
}


void State::setState(State* state) {
  state_ = state;
}


void State::setAcceptation(bool isAcceptation) {
  isAcceptation_ = isAcceptation;
}


void State::setInitial(bool isInitial) {
  isInitial_ = isInitial;
}


void State::setTransitions(vector<Transition>& transitions) {
  transitions_ = transitions;
}


void State::addTransition(Transition& transition) {
  transitions_.push_back(transition);
}