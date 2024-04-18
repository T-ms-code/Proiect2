//
// Created by Mihai Telu on 4/18/2024.
//

#include "diriginte.h"
Diriginte::Diriginte(const Profesor& p, std::string s) : Profesor(p) {
    this->nume_clasa = std::move(s);
}

Diriginte::Diriginte() = default;

Diriginte::Diriginte(const Diriginte& d) : Profesor(d) {
    this->nume_clasa = d.nume_clasa;
}

Diriginte& Diriginte::operator=(const Diriginte& d) {
    if (this == &d) {
        return *this;
    } else {
        this->Profesor::operator=(d);
        this->nume_clasa = d.nume_clasa;
        return *this;
    }
}

void Diriginte::Statut() {
    std::cout << nume_profesor << " este diriginte la clasa " << nume_clasa << " si castiga " << salariu + 1000 << " lei lunar.";
}

std::istream& operator>>(std::istream& in, Diriginte& d) {
    in >> static_cast<Profesor&>(d);
    std::cout << std::endl;
    std::cout << "Clasa (inca o data): ";
    in >> d.nume_clasa;
    return in;
}