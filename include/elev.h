//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_ELEV_H
#define OOP_ELEV_H
#include "persoana.h"
#include "materie.h"
#include <vector>
#include <iostream>

class Elev: public Persoana{
private:
    std::vector<Materie> materii;
    int nr_absente;
protected:
    std::string nume_elev;
public:
    Elev();
    explicit Elev(std::string nume);
    Elev(std::string nume, int absente, std::vector<Materie> materii);
    Elev(const Elev& e);
    Elev& operator=(const Elev& e);
    ~Elev() override;
    float getmedie_elev();
    std::string getnume_elev();
    [[nodiscard]] int getnr_absente() const;
    friend std::ostream& operator<<(std::ostream &out, Elev& e);
    void PuneNota(const std::string& materie, int nota);
    void PuneAbsenta();
    void aduga_materie(const Materie& m);
    virtual void afis();
    static void scrie();
    void descriere() override;
    std::vector<Materie> get_materii();
};
#endif //OOP_ELEV_H
