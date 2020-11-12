#ifndef TP1_OCCURRENCE_HPP
#define TP1_OCCURRENCE_HPP

#include <string>

/**
 * Occurrence d'un mot
 */
class Occurrence {
public:
    /**
     * Constructeur
     *
     * @param pattern Pattern
     * @param index Index de découverte
     */
    Occurrence(const std::string& pattern, int index);

    ~Occurrence() = default;

    /**
     * @return pattern
     */
    [[nodiscard]] std::string getPattern() const;

    /**
     * @return index
     */
    [[nodiscard]] int getIndex() const;

private:
    /***
     * Pattern
     */
    std::string pattern;

    /**
     * Index de découverte
     */
    int index;
};

#endif //TP1_OCCURRENCE_HPP
