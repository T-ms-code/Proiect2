//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_DIRIGINTE_H
#define OOP_DIRIGINTE_H
#include "profesor.h"

class Diriginte : public Profesor {
private:
    std::string nume_clasa;
public:
    Diriginte(const Profesor& p, std::string s);
    Diriginte();
    Diriginte(const Diriginte& d);
    Diriginte& operator=(const Diriginte& d);
    void Statut() override;
    friend std::istream& operator>>(std::istream& in, Diriginte& d);
};
#endif //OOP_DIRIGINTE_H
