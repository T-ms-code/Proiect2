//
// Created by Mihai Telu on 4/18/2024.
//

#ifndef OOP_MATERIE_H
#define OOP_MATERIE_H
#include <vector>
#include <string>

class Materie{
    std::string nume_materie;
    int nr_note;
    std::vector<int> v;
    static int numar_min_note;
public:
    explicit Materie(std::string s="");
//    explicit Materie(std::string s);
    Materie(std::string s, std::vector<int> a, int n);
    ~Materie();
    Materie(const Materie& m);
    Materie& operator=(const Materie& m);
    float medie();
    int& get_nr_note();
    std::string get_denumire();
    std::vector<int>& get_note();
    static int get_nrminnote();
    static void set_nrminnote(int x);
};

#endif //OOP_MATERIE_H
