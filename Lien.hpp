//
// Created by Romain on 19/10/2020.
//

#ifndef TP1_LIEN_HPP
#define TP1_LIEN_HPP

#include "Etat.fwd.hpp"
#include "Lien.fwd.hpp"

class Lien {
public:
    Lien(char etiquette, Etat* next) : etiquette(etiquette), next(next) {}

    bool jump_available(char c);

    char etiquette;
    Etat* next;
};

#endif //TP1_LIEN_HPP
