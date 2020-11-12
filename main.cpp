#include "main.hpp"

std::vector<Occurrence*> basicMatch(const std::string& text, const std::vector<std::string>& words) {
    std::vector<Occurrence*> res;

    for (int i = 0; i < text.length(); i++) {
        for (auto& word : words) {
            int pt = 0;

            while (pt + i < text.length() && pt < word.length() && text[i+pt] == word[pt]) {
                pt++;
            }

            if (pt >= word.length()) {
                res.push_back(new Occurrence(word, i));
            }
        }
    }

    return res;
}

// TODO: Retirer
std::vector<Occurrence*> quickMatch(const std::string& text, const std::vector<std::string>& words) {
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
                res.push_back(new Occurrence(words.at(j), i - (int) words.at(j).length() + 1));
                match[j] = 0;
            }
        }
    }

    return res;
}

std::vector<Occurrence*> automatonMatch(const std::string& text, Automaton& au) {
    std::vector<Occurrence*> res;

    for (int i = 0; i < text.length(); i++) {
        au.jump(text[i]);
        auto allRes = au.getRecognizedStrings();

        for (std::string& resStr : allRes) {
            res.push_back(new Occurrence(resStr, i - (int) resStr.length() + 1));
        }
    }

    return res;
}

bool testMatchs(const std::string& text, const std::vector<std::string>& words) {
    auto* automateNew = new Automaton(words);

    std::vector<Occurrence*> res_base = basicMatch(text, words);
    std::vector<Occurrence*> res_automate_dyn = automatonMatch(text, *(automateNew));

    bool ok = true;

    if (res_base.size() == res_automate_dyn.size()) {
        for (int i = 0; i < res_base.size(); i++) {
            if (res_base.at(i)->getPattern() == res_automate_dyn.at(i)->getPattern()) {
                std::cout << "Occurrence : " << res_base.at(i)->getPattern() << " " << res_base.at(i)->getIndex() << std::endl;
            }
            else {
                std::cout << "err : '" << res_base.at(i)->getPattern() << "' vs '" << res_automate_dyn.at(i)->getPattern() << "'" << std::endl;
                ok = false;
                break;
            }
        }
    }
    else {
        std::cout << "err : size, '" << res_base.size() << "' vs '" << res_automate_dyn.size() << "'" << std::endl;
        ok = false;
    }

    for (auto& item : res_base) {
        delete item;
    }

    for (auto& item : res_automate_dyn) {
        delete item;
    }

    delete automateNew;
    return ok;
}

int main() {
    std::string text = "annie n'honnit ni nina ni irene";
    // std::string text = "annie";

    std::vector<std::string> words;
    words.emplace_back("ni");
    words.emplace_back("rein");
    words.emplace_back("rene");
    words.emplace_back("irene");
    // words.emplace_back("nn");
    // TODO: gérer cet edge-case...

#if DEBUG
    std::vector<Occurrence*> res_base = basicMatch(text, words);
    for (auto& item : res_base) {
        std::cout << item->getPattern() << " " << item->getIndex() << std::endl;
        delete item;
    }

    std::cout << std::endl;

    auto* automateNew = new Automaton(words);
    std::vector<Occurrence*> res_automate_dyn = automatonMatch(text, *(automateNew));
    for (auto& item : res_automate_dyn) {
        std::cout << item->getPattern() << " " << item->getIndex() << std::endl;
        delete item;
    }

    delete automateNew;
#else
    bool ok = testMatchs(text, words);

    if (ok) {
        std::cout << "ok :)" << std::endl;
    }
    else {
        std::cout << "aie..." << std::endl;
    }
#endif

    return EXIT_SUCCESS;
}
