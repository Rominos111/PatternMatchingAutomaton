#ifndef TP1_OCCURRENCE_HPP
#define TP1_OCCURRENCE_HPP

#include <string>

/**
 * Occurrence d'un mot
 */
class Occurrence {
public:
    Occurrence(std::string& pattern, int index);

    std::string getPattern() const;

    int getIndex() const;

private:
    std::string pattern;
    int index;
};

#endif //TP1_OCCURRENCE_HPP
