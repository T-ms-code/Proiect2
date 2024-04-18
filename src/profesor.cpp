//
// Created by Mihai Telu on 4/18/2024.
//

#include "profesor.h"
Profesor::Profesor(std::string s1, std::string s2, int n) : materie_predata(std::move(s2)), ani_vechime(n), nume_profesor(std::move(s1)) {}

std::string Profesor::getnume_profesor() const {
    return nume_profesor;
}

Profesor::~Profesor() = default;

Profesor::Profesor(const Profesor& p) : Persoana(p) {
    this->materie_predata = p.materie_predata;
    this->ani_vechime = p.ani_vechime;
    this->nume_profesor = p.nume_profesor;
    this->salariu = p.salariu;
}

Profesor& Profesor::operator=(const Profesor& d) {
    if (this == &d) {
        return *this;
    } else {
        this->nume_profesor = d.nume_profesor;
        this->materie_predata = d.materie_predata;
        this->ani_vechime = d.ani_vechime;
        return *this;
    }
}

void Profesor::AdaugareVchime() {
    ani_vechime++;
}

void Profesor::Statut() {
    std::cout << nume_profesor << " preda " << materie_predata << " de " << ani_vechime << "ani si castiga " << salariu << " lei lunar.";
}

bool Profesor::operator==(Profesor& p) {
    return (this->nume_profesor == p.nume_profesor && this->materie_predata == p.materie_predata && this->ani_vechime == p.ani_vechime);
}

void Profesor::descriere() {
    std::cout << nume_profesor << " este un profesor al liceului X." << std::endl;
}

std::istream& operator>>(std::istream& in, Profesor& c) {
    std::cout << "Numele profesorului: ";
    getline(in, c.nume_profesor);
    std::cout << std::endl;
    std::cout << "Materia predata (cu prima litera mare): ";
    getline(in, c.materie_predata);
    std::cout << std::endl;
    std::cout << "Ani vechime: ";
    in >> c.ani_vechime;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Profesor& c) {
    out << "Numele profesorului: ";
    out << c.nume_profesor;
    out << std::endl;
    out << "Materia predata: ";
    out << c.materie_predata;
    out << std::endl;
    out << "Ani vechime: ";
    out << c.ani_vechime;
    return out;
}