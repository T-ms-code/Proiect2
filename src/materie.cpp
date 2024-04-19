//
// Created by Mihai Telu on 4/18/2024.
//

#include "materie.h"
#include <cmath>
#include <utility>
Materie::Materie(std::string s):nume_materie(std::move(s)){
    nr_note=0;
    v.resize(0);
}

//Materie::Materie(std::string s):nume_materie(std::move(s)){
//    nr_note=0;
//    v.resize(0);
//}

Materie::Materie(std::string s, std::vector<int> a, int n): nume_materie(std::move(s)), nr_note(n){
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = a[i];
    }
}

Materie::~Materie() = default;

Materie& Materie::operator=(const Materie& m){
    if(this==&m) return *this;
    this->nume_materie=m.nume_materie;
    this->nr_note=m.nr_note;
    this->v.resize(m.nr_note);
    for(int i=0;i<m.nr_note;i++)
        this->v[i]=m.v[i];
    return *this;
}

Materie::Materie(const Materie& m){
    this->nume_materie=m.nume_materie;
    this->nr_note=m.nr_note;
    this->v.resize(m.nr_note);
    for(int i=0;i<m.nr_note;i++)
        this->v[i]=m.v[i];
}

float Materie::medie(){
    float m=0;
    if(nr_note!=0){
        for(int i=0;i<nr_note;i++)m+=(float)v[i];
        return std::round(m/(float)nr_note);
    }
    else return m;
}

int& Materie::get_nr_note() {return nr_note;}

std::string Materie::get_denumire(){return nume_materie;}

std::vector<int>& Materie::get_note(){ return v;}

int Materie::get_nrminnote(){return numar_min_note;}

void Materie::set_nrminnote(int x){numar_min_note=x;}

int Materie::numar_min_note=3;