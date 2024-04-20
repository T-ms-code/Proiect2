#include <gtest/gtest.h>
#include "example.h"
#include "exceptie.h"
#include "persoana.h"
#include "materie.h"
#include "elev.h"
#include "bursier.h"
#include "profesor.h"
#include "diriginte.h"
#include "clasa.h"
#include "director.h"



TEST(SuiteName, TestName) {
    EXPECT_EQ(doSomething(10), 10);
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}



//MATERIE:
TEST(MaterieConstructor, ConstructorWithOnlyName) {
    Materie m("Math");
    EXPECT_EQ(m.get_denumire(), "Math");
    EXPECT_EQ(m.get_nr_note(), 0);
}

TEST(MaterieConstructor, ConstructorWithNameGradesAndNumber) {
    std::vector<int> grades = {8, 9, 7};
    Materie m("Physics", grades, 3);
    EXPECT_EQ(m.get_denumire(), "Physics");
    EXPECT_EQ(m.get_nr_note(), 3);
    EXPECT_EQ(m.get_note(), grades);
}

TEST(MaterieAssignment, AssignmentOperator) {
    Materie m1("Chemistry", {10, 9, 8}, 3);
    Materie m2("Biology", {7, 8}, 2);
    m2 = m1;
    EXPECT_EQ(m2.get_denumire(), "Chemistry");
    EXPECT_EQ(m2.get_nr_note(), 3);
    EXPECT_EQ(m2.get_note(), std::vector<int>({10, 9, 8}));
}

TEST(MaterieCopyConstructor, CopyConstructor) {
    Materie m1("History", {9, 8}, 2);
    Materie m2 = m1;
    EXPECT_EQ(m2.get_denumire(), "History");
    EXPECT_EQ(m2.get_nr_note(), 2);
    EXPECT_EQ(m2.get_note(), std::vector<int>({9, 8}));
}

TEST(MaterieMedie, MedieFunction) {
    Materie m("English", {8, 7, 6, 9}, 4);
    EXPECT_EQ(m.medie(), 8); // The average of {8, 7, 6, 9} is 7.5, rounded to 8
}

TEST(MaterieNrMinNote, SetAndGetNrMinNote) {
    Materie m("Geography");
    Materie::set_nrminnote(2);
    EXPECT_EQ(m.get_nrminnote(), 2);
}



//ELEV:
TEST(ElevTest, DefaultConstructor) {
    Elev e;
    EXPECT_EQ(e.getnume_elev(), "");
    EXPECT_EQ(e.getnr_absente(), 0);
    EXPECT_TRUE(e.get_materii().empty());
}

TEST(ElevTest, ConstructorWithName) {
    Elev e("John");
    EXPECT_EQ(e.getnume_elev(), "John");
    EXPECT_EQ(e.getnr_absente(), 0);
    EXPECT_TRUE(e.get_materii().empty());
}

TEST(ElevTest, ConstructorWithNameAbsencesAndSubjects) {
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    std::vector<Materie> materii = {m1, m2};
    Elev e("Alice", 2, materii);
    EXPECT_EQ(e.getnume_elev(), "Alice");
    EXPECT_EQ(e.getnr_absente(), 2);
    EXPECT_EQ(e.get_materii().size(), 2);
    EXPECT_EQ(e.get_materii()[0].get_denumire(), "Math");
    EXPECT_EQ(e.get_materii()[1].get_denumire(), "Physics");
}

TEST(ElevTest, CopyConstructor) {
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    std::vector<Materie> materii = {m1, m2};
    Elev e1("Bob", 1, materii);
    Elev e2 = e1;
    EXPECT_EQ(e2.getnume_elev(), "Bob");
    EXPECT_EQ(e2.getnr_absente(), 1);
    EXPECT_EQ(e2.get_materii().size(), 2);
    EXPECT_EQ(e2.get_materii()[0].get_denumire(), "Math");
    EXPECT_EQ(e2.get_materii()[1].get_denumire(), "Physics");
}

TEST(ElevTest, GetMedieElevFunction) {
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    std::vector<Materie> materii = {m1, m2};
    Elev e("Alice", 2, materii);
    // Expected average = (8+7+9+9+8)/5 = 8.2
    EXPECT_FLOAT_EQ(e.getmedie_elev(), 8.5);
}

