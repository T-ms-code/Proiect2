//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_EXCEPTIE_H
#define OOP_EXCEPTIE_H

#include <exception>

class Exceptie : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override{
        return "Indexul este in afara limitelor vectorului!";
    }
};

#endif //OOP_EXCEPTIE_H
