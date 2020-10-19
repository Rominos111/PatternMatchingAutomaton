#include <iostream>
#include "tp.hpp"

int main() {

    std::string text = "annie n'honnit ni nina ni rene irene roro il as pas de reineuhhh";

    std::vector<std::string> words;
    words.emplace_back("ni");
    words.emplace_back("rein");
    words.emplace_back("rene");
    words.emplace_back("irene");

    std::vector<Occurrence*> res = match_patterns(text, words);

    for(auto& oc : res) {
        std::cout << "Occurrence : " << oc->pattern << " " << oc->index << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    res = quick_match(text, words);

    for(auto& oc : res) {
        std::cout << "Occurrence : " << oc->pattern << " " << oc->index << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    /*std::string*/// text = "annie n'honnit ni nina ni irene";
    auto* automate = new Automate();

    /*std::vector<Occurrence*>*/ res = struct_match(text, *(automate));

    for(auto& oc : res) {
        std::cout << "Occurrence : " << oc->pattern << " " << oc->index << std::endl;
    }

    return EXIT_SUCCESS;
}
