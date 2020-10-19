#ifndef TP1_TP_HPP
#define TP1_TP_HPP

#include <vector>
#include <string>
#include <iostream>

class Occurrence {
public:
    std::string pattern;
    int index;
};

std::vector<Occurrence*> match_patterns(std::string& text, std::vector<std::string>& words);

std::vector<Occurrence*> quick_match(std::string& text, std::vector<std::string>& words);

class Etat;

class Lien {
public:
    Lien(char etiquette, Etat* next) : etiquette(etiquette), next(next) {}

    char etiquette;
    Etat* next;

    bool jump_available(char c);
};

class Etat {
public:
    explicit Etat(std::vector<Lien>& liens) : final(), liens(liens) {}

    Etat(std::vector<std::string>& final, std::vector<Lien>& liens) : final(final), liens(liens) {}

    explicit Etat(std::vector<std::string>& final) : final(final), liens() {}

    Etat() : final(), liens() {}

    std::vector<std::string> final;
    std::vector<Lien> liens;

    void jump_possible(char car);

    Lien* getLien(char c);
};

class Automate {
public:
    Automate();

    explicit Automate(std::vector<std::string>& words);
    Etat* entree;
    Etat* eCour;

    std::string chaine;
    void jump(char car);
    std::vector<std::string> get_etats_finaux();
};

std::vector<Occurrence*> struct_match(std::string& text, Automate& au);

#endif //TP1_TP_HPP
