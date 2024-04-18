//
// Created by Mihai Telu on 4/18/2024.
//

#include "bursier.h"

Bursier::Bursier([[maybe_unused]] std::string nume, int absente, [[maybe_unused]] std::vector<Materie> materii, std::string bursa, int suma)
        : Elev(std::move(nume), absente, std::move(materii)), nume_bursa(std::move(bursa)), suma_incasata(suma) {}

Bursier::Bursier() : Elev() {
    nume_bursa = "";
    suma_incasata = 0;
}

Bursier::Bursier(const Elev& e, std::string bursa, int suma) : Elev(e), nume_bursa(std::move(bursa)), suma_incasata(suma) {}

Bursier::~Bursier() = default;

Bursier::Bursier(const Bursier& b) : Elev(b) {
    this->nume_bursa = b.nume_bursa;
    this->suma_incasata = b.suma_incasata;
}

Bursier& Bursier::operator=(const Bursier& b) {
    if (this == &b) {
        return *this;
    }
    this->Elev::operator=(b);
    this->nume_bursa = b.nume_bursa;
    this->suma_incasata = b.suma_incasata;
    return *this;
}

void Bursier::afis() {
    std::cout << nume_elev << " este elev bursier." << std::endl;
}

void Bursier::scrie() {
    std::cout << nume_elev << " ia " << nume_bursa << " si suma incasata este " << suma_incasata << " lei." << std::endl << std::endl;
}

std::string Bursier::scrie(int x) {
    std::cout<<x;
    return "BURSELE SUNT OBTINUTE PE BAZA REZULTATELOR DEOSEBITE ORI A UNEI CONDITII SPECIALE!";
}

std::string Bursier::get_bursa() {
    return nume_bursa;
}