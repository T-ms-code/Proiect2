//
// Created by Mihai Telu on 4/21/2024.
//

#ifndef OOP_DIRECTOR_H
#define OOP_DIRECTOR_H
#include "director.h"
#include "profesor.h"
#include <iostream>
class Director : public Profesor {
    int an_alegere_in_functie;

public:
    Director(const Profesor& p, int an) : Profesor(p), an_alegere_in_functie(an) {}
    void Statut() override;
};
#endif //OOP_DIRECTOR_H
