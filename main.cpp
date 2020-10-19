#include <iostream>

#include "main.hpp"

std::vector<Occurrence*> match_patterns(std::string& text, std::vector<std::string>& words) {
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
                res.push_back(new Occurrence(words.at(j), i - (int) words.at(j).length() + 1));
                match[j] = 0;
            }
        }
    }

    return res;
}

std::vector<Occurrence*> struct_match(std::string& text, Automate& au) {
    std::vector<Occurrence*> res;

    for (int i = 0; i < text.length(); i++) {
        au.jump(text[i]);
        auto allRes = au.get_etats_finaux();

        for (std::string& resStr : allRes) {
            res.push_back(new Occurrence(resStr, i - (int) resStr.length() + 1));
        }
    }

    return res;
}

int main() {
    std::string text = "annie n'honnit ni nina ni rene irene roro il as pas de reineuhhh";

    std::vector<std::string> words;
    words.emplace_back("ni");
    words.emplace_back("rein");
    words.emplace_back("rene");
    words.emplace_back("irene");

    std::vector<Occurrence*> res = match_patterns(text, words);

    for (auto& oc : res) {
        std::cout << "Occurrence : " << oc->getPattern() << " " << oc->getIndex() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    res = quick_match(text, words);

    for (auto& oc : res) {
        std::cout << "Occurrence : " << oc->getPattern() << " " << oc->getIndex() << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    /*std::string*/// text = "annie n'honnit ni nina ni irene";
    auto* automate = new Automate();

    /*std::vector<Occurrence*>*/ res = struct_match(text, *(automate));

    for (auto& oc : res) {
        std::cout << "Occurrence : " << oc->getPattern() << " " << oc->getIndex() << std::endl;
    }

    return EXIT_SUCCESS;
}