TEST(ElevTest, OperatorOverload) {
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    std::vector<Materie> materii = {m1, m2};
    Elev e("Alice", 2, materii);
    std::stringstream ss;
    ss << e;
    std::string expectedOutput = "Numele elevului: Alice\n";
    expectedOutput += "Note la Math: 8 7 9 \n";
    expectedOutput += "Note la Physics: 9 8 \n";
    expectedOutput += "Media generala: 8.5\n";
    expectedOutput += "Absente: 2";
    EXPECT_EQ(ss.str(), expectedOutput);
}

TEST(ElevTest, PuneNotaFunction) {
    Materie m1("Math", {8, 7, 9}, 3);
    std::vector<Materie> materii = {m1};
    Elev e("Alice", 2, materii);
    e.PuneNota("Math", 10);
    EXPECT_EQ(e.get_materii()[0].get_nr_note(), 4);
    EXPECT_EQ(e.get_materii()[0].get_note()[3], 10);
}

TEST(ElevTest, PuneAbsentaFunction) {
    Elev e("John");
    e.PuneAbsenta();
    EXPECT_EQ(e.getnr_absente(), 1);
}

TEST(ElevTest, AdaugaMaterieFunction) {
    Materie m1("Math", {8, 7, 9}, 3);
    Elev e("John");
    e.aduga_materie(m1);
    EXPECT_EQ(e.get_materii().size(), 1);
    EXPECT_EQ(e.get_materii()[0].get_denumire(), "Math");
}

TEST(ElevTest, AfisFunction) {
    Elev e("John");
    // Not testing output since it goes to standard output
    e.afis();
}

TEST(ElevTest, ScrieFunction) {
    Elev e("John");
    // Not testing output since it goes to standard output
    Elev::scrie();
}

TEST(ElevTest, DescriereFunction) {
    Elev e("John");
    // Not testing output since it goes to standard output
    e.descriere();
}



//BURSIER:
TEST(BursierTest, ConstructorWithNameAbsencesScholarshipAndAmount) {
    Materie m1("Math", {8, 7, 9}, 3);
    std::vector<Materie> materii = {m1};
    Bursier b("John", 2, materii, "Merit", 1000);
    EXPECT_EQ(b.getnume_elev(), "John");
    EXPECT_EQ(b.getnr_absente(), 2);
    EXPECT_EQ(b.get_materii().size(), 1);
    EXPECT_EQ(b.get_materii()[0].get_denumire(), "Math");
    EXPECT_EQ(b.get_bursa(), "Merit");
}

TEST(BursierTest, ConstructorWithScholarshipAndAmount) {
    Bursier b("Merit", 1000);
    EXPECT_EQ(b.getnume_elev(), "");
    EXPECT_EQ(b.getnr_absente(), 0);
    EXPECT_TRUE(b.get_materii().empty());
    EXPECT_EQ(b.get_bursa(), "Merit");
}

TEST(BursierTest, CopyConstructor) {
    Materie m1("Math", {8, 7, 9}, 3);
    std::vector<Materie> materii = {m1};
    Bursier b1("Alice", 1, materii, "Merit", 1000);
    Bursier b2 = b1;
    EXPECT_EQ(b2.getnume_elev(), "Alice");
    EXPECT_EQ(b2.getnr_absente(), 1);
    EXPECT_EQ(b2.get_materii().size(), 1);
    EXPECT_EQ(b2.get_materii()[0].get_denumire(), "Math");
    EXPECT_EQ(b2.get_bursa(), "Merit");
}

TEST(BursierTest, AssignmentOperator) {
    Materie m1("Math", {8, 7, 9}, 3);
    std::vector<Materie> materii = {m1};
    Bursier b1("Bob", 2, materii, "Merit", 1000);
    Bursier b2("Social", 500);
    b2 = b1;
    EXPECT_EQ(b2.getnume_elev(), "Bob");
    EXPECT_EQ(b2.getnr_absente(), 2);
    EXPECT_EQ(b2.get_materii().size(), 1);
    EXPECT_EQ(b2.get_materii()[0].get_denumire(), "Math");
    EXPECT_EQ(b2.get_bursa(), "Merit");
}

