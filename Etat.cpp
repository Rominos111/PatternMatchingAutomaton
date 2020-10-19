#include "Etat.hpp"
#include "Lien.hpp"

void Etat::jump_possible(char car) {

}

Lien* Etat::getLien(char c) {
    for (Lien& lien : liens) {
        if (lien.etiquette == c) {
            return &lien;
        }
    }

    return nullptr;
}
