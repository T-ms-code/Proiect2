//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H

#include <string>

class Persoana{
    std::string CNP;
public:
    virtual ~Persoana()=0;
    virtual void descriere()=0;
};

#endif //OOP_PERSOANA_H