TEST(BursierTest, AfisFunction) {
    Materie m1("Math", {8, 7, 9}, 3);
    std::vector<Materie> materii = {m1};
    Bursier b("John", 2, materii, "Merit", 1000);
    // Not testing output since it goes to standard output
    b.afis();
}

TEST(BursierTest, ScrieFunction) {
    Materie m1("Math", {8, 7, 9}, 3);
    std::vector<Materie> materii = {m1};
    Bursier b("John", 2, materii, "Merit", 1000);
    // Not testing output since it goes to standard output
    b.scrie();
}

TEST(BursierTest, ScrieIntFunction) {
    Bursier b("Merit", 1000);
    EXPECT_EQ(b.scrie(10), "BURSELE SUNT OBTINUTE PE BAZA REZULTATELOR DEOSEBITE ORI A UNEI CONDITII SPECIALE!");
}



//PROFESOR::
TEST(ProfesorTest, ConstructorWithParameters) {
    Profesor p("John Doe", "Mathematics", 10);
    EXPECT_EQ(p.getnume_profesor(), "John Doe");
}

TEST(ProfesorTest, CopyConstructor) {
    Profesor p1("John Doe", "Mathematics", 10);
    const Profesor& p2 = p1;
    EXPECT_EQ(p2.getnume_profesor(), "John Doe");
}

TEST(ProfesorTest, AssignmentOperator) {
    Profesor p1("John Doe", "Mathematics", 10);
    Profesor p2("Alice Smith", "Physics", 5);
    p2 = p1;
    EXPECT_EQ(p2.getnume_profesor(), "John Doe");
}

TEST(ProfesorTest, AdaugareVchimeFunction) {
    Profesor p("John Doe", "Mathematics", 10);
    p.AdaugareVchime();
}

TEST(ProfesorTest, StatutFunction) {
    Profesor p("John Doe", "Mathematics", 10);
    // Not testing output since it goes to standard output
    p.Statut();
}

TEST(ProfesorTest, OperatorEqualsEqualsOverload) {
    Profesor p1("John Doe", "Mathematics", 10);
    Profesor p2("John Doe", "Mathematics", 10);
    EXPECT_TRUE(p1 == p2);
}

TEST(ProfesorTest, DescriereFunction) {
    Profesor p("John Doe", "Mathematics", 10);
    // Not testing output since it goes to standard output
    p.descriere();
}

TEST(ProfesorTest, InputOperatorOverload) {
    Profesor profesor;
    std::stringstream input("John Doe\nMathematics\n10");
    input >> profesor;

    EXPECT_EQ(profesor.getnume_profesor(), "John Doe");
}

TEST(ProfesorTest, OutputOperatorOverload) {
    Profesor profesor("Jane Smith", "Physics", 5);
    std::stringstream output;
    output << profesor;

    std::string expected_output = "Numele profesorului: Jane Smith\nMateria predata: Physics\nAni vechime: 5";
    EXPECT_EQ(output.str(), expected_output);
}



//DIRIGINTE:
TEST(DiriginteTest, ConstructorWithParametersInitializesCorrectly) {
    Profesor profesor("John Doe", "Mathematics",10);
    Diriginte diriginte(profesor, "10A");

    EXPECT_EQ(diriginte.getnume_profesor(), "John Doe");
}

TEST(DiriginteTest, DefaultConstructorInitializesCorrectly) {
    Diriginte diriginte;

    EXPECT_EQ(diriginte.getnume_profesor(), "");
}

TEST(DiriginteTest, CopyConstructorCopiesCorrectly) {
    Profesor profesor("Jane Smith","Chemistry",25);
    Diriginte diriginte(profesor, "11B");
    const Diriginte& copy_diriginte(diriginte);

    EXPECT_EQ(copy_diriginte.getnume_profesor(), "Jane Smith");
}

TEST(DiriginteTest, AssignmentOperatorAssignsCorrectly) {
    Profesor profesor1("Alice Johnson","Math" ,18);
    Diriginte diriginte1(profesor1, "9C");

    Profesor profesor2("Bob Brown","Math",22);
    Diriginte diriginte2(profesor2, "12D");

    diriginte2 = diriginte1;

    EXPECT_EQ(diriginte2.getnume_profesor(), "Alice Johnson");
}

