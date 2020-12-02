#ifndef TP1_MAIN_HPP
#define TP1_MAIN_HPP

#include <iostream>

#include "Occurrence.hpp"
#include "State.hpp"
#include "Link.hpp"
#include "Automaton.hpp"

#define DEBUG false
#define BENCHMARK false

/**
 * Match basique
 *
 * @param text Texte
 * @param words Mots
 * @return Occurrences
 */
std::vector<Occurrence*> basicMatch(const std::string& text, const std::vector<std::string>& words);

/**
 * Match basique
 *
 * @param text Texte
 * @param words Mots
 * @return Occurrences
 */
std::vector<Occurrence*> automatonMatch(const std::string& text, Automaton& au);

/**
 * Teste notre algorithme
 *
 * @param text Texte
 * @param words Mots
 * @return OK ou non
 */
bool testMatchs(const std::string& text, const std::vector<std::string>& words);

int main();

#endif //TP1_MAIN_HPP
