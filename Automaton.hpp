#ifndef TP1_AUTOMATON_HPP
#define TP1_AUTOMATON_HPP

#include <string>
#include <vector>
#include <iostream>

#include "State.hpp"
#include "Link.hpp"

/**
 * Automaton
 */
class Automaton {
public:
    /**
     * Constructeur par défaut, pour l'exemple
     */
    Automaton();

    ~Automaton();

    /**
     * Constructeur
     *
     * @param words Mots
     */
    explicit Automaton(const std::vector<std::string>& words);

    /**
     * Saute à un certain état
     *
     * @param car Caractère
     */
    void jump(char car);

    /**
     * Récupère les états finaux
     *
     * @return États finaux
     */
    [[nodiscard]] std::vector<std::string> getRecognizedStrings() const;

    /**
     * Affiche un automate
     */
    void display() const;

private:
    /**
     * Entrée de l'automate
     */
    State* entree;

    /**
     * État courant
     */
    State* eCour;

    /**
     * Chaine courante
     */
    std::string chaine;
};

#endif //TP1_AUTOMATON_HPP