TEST(DiriginteTest, StatutMethodReturnsCorrectString) {
    Profesor profesor("Mike Wilson","Music",30);
    Diriginte diriginte(profesor, "8E");

    // Not testing output since it goes to standard output
    diriginte.Statut();
}

TEST(DiriginteTest, InputOperatorOverload) {
    Diriginte diriginte;
    std::istringstream input("John Doe\nMathematics\n10\n11C");
    input >> diriginte;

    EXPECT_EQ(diriginte.getnume_profesor(), "John Doe");
}



//CLASA:
TEST(ClasaTest, ConstructorWithParameters) {
    Profesor profesor("John Doe", "Mathematics", 10);
    Diriginte diriginte(profesor,"10A");
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    Materie m3("Physics", {10, 10}, 2);
    std::vector<Materie> materii = {m1, m2};
    std::vector<Materie> materii1 = {m1, m3};
    Elev elevi[3] = {Elev("Alice",2,materii), Elev("Bob",1,materii1)};
    Clasa clasa("10A", diriginte, elevi, 2);

    EXPECT_EQ(clasa.getnume(), "10A");
    EXPECT_EQ(clasa.getnrelevi(), 2);
    EXPECT_EQ(clasa.getdiriginte().getnume_profesor(), "John Doe");
}

TEST(ClasaTest, DefaultConstructor) {
    Clasa clasa;

    EXPECT_EQ(clasa.getnume(), "");
    EXPECT_EQ(clasa.getnrelevi(), 0);
}

TEST(ClasaTest, OutputOperatorOverload) {
    Profesor profesor("Alice Smith", "Physics", 5);
    Diriginte diriginte(profesor, "11B");
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    Materie m3("Physics", {10, 10}, 2);
    std::vector<Materie> materii = {m1, m2};
    std::vector<Materie> materii1 = {m1, m3};
    Elev elevi[3] = {Elev("Alice",2,materii), Elev("Bob",1,materii1)};
    Clasa clasa("11B", diriginte, elevi, 2);

    std::stringstream ss;
    ss << clasa;

    std::string expected_output = "Numele clasei: 11B\n";
    expected_output += "Diriginte: Alice Smith\n";
    expected_output += "Elevi:\n";
    expected_output += "Nr1: Alice--medie generala: 8.5--absente: 2\n";
    expected_output += "Nr2: Bob--medie generala: 9--absente: 1\n";

    EXPECT_EQ(ss.str(), expected_output);
}

TEST(ClasaTest, AdaugaElev) {
    Profesor profesor("Alice Smith", "Physics", 5);
    Diriginte diriginte(profesor, "11B");
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    Materie m3("Physics", {10, 10}, 2);
    std::vector<Materie> materii = {m1, m2};
    std::vector<Materie> materii1 = {m1, m3};
    std::vector<Materie> materii2 = {m2, m3};
    Elev elevi[3] = {Elev("Alice",2,materii), Elev("Bob",1,materii1)};
    Clasa clasa("11B", diriginte, elevi, 2);

    Elev elev("Bob",1,materii2);
    clasa.AdaugaElev(elev);

    EXPECT_EQ(clasa.getnrelevi(), 2);
    EXPECT_EQ(clasa.getelevi()[2].getnume_elev(), "Bob");
}

TEST(ClasaTest, ExmatriculeazaElev) {
    Profesor profesor("Alice Smith", "Physics", 5);
    Diriginte diriginte(profesor, "11B");
    Materie m1("Math", {8, 7, 9}, 3);
    Materie m2("Physics", {9, 8}, 2);
    Materie m3("Physics", {10, 10}, 2);
    std::vector<Materie> materii = {m1, m2};
    std::vector<Materie> materii1 = {m1, m3};
    Elev elevi[3] = {Elev("Alice",2,materii), Elev("Bob",1,materii1)};
    Clasa clasa("11B", diriginte, elevi, 2);

    clasa.ExmatriculeazaElev("Alice");

    EXPECT_EQ(clasa.getnrelevi(), 1);
    EXPECT_EQ(clasa.getelevi()[0].getnume_elev(), "Bob");
}


TEST(DirectorTest, StatutTest) {
    Profesor profesor{"John Doe", "Math", 20};
    Director director{profesor, 2020};
    // Not testing output since it goes to standard output
    director.Statut();
}