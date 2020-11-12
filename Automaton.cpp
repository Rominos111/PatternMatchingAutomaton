#include "Automaton.hpp"

Automaton::Automaton(const std::vector<std::string>& words) {
    this->entree = new State();
    this->eCour = entree;
    this->chaine = "";

    State* base;

    for (auto& word : words) {
        base = this->entree;

        for (int i = 0; i < word.length(); i++) {
            Link* lien = base->getLink(word[i]);

            if (lien == nullptr) {
                // Ne contient pas
                State* etat;

                if (i == word.length() - 1) {
                    std::vector<std::string> final;

                    for (const std::string& w2 : words) {
                        if (word.find(w2) != std::string::npos) {
                            final.emplace(final.begin(), w2);
                        }
                    }

                    etat = new State(final);
                }
                else {
                    etat = new State;
                }

                base->addLink(new Link(word[i], etat));
                base = etat;
            }
            else {
                // Contient
                base = lien->getNext();
            }
        }
    }
}

Automaton::~Automaton() {
    delete this->entree;
}

Automaton::Automaton() {
    std::vector<std::string> res;

    // Résultats de 13
    res.clear();
    res.emplace(res.begin(), "rene");
    res.emplace(res.begin(), "irene");
    // État 13
    auto* etat13 = new State(res);

    // Liens de 12
    std::vector<Link*> liensE12;
    liensE12.push_back(new Link('e', etat13));

    // État 12
    auto* etat12 = new State(liensE12);

    // Liens de 11
    std::vector<Link*> liensE11;
    // Résultats de 11
    std::vector<std::string> res2;
    res2.emplace(res2.begin(), "rein");
    // État 11
    auto* etat11 = new State(res2, liensE11);

    // Résultats de 10
    std::vector<std::string> res3;
    res3.emplace(res3.begin(), "rene");
    // État 10
    auto* etat10 = new State(res3);

    // Liens de 9
    std::vector<Link*> liensE9;
    liensE9.push_back(new Link('n', etat12));

    // État 9
    auto* etat9 = new State(liensE9);

    // Liens de 8
    std::vector<Link*> liensE8;
    liensE8.push_back(new Link('n', etat11));

    // État 8
    auto* etat8 = new State(liensE8);

    // Actualisation autres liens
    liensE9.push_back(new Link('i', etat8));

    // Liens de 7
    std::vector<Link*> liensE7;
    liensE7.push_back(new Link('e', etat10));

    // État 7
    auto* etat7 = new State(liensE7);

    // Liens de 6
    std::vector<Link*> liensE6;
    liensE6.push_back(new Link('e', etat9));

    // État 6
    auto* etat6 = new State(liensE6);

    // Actualisation
    liensE8.push_back(new Link('r', etat6));

    // Liens de 5
    std::vector<Link*> liensE5;
    liensE5.push_back(new Link('i', etat8));
    liensE5.push_back(new Link('n', etat7));

    // État 5
    State* etat5 = new State(liensE5);

    // Liens de 4
    std::vector<Link*> liensE4;
    liensE4.push_back(new Link('r', etat6));
    // Résultats de 4
    std::vector<std::string> res4;
    res4.emplace(res4.begin(), "ni");
    // État 4
    State* etat4 = new State(res4, liensE4);

    liensE11.push_back(new Link('i', etat4));
    liensE12.push_back(new Link('i', etat4));
    liensE7.push_back(new Link('i', etat4));

    // Liens de 3
    std::vector<Link*> liensE3;
    liensE3.push_back(new Link('r', etat6));

    // État
    State* etat3 = new State(liensE3);

    // Liens de 2
    std::vector<Link*> liensE2;
    liensE2.push_back(new Link('e', etat5));

    // État 2
    State* etat2 = new State(liensE2);

    // Liens de 1
    std::vector<Link*> liensE1;
    liensE1.push_back(new Link('i', etat4));

    // État 1
    State* etat1 = new State(liensE1);

    // Liens de 0
    std::vector<Link*> liensE0;
    liensE0.push_back(new Link('r', etat2));
    liensE0.push_back(new Link('n', etat1));
    liensE0.push_back(new Link('i', etat3));


    // État 0
    this->entree = new State(liensE0);
    this->eCour = entree;
    this->chaine = "";
}

void Automaton::jump(char car) {
    for (auto& lien : eCour->getLinks()) {
        if (lien->jumpAvailable(car)) {
            eCour = lien->getNext();
            chaine.push_back(car);
            return;
        }
    }

    // Si aucun lien n'est trouvé
    eCour = entree;
    chaine.clear();

    for (auto& lien : eCour->getLinks()) {
        if (lien->jumpAvailable(car)) {
            eCour = lien->getNext();
            chaine.push_back(car);
            return;
        }
    }
}

std::vector<std::string> Automaton::getRecognizedStrings() const {
    return this->eCour->getRecognizedStrings();
}

void displayRec(Link& lien) {
    std::cout << lien.getLabel();
    State* next = lien.getNext();

    if (next->getLinks().empty()) {
        std::cout << " :";

        for (auto& elem : next->getRecognizedStrings()) {
            std::cout << " " << elem;
        }
        std::cout << "\n";
    }
    else {
        for (auto& lien2 : next->getLinks()) {
            displayRec(*lien2);
        }
    }
}

void Automaton::display() const {
    for (auto& lien : entree->getLinks()) {
        displayRec(*lien);
    }
}
