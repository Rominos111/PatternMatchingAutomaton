#ifndef TP1_MAIN_HPP
#define TP1_MAIN_HPP

#include <iostream>

#include "Occurrence.hpp"
#include "State.hpp"
#include "Link.hpp"
#include "Automaton.hpp"

#define DEBUG false

std::vector<Occurrence*> basicMatch(const std::string& text, const std::vector<std::string>& words);

std::vector<Occurrence*> quickMatch(const std::string& text, const std::vector<std::string>& words);

std::vector<Occurrence*> automatonMatch(const std::string& text, Automaton& au);

bool testMatchs(const std::string& text, const std::vector<std::string>& words);

int main();

#endif //TP1_MAIN_HPP
