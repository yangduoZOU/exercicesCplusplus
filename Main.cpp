#include "PlageHoraire.h"
#include <iostream>
#include <vector>

int main() {
    PlageHoraire plage1(8, 12);
    PlageHoraire plage2(10, 14);

    if (plage1.estIncluseDans(plage2)) {
        std::cout << "La plage horaire 1 est incluse dans la plage horaire 2" << std::endl;
    }
    else {
        std::cout << "La plage horaire 1 n'est pas incluse dans la plage horaire 2" << std::endl;
    }

    if (plage1.estEnIntersectionAvec(plage2)) {
        std::cout << "Les plages horaires 1 et 2 ont une intersection" << std::endl;
    }
    else {
        std::cout << "Les plages horaires 1 et 2 n'ont pas d'intersection" << std::endl;
    }

    std::set<PlageHoraire> resultatSoustraction = plage1.soustraction(plage2);
    std::cout << "Résultat de la soustraction : ";
    for (const auto& plage : resultatSoustraction) {
        std::cout << plage << " ";
    }
    std::cout << std::endl;

    std::vector<PlageHoraire> plages = {{9, 11}, {12, 15}, {10, 13}};
    std::cout << "Plages horaires avant tri : ";
    for (const auto& plage : plages) {
        std::cout << plage << " ";
    }
    std::cout << std::endl;

    std::sort(plages.begin(), plages.end());

    std::cout << "Plages horaires après tri : ";
    for (const auto& plage : plages) {
        std::cout << plage << " ";
    }
    std::cout << std::endl;

    return 0;
}
