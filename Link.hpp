#ifndef TP1_LINK_HPP
#define TP1_LINK_HPP

#include "State.fwd.hpp"
#include "Link.fwd.hpp"

/**
 * Link
 */
class Link {
public:
    /**
     * Constructeur
     *
     * @param etiquette Étiquette, caractère
     * @param next État suivant
     */
    Link(char etiquette, State* next);

    ~Link();

    /**
     * @param c Caractère
     * @return Saut possible ou non
     */
    [[nodiscard]] bool jumpAvailable(char c) const;

    /**
     * @return next
     */
    [[nodiscard]] State* getNext() const;

    /**
     * @return label
     */
    [[nodiscard]] char getLabel() const;

private:
    /**
     * Étiquette
     */
    char label;

    /**
     * État suivant
     */
    State* next;
};

#endif //TP1_LINK_HPP
