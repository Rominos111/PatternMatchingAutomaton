#include "State.hpp"
#include "Link.hpp"

State::State(std::vector<Link*>& liens) : recognizedStrings(), links(liens) {}

State::State(std::vector<std::string>& final, std::vector<Link*>& liens) : recognizedStrings(final), links(liens) {}

State::State(std::vector<std::string>& final) : recognizedStrings(final), links() {}

State::State() : recognizedStrings(), links() {}

State::~State() {
    for (auto& item : this->links) {
        delete item;
    }
}

Link* State::getLink(char c) const {
    for (Link* lien : links) {
        if (lien->jumpAvailable(c)) {
            return lien;
        }
    }

    return nullptr;
}

std::vector<Link*> State::getLinks() const {
    return links;
}

void State::addLink(Link* lien) {
    if (getLink(lien->getLabel()) != nullptr) {
        std::cout << "ERREUR: " << lien->getLabel() << std::endl;
    }

    links.emplace_back(lien);
}

std::vector<std::string> State::getRecognizedStrings() const {
    return recognizedStrings;
}
