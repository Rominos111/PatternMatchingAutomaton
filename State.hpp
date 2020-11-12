#ifndef TP1_STATE_HPP
#define TP1_STATE_HPP

#include <string>
#include <vector>
#include <iostream>

#include "State.fwd.hpp"
#include "Link.fwd.hpp"

/**
 * État
 */
class State {
public:
    /**
     * Constructeur
     *
     * @param liens Liens
     */
    explicit State(std::vector<Link*>& liens);

    /**
     * Constructeur
     *
     * @param final String finale
     * @param liens Liens
     */
    State(std::vector<std::string>& final, std::vector<Link*>& liens);

    /**
     * Constructeur
     *
     * @param final String finale
     */
    explicit State(std::vector<std::string>& final);

    /**
     * Constructeur
     */
    State();

    ~State();

    /**
     * Récupère le lien connectant un caractère
     *
     * @param c Caractère
     *
     * @return Link connecté à `c`
     */
    [[nodiscard]] Link* getLink(char c) const;

    /**
     * @return Liens
     */
    [[nodiscard]] std::vector<Link*> getLinks() const;

    /**
     * Ajoute un lien
     *
     * @param lien Link
     */
    void addLink(Link* lien);

    /**
     * @return Strings reconnues
     */
    [[nodiscard]] std::vector<std::string> getRecognizedStrings() const;

private:
    /**
     * String reconnues
     */
    std::vector<std::string> recognizedStrings;

    /**
     * Liens
     */
    std::vector<Link*> links;
};

#endif //TP1_STATE_HPP
