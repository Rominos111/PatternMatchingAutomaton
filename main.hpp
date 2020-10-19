#ifndef TP1_MAIN_HPP
#define TP1_MAIN_HPP

#include "Occurrence.hpp"
#include "Etat.hpp"
#include "Lien.hpp"
#include "Automate.hpp"

std::vector<Occurrence*> match_patterns(std::string& text, std::vector<std::string>& words);

std::vector<Occurrence*> quick_match(std::string& text, std::vector<std::string>& words);

std::vector<Occurrence*> struct_match(std::string& text, Automate& au);

#endif //TP1_MAIN_HPP
