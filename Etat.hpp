#ifndef TP1_ETAT_HPP
#define TP1_ETAT_HPP

#include <string>
#include <vector>

#include "Etat.fwd.hpp"
#include "Lien.fwd.hpp"

class Etat {
public:
    explicit Etat(std::vector<Lien*>& liens) : final(), liens(liens) {}

    Etat(std::vector<std::string>& final, std::vector<Lien*>& liens) : final(final), liens(liens) {}

    explicit Etat(std::vector<std::string>& final) : final(final), liens() {}

    Etat() : final(), liens() {}

    void jump_possible(char car);

    Lien* getLien(char c);

    void addLien(Lien* lien);

    std::vector<std::string> final;
    std::vector<Lien*> liens;
};

#endif //TP1_ETAT_HPP
