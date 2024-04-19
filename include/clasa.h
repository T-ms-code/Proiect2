//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_CLASA_H
#define OOP_CLASA_H
#include "diriginte.h"
#include "elev.h"

class Clasa {
private:
    std::string nume_clasa;
    Diriginte d;
    Elev* elevi;
    int nr_elevi;
public:
    Clasa(std::string nume_clasa, const Diriginte& d, const Elev* elevi, int nr_elevi);
    Clasa();
    ~Clasa();

    [[maybe_unused]] Clasa(const Clasa& c);
    Clasa& operator=(const Clasa& c);
    friend std::ostream& operator<<(std::ostream& out, const Clasa& c);
    friend std::istream& operator>>(std::istream& in, Clasa& c);
    void operator++();
    friend int operator+(const Clasa& c1, const Clasa& c2);
    void SchimbaDiriginte(const Diriginte& p);
    void AdaugaElev(const Elev& e);
    void ExmatriculeazaElev(const std::string& nume);
    float MediaClasei();
    [[nodiscard]] int getnrelevi() const;
    std::string getnume();
    Elev* getelevi();
    Diriginte getdiriginte();
    void setvechime();
    void adauga_materie_noua(const Materie& m);
};

#endif //OOP_CLASA_H
