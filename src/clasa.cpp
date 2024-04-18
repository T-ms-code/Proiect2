//
// Created by Mihai Telu on 4/18/2024.
//

#include "clasa.h"
#include <cmath>

Clasa::Clasa(std::string nume_clasa, const Diriginte& d, const Elev* elevi, int nr_elevi)
        : nume_clasa(std::move(nume_clasa)), d(d) {
    if (elevi != nullptr && nr_elevi > 0) {
        this->nr_elevi = nr_elevi;
        this->elevi = new Elev[nr_elevi];
        for (int i = 0; i < nr_elevi; i++)
            this->elevi[i] = elevi[i];
    } else {
        this->elevi = nullptr;
        this->nr_elevi = 0;
    }
}

Clasa::Clasa() : d() {
    this->nume_clasa = "";
    this->elevi = nullptr;
    this->nr_elevi = 0;
}

Clasa::~Clasa() {
    delete[] elevi;
}

//Clasa::Clasa(const Clasa& c) {
//    this->nume_clasa = c.nume_clasa;
//    this->d = c.d;
//    if (c.elevi != nullptr && c.nr_elevi > 0) {
//        this->nr_elevi = c.nr_elevi;
//        this->elevi = new Elev[this->nr_elevi];
//        for (int i = 0; i < this->nr_elevi; i++)
//            this->elevi[i] = c.elevi[i];
//    } else {
//        this->elevi = nullptr;
//        this->nr_elevi = 0;
//    }
//}

Clasa& Clasa::operator=(const Clasa& c) {
    if (this != &c) {
        this->nume_clasa = c.nume_clasa;
        this->d = c.d;
        delete[] this->elevi;
        if (c.elevi != nullptr && c.nr_elevi > 0) {
            this->nr_elevi = c.nr_elevi;
            this->elevi = new Elev[this->nr_elevi];
            for (int i = 0; i < this->nr_elevi; i++)
                this->elevi[i] = c.elevi[i];
        } else {
            this->elevi = nullptr;
            this->nr_elevi = 0;
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Clasa& c) {
    out << "Numele clasei: " << c.nume_clasa << std::endl;
    out << "Diriginte: " << c.d.getnume_profesor() << std::endl;
    out << "Elevi:" << std::endl;
    for (int i = 0; i < c.nr_elevi; i++) {
        out << "Nr" << i + 1 << ": " << c.elevi[i].getnume_elev() << "--" << "medie generala: " << c.elevi[i].getmedie_elev() << "--" << "absente: " << c.elevi[i].getnr_absente() << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Clasa& c) {
    std::cout << "Numele clasei: " << std::endl;
    std::string s1;
    std::cin.get();
    do {
        getline(in, s1);
        std::cout << std::endl;
    } while (!(s1.size() == 2 && s1[0] == '9' && 'A' <= s1[1] && s1[1] <= 'D') && !(s1.size() == 3 && s1[0] == '1' && '0' <= s1[1] && s1[1] <= '2' && 'A' <= s1[2] && s1[2] <= 'D'));
    std::cout << std::endl;
    std::cout << " ACCEPTAT!" << std::endl;
    c.nume_clasa = s1;
    std::cout << "Diriginte (care nu exista deja!): " << std::endl;
    in >> c.d;
    return in;
}

void Clasa::operator++() {
    nr_elevi++;
}

int operator+(const Clasa& c1, const Clasa& c2) {
    return c1.getnrelevi() + c2.getnrelevi();
}


void Clasa::SchimbaDiriginte(const Diriginte& p) {
    d = p;
}

void Clasa::AdaugaElev(const Elev& e) {
    int nr = nr_elevi + 1;
    Elev* v2 = new Elev[nr];
    for (int i = 0; i < nr_elevi; i++)
        v2[i] = elevi[i];
    v2[nr_elevi] = e;
    delete[] elevi;
    elevi = new Elev[nr];
    for (int i = 0; i < nr_elevi; i++)
        elevi[i] = v2[i];
    elevi[nr_elevi] = e;
    delete[] v2;
}

void Clasa::ExmatriculeazaElev(const std::string& nume) {
    if (nr_elevi >= 1) {
        int nr = nr_elevi - 1;
        Elev* v2 = new Elev[nr];
        int ok = 0;
        int j = 0;
        for (int i = 0; i < nr_elevi; i++) {
            if (elevi[i].getnume_elev() == nume && ok == 1) {
                v2[j] = elevi[i];
                j++;
            }
            if (elevi[i].getnume_elev() == nume && ok == 0) {
                ok = 1;
            }
            if (elevi[i].getnume_elev() != nume) {
                v2[j] = elevi[i];
                j++;
            }
        }
        delete[] elevi;
        elevi = new Elev[nr];
        for (int i = 0; i < nr; i++)
            elevi[i] = v2[i];
        nr_elevi = nr;
        delete[] v2;
    }
}

float Clasa::MediaClasei() {
    float m = 0;
    for (int i = 0; i < nr_elevi; i++)
        m += elevi[i].getmedie_elev();
    if (nr_elevi != 0) {
        m = m / (float)nr_elevi;
    }
    return std::round(m * 100) / 100;
}

int Clasa::getnrelevi() const {
    return nr_elevi;
}

std::string Clasa::getnume() {
    return nume_clasa;
}

Elev* Clasa::getelevi() {
    return elevi;
}

Diriginte Clasa::getdiriginte() {
    return d;
}

void Clasa::setvechime() {
    d.AdaugareVchime();
}

void Clasa::adauga_materie_noua(const Materie& m) {
    for (int i = 0; i < nr_elevi; i++)
        elevi[i].aduga_materie(m);
}