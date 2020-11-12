#include "Link.hpp"
#include "State.hpp"

Link::Link(char etiquette, State* next) : label(etiquette), next(next) {}

Link::~Link() {
    delete this->next;
}

bool Link::jumpAvailable(char c) const {
    return label == c;
}

State* Link::getNext() const {
    return next;
}

char Link::getLabel() const {
    return label;
}
