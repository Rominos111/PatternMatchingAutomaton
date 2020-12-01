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

#include <chrono>
using namespace std::chrono;

int main() {
    std::string text = "annie n'honnit ni nina ni irene";

    std::vector<std::string> words;
    words.emplace_back("ni");
    words.emplace_back("rein");
    words.emplace_back("rene");
    words.emplace_back("irene");

    std::cout << text.size();

#if DEBUG
    bool ok = testMatchs(text, words);

    if (ok) {
        std::cout << "ok :)" << std::endl;
    }
    else {
        std::cout << "aie..." << std::endl;
    }
#else
    auto start_basic = high_resolution_clock::now();
    std::vector<Occurrence*> res_base = basicMatch(text, words);
    auto stop_basic = high_resolution_clock::now();

    for (auto& item : res_base) {
        std::cout << item->getPattern() << " " << item->getIndex() << std::endl;
        delete item;
    }

    std::cout << std::endl;

    auto start_construct = high_resolution_clock::now();
    auto* automateNew = new Automaton(words);
    auto stop_construct = high_resolution_clock::now();

    auto start_match = high_resolution_clock::now();
    auto res = automatonMatch(text, *(automateNew));
    auto stop_match = high_resolution_clock::now();

    for (auto& item : res) {
        std::cout << item->getPattern();
        std::cout << " " << item->getIndex() << std::endl;
        delete item;
    }

    delete automateNew;

    std::cout << std::endl;
    std::cout << "Algorithme basique : " << duration_cast<microseconds>(stop_basic - start_basic).count() << " µs" << std::endl;
    std::cout << "Construction de l'automate : " << duration_cast<microseconds>(stop_construct - start_construct).count() << " µs" << std::endl;
    std::cout << "Algorithme automate : " << duration_cast<microseconds>(stop_match - start_match).count() << " µs" << std::endl;
#endif

    return EXIT_SUCCESS;
}

// words.emplace_back("nn");
// TODO: gérer cet edge-case...
