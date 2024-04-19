//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_BURSIER_H
#define OOP_BURSIER_H
#include <string>
#include "elev.h"

class Bursier : public Elev {
private:
    std::string nume_bursa;
    int suma_incasata = 0;
public:
    Bursier([[maybe_unused]] std::string nume, int absente, [[maybe_unused]] std::vector<Materie> materii, std::string bursa, int suma);
    explicit Bursier(std::string s="",int suma=0);
    Bursier(const Elev& e, std::string bursa, int suma);
    ~Bursier() override;
    Bursier(const Bursier& b);
    Bursier& operator=(const Bursier& b);
    void afis() override;
    void scrie();
    static std::string scrie(int x);
    std::string get_bursa();
};

#endif //OOP_BURSIER_H
