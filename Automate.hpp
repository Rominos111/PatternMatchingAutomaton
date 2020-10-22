#ifndef TP1_AUTOMATE_HPP
#define TP1_AUTOMATE_HPP

#include <string>
#include <vector>
#include <iostream>

#include "Etat.hpp"
#include "Lien.hpp"

class Automate {
public:
    Automate();

    explicit Automate(std::vector<std::string>& words);
    Etat* entree;
    Etat* eCour;

    std::string chaine;
    void jump(char car);
    std::vector<std::string> get_etats_finaux() const;
    std::string toString();
};

#endif //TP1_AUTOMATE_HPP
