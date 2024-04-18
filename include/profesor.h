//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_PROFESOR_H
#define OOP_PROFESOR_H
#include "persoana.h"
#include <iostream>

class Profesor : public Persoana {
private:
    std::string materie_predata;
    int ani_vechime;
protected:
    std::string nume_profesor;
    int salariu = 3000;
public:
    explicit Profesor(std::string s1 = "", std::string s2 = "", int n = 0);
    [[nodiscard]] std::string getnume_profesor() const;
    ~Profesor() override;
    Profesor(const Profesor& p);
    Profesor& operator=(const Profesor& d);
    void AdaugareVchime();
    virtual void Statut();
    bool operator==(Profesor& p);
    void descriere() override;
    friend std::istream& operator>>(std::istream& in, Profesor& c);
    friend std::ostream& operator<<(std::ostream& out, const Profesor& c);
};
#endif //OOP_PROFESOR_H
