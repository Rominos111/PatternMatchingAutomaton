#include "Occurrence.hpp"

Occurrence::Occurrence(std::string& pattern, int index) {
    this->pattern = pattern;
    this->index = index;
}

int Occurrence::getIndex() const {
    return index;
}

std::string Occurrence::getPattern() const {
    return pattern;
}
