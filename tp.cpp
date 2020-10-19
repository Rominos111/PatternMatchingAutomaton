#include "tp.hpp"

// ============================= QUESTION 1 =============================
std::vector<Occurrence*> match_patterns(std::string& text, std::vector<std::string>& words) {
    std::vector<Occurrence*> res;

    for (int i = 0; i < text.length(); i++) {
        for (auto& word : words) {
             int pt = 0;

             while (pt + i < text.length() && pt < word.length() && text[i+pt] == word[pt]) {
                 pt++;
             }

             if (pt >= word.length()) {
                 auto* oc = new Occurrence;
                 oc->pattern = word;
                 oc->index = i;
                 res.push_back(oc);
             }
        }
    }

    return res;
}

// ============================= QUESTION 2 =============================
// TODO: Retirer
std::vector<Occurrence*> quick_match(std::string& text, std::vector<std::string>& words) {
    std::vector<Occurrence*> res;
    int match[words.size()];

    for (int i = 0; i < words.size(); i++) {
        match[i] = 0;
    }

    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (text[i] != words.at(j)[match[j]]) {
                match[j] = 0;
            }

            if (text[i] == words.at(j)[match[j]]) {
                match[j]++;
            }

            if (match[j] == words.at(j).length()) {
                auto* oc = new Occurrence;
                oc->pattern = words.at(j);
                oc->index = i - (int) words.at(j).length() + 1;
                res.push_back(oc);
                match[j] = 0;
            }
        }
    }

    return res;
}


// ================================= méthode avec ds structures et autres trucs po bo =================================

bool Lien::jump_available(char c) {
    return etiquette == c;
}

std::vector<std::string> Automate::get_etats_finaux() {
    return this->eCour->final;
}

void Automate::jump(char car) {
    // std::cout << car << ' ';
    
    for (auto& lien : eCour->liens) {
        if (lien.jump_available(car)) {
            eCour = lien.next;
            chaine.push_back(car);
            // std::cout << "pas lien" << std::endl;
            return;
        }
    }

    // Si aucun lien n'est trouvé
    eCour = entree;
    chaine.clear();

    for (auto& lien : eCour->liens) {
        if (lien.jump_available(car)) {
            eCour = lien.next;
            chaine.push_back(car);
            // std::cout << "pas saut" << std::endl;
            return;
        }
    }

    // std::cout << "rien" << std::endl;
}

Automate::Automate() {

    //res
    std::vector<std::string> res;

    //resultats de 13
    res.clear();
    res.push_back("rene");
    res.push_back("irene");
    //etat 13
    Etat* etat13 = new Etat(res);

    //liens de 12
    std::vector<Lien> liensE12;
    liensE12.push_back(*(new Lien('e', etat13)));

    //etat 12
    Etat* etat12 = new Etat(liensE12);
    
    //liens de 11
    std::vector<Lien> liensE11;
    //resultats de 11
    std::vector<std::string> res2;
    res2.push_back("rein");
    //etat 11
    Etat* etat11 = new Etat(res2,liensE11);

    //resultats de 10
    std::vector<std::string> res3;
    res3.push_back("rene");
    //etat 10
    Etat* etat10 = new Etat(res3);

    //liens de 9
    std::vector<Lien> liensE9;
    liensE9.push_back(*(new Lien('n', etat12)));

    //etat 9
    Etat* etat9 = new Etat(liensE9);

    //liens de 8
    std::vector<Lien> liensE8;
    liensE8.push_back(*(new Lien('n', etat11)));

    //etat 8
    Etat* etat8 = new Etat(liensE8);

    //Actualisation autres liens
    liensE9.push_back(*(new Lien('i', etat8)));

    //liens de 7
    std::vector<Lien> liensE7;
    liensE7.push_back(*(new Lien('e', etat10)));

    //etat 7
    Etat* etat7 = new Etat(liensE7);

    //liens de 6
    std::vector<Lien> liensE6;
    liensE6.push_back(*(new Lien('e', etat9)));

    //etat 6
    Etat* etat6 = new Etat(liensE6);

    //actualisation
    liensE8.push_back(*(new Lien('r', etat6)));

    //liens de 5
    std::vector<Lien> liensE5;
    liensE5.push_back(*(new Lien('i', etat8)));
    liensE5.push_back(*(new Lien('n', etat7)));
    
    //etat 5
    Etat* etat5 = new Etat(liensE5);

    //liens de 4
    std::vector<Lien> liensE4;
    liensE4.push_back(*(new Lien('r', etat6)));
    //resultats de 4
    std::vector<std::string> res4;
    res4.push_back("ni");
    //etat 4
    Etat* etat4 = new Etat(res4, liensE4);

    //on prie pour que ça marche
    liensE11.push_back(*(new Lien('i', etat4)));
    liensE12.push_back(*(new Lien('i', etat4)));
    liensE7.push_back(*(new Lien('i', etat4)));

    //liens de 3
    std::vector<Lien> liensE3;
    liensE3.push_back(*(new Lien('r', etat6)));

    //etat
    Etat* etat3 = new Etat(liensE3);

    //liens de 2
    std::vector<Lien> liensE2;
    liensE2.push_back(*(new Lien('e', etat5)));
    
    //etat 2
    Etat* etat2 = new Etat(liensE2);
    
    //liens de 1
    std::vector<Lien> liensE1;
    liensE1.push_back(*(new Lien('i', etat4)));

    //etat 1
    Etat* etat1 = new Etat(liensE1);

    //liens de 0
    std::vector<Lien> liensE0;
    liensE0.push_back(*(new Lien('r', etat2)));
    liensE0.push_back(*(new Lien('n', etat1)));
    liensE0.push_back(*(new Lien('i', etat3)));


    //etat 0
    this->entree = new Etat(liensE0);
    this->eCour = entree;
    this->chaine = "";
}

Lien* Etat::getLien(char c) {
    for (Lien& lien : liens) {
        if (lien.etiquette == c) {
            return &lien;
        }
    }

    return nullptr;
}

Automate::Automate(std::vector<std::string>& words) {
    this->entree = new Etat();
    this->eCour = entree;
    this->chaine = "";

    Etat* base = this->entree;

    for (auto& word : words) {
        for (int i = 0; i < word.length(); i++) {
            Lien* lien = base->getLien(word[i]);

            if (lien == nullptr) {
                // Ne contient pas
            }
            else {
                // Contient
            }
        }
    }
}

void Etat::jump_possible(char car) {

}

std::vector<Occurrence*> struct_match(std::string& text, Automate& au)
{
    std::vector<Occurrence*> res;

    for (int i = 0; i < text.length(); i++) {
        au.jump(text[i]);
        auto allRes = au.get_etats_finaux();

        for (std::string& resStr : allRes) {
            auto *oc = new Occurrence;
            oc->pattern = resStr;
            oc->index = i - (int) oc->pattern.length() + 1;
            res.push_back(oc);
        }
    }

    return res;
}
