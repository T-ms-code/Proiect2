//
// Created by Mihai Telu on 4/18/2024.
//

#include "elev.h"
#include <cmath>

Elev::Elev() {
    this->nume_elev = "";
    this->nr_absente = 0;
    materii.resize(0);
}

Elev::Elev(std::string nume) {
    this->nume_elev = std::move(nume);
    this->nr_absente = 0;
    materii.resize(0);
}

Elev::Elev(std::string nume, int absente, std::vector<Materie> materii) {
    this->nume_elev = std::move(nume);
    this->nr_absente = absente;
    this->materii.resize(materii.size());
    for (int i = 0; i <(int)materii.size(); i++)
        this->materii[i] = materii[i];
}

Elev::Elev(const Elev& e) : Persoana(e) {
    this->nume_elev = e.nume_elev;
    this->nr_absente = e.nr_absente;
    this->materii.resize(e.materii.size());
    for (int i = 0; i <(int)e.materii.size(); i++)
        this->materii[i] = e.materii[i];
}

Elev& Elev::operator=(const Elev& e) {
    if (this == &e)
        return *this;
    this->nume_elev = e.nume_elev;
    this->nr_absente = e.nr_absente;
    this->materii.resize(e.materii.size());
    for (int i = 0; i <(int)e.materii.size(); i++)
        this->materii[i] = e.materii[i];
    return *this;
}

Elev::~Elev() = default;

float Elev::getmedie_elev() {
    float m = 0;
    if (!materii.empty()) {
        for (auto & i : materii)
            m += i.medie();
        return std::round((m / (float) materii.size()) * 100) / 100;
    }
    return m;
}

std::string Elev::getnume_elev() {
    return nume_elev;
}

int Elev::getnr_absente() const {
    return nr_absente;
}

std::ostream& operator<<(std::ostream &out, Elev& e) {
    out << "Numele elevului: ";
    out << e.nume_elev;
    out << std::endl;
    for (auto & i : e.materii) {
        out << "Note la " + i.get_denumire() + ": ";
        for (int j = 0; j < i.get_nr_note(); j++) out << i.get_note()[j] << " ";
        out << std::endl;
    }
    out << "Media generala: ";
    out << e.getmedie_elev() << std::endl;
    out << "Absente: " << e.nr_absente;
    return out;
}

void Elev::PuneNota(const std::string& materie, int nota) {
    if (nota >= 1 && nota <= 10) {
        for (auto & i : materii)
            if (i.get_denumire() == materie) {
                i.get_note().push_back(nota);
                i.get_nr_note()++;
            }
    }
}

void Elev::PuneAbsenta() {
    nr_absente++;
}

void Elev::aduga_materie(const Materie& m) {
    materii.push_back(m);
}

void Elev::afis() {
    std::cout << nume_elev << " este elev in liceu." << std::endl;
}

void Elev::scrie() {
    std::cout << "El/Ea poate sa ia diverse burse: de merit, sociala, de performanta etc." << std::endl << std::endl;
}

void Elev::descriere() {
    std::cout << nume_elev << " este/a fost un elev al liceului X." << std::endl;
}

std::vector<Materie> Elev::get_materii() {
    return materii;
}