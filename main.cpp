#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <exception>
#include "exceptie.h"
#include "persoana.h"
#include "materie.h"
#include "elev.h"
#include "bursier.h"
#include "profesor.h"
#include "diriginte.h"
#include "clasa.h"
#include "director.h"
using namespace std;




void Satut_cadru_didactic(Profesor& p){
    cout<<"Statut: ";
    p.Statut();
    cout<<endl;
}


int main() {
    vector<Persoana*>Pers;
    vector<Profesor>P;
    Profesor P1("Daniel Fugulin", "Matematica", 30), P2("Nicu Cristinel", "Sport", 15), P3("Fugulin Sivia", "Romana",20), P4("Visenescu Valeria","Biologie", 30),P5("Stanescu Gabriel","Fizica",23),P6("Stanescu Marcel", "Fizica", 40),P7("Chiriac Marius", "Muzica", 27),P8("Voica Cornelia Nicole", "Informatica", 36),P9("Duican Carmen", "Chimie",31),P10("Zaharia Adrian","Istorie",44),P11("Scarlat Valentin-Marius","Istorie",15);
    P.push_back(P1); P.push_back(P2); P.push_back(P3); P.push_back(P4);P.push_back(P5);P.push_back(P6);P.push_back(P7);P.push_back(P8);P.push_back(P9);P.push_back(P10);P.push_back(P11);
    vector<Diriginte>D;
    Diriginte D1(P1,"9A"),D2(P2,"12A"),D3(P3,"10A"),D4(P4,"11A");
    D.push_back(D1);D.push_back(D2); D.push_back(D3); D.push_back(D4);
    vector <int> v1 = {7, 9, 10};
    vector <int> v2 = {2, 10, 10};
    vector <int> v3 = {4, 4, 8};
    vector <int> v4 = {8, 8};
    vector <int> v5 = {10, 10, 10};
    vector <int> v6 = {4, 4, 5, 5};
    vector <int> v7 = {10, 10, 9, 10, 10};
    vector <int> v8 = {7,4,4,2};
    Materie M1("Matematica",v1,3),M2("Romana",v2,3),M3("Fizica",v3,3),M4("Informatica",v4,2),
            M5("Matematica",v4,2),M6("Romana",v5,3),M7("Fizica",v1,3),M8("Informatica",v2,3);
//    vector <Materie> m1={M1,M2,M3,M4},m2={M5,M6,M7,M8};
vector<Materie>m1;m1.push_back(M1);m1.push_back(M2);m1.push_back(M3);m1.push_back(M4);
vector<Materie>m2;m2.push_back(M5);m2.push_back(M6);m2.push_back(M7);m2.push_back(M8);
    Elev elevi1[2], e1("Telu Andrei",10,m1), e2("Pandeliu Casian",4,m2);
    elevi1[0] = e1;
    elevi1[1] = e2;
    Materie M9("Matematica",v1,3),M10("Romana",v7,5),M11("Fizica",v2,3),M12("Informatica",v6,4);
//    vector <Materie> m3={M9,M10,M11,M12};
vector<Materie>m3;m3.push_back(M9);m3.push_back(M10);m3.push_back(M11);m3.push_back(M12);
    Elev elevi2[1], e3("Anton Anelis", 3,m3);
    elevi2[0] = e3;
    Materie M13("Matematica",v5,3),M14("Romana",v6,4),M15("Fizica",v5,3),M16("Informatica",v3,3),M17("Matematica",v8,4),M18("Romana",v3,3),M19("Fizica",v3,3),M20("Informatica",v3,3),M21("Matematica",v3,3),M22("Romana",v5,3),M23("Fizica",v2,3),M24("Informatica",v2,3);
//    vector <Materie> m4={M13,M14,M15,M16},m5={M17,M18,M19,M20},m6={M21,M22,M23,M24};
vector<Materie>m4;m4.push_back(M13);m4.push_back(M14);m4.push_back(M15);m4.push_back(M16);
vector<Materie>m5;m5.push_back(M17);m5.push_back(M18);m5.push_back(M19);m5.push_back(M20);
vector<Materie>m6;m6.push_back(M21);m6.push_back(M22);m6.push_back(M23);m6.push_back(M24);
    Elev elevi3[3], e4("Gheorghe Marius-Andrei", 20, m4), e5("Vanocea Sebi",20,m5), e6("Bilous Vlad",5,m6);
    elevi3[0] = e4;
    elevi3[1] = e5;
    elevi3[2] = e6;
//    vector <Materie> m7={M1,M14,M24},m8={M13,M18,M20},m9={M21,M22,M16},m10={M1,M10,M4};
vector<Materie>m7;m7.push_back(M1);m7.push_back(M14);m7.push_back(M24);
vector<Materie>m8;m8.push_back(M13);m8.push_back(M18);m8.push_back(M20);
vector<Materie>m9;m9.push_back(M21);m9.push_back(M22);m9.push_back(M16);
vector<Materie>m10;m10.push_back(M1);m10.push_back(M10);m10.push_back(M4);
    Elev elevi4[4], e7("Telu Mihai",0,m7), e8("Fugulin Victor-Gabriel",0,m8), e9("Serban Alexandru",3,m9), e10("Ciuca Teodora",1,m10);
    elevi4[0] = e7;
    elevi4[1] = e8;
    elevi4[2] = e9;
    elevi4[3] = e10;

    Clasa C1("9A", D1, elevi1, 2), C2("10A", D3, elevi2, 1), C3("11A", D4, elevi3, 3), C4("12A", D2, elevi4, 4  );
    Clasa clase[12];
    clase[0] = C1;
    clase[1] = C2;
    clase[2] = C3;
    clase[3] = C4;
    int nr_clase = 4;


    Bursier b1("Pandeliu Casian",4,m2,"Bursa_de_merit",500);
    Bursier b2("Telu Mihai",0,m7,"Bursa_sociala",300);
    Bursier b3("Gheorghe Marius-Andrei", 20, m4,"Bursa_de_performata",1000);
    Bursier b4("Gheorghe Marius-Andrei", 20, m4,"Bursa_sociala",300);
    Elev *E1=&b1, *E2=&b2, *E3=&b3;

    auto* B1=dynamic_cast<Bursier*>(E1);
    auto* B2=dynamic_cast<Bursier*>(E2);
    auto* B3=dynamic_cast<Bursier*>(E3);

    vector<Elev*>E;
    E.push_back(&e1);E.push_back(&b1);E.push_back(&e3);E.push_back(&b3);E.push_back(&e5);E.push_back(&e6);E.push_back(&b2);E.push_back(&e8);E.push_back(&e9);E.push_back(&e10);
    vector<Bursier*>B;
    B.push_back(B1); B.push_back(B2); B.push_back(B3);B.push_back(&b4);
    Pers.reserve(P.size());
    for(auto & i : P)Pers.push_back(&i);
    for(auto & i : E)Pers.push_back(i);

    vector<Bursier*>Bref;
    vector<Elev*>Eref;
    vector<Diriginte*>Dref;
    vector<Profesor*>Pref;


    Director Dir(P1,2000);

    int n;
    do {
        cout << "          MENIU-CATALOAGELE LICEULUI X    " << endl;
        cout << "Apasa 1 pentru OPTIUNI-CLASE" << endl;
        cout << "Apasa 2 pentru OPTIUNI-ELEVI" << endl;
        cout << "Apasa 3 pentru OPTIUNI-PROFESORI" << endl;
        cout << "Apasa 4 pentru a vizualiza ISTORICUL LICEULUI" <<endl;
        cout << "Apasa 5 pentru a CAUTA UN ELEV DUPA INDEX(un numar-ordinea inscrierii-) in istoric" <<endl;
        cout << "Apasa 6 pentru informatii despre DIRECTOR" <<endl;
        cout << "Apasa 0 pentru A IESI" << endl;
        cin >> n;
        if(n==0){break;}
        switch (n) {
            case (1): {
                int n1;
                do {
                    cout << "          OPTIUNI-CLASE    "<<endl;
                    cout << "Apasa 1 pentru a vizualiza clasele" << endl;
                    cout << "Apasa 2 pentru a adauga o clasa noua" << endl;
                    cout << "Apasa 3 pentru a vizualiza media unei clase" << endl;
                    cout << "Apasa 4 pentru a adauga o materie noua unei clase"<<endl;
                    cout << "Apasa 5 pentru a vedea conditiile de promovare la o materie si elevii in stare de corigenta"<<endl;
                    cout << "Apasa 6 pentru a schimba conditiile de promovare"<< endl;
                    cout << "Apasa 0 pentru a te intoarce" << endl;
                    cin>>n1;
                    if(n1==0){break;}
                    switch (n1) {
                        case (1): {
                            int x = 0;
                            for (int i = 0; i < nr_clase-1; i += 2)
                                x += clase[i] + clase[i + 1];
                            if (nr_clase % 2 == 1)x += clase[nr_clase - 1].getnrelevi();
                            cout << "Liceul X are in acest moment " << x << " elevi." << endl;
                            cout << "Clase: "<<endl;
                            int egal=0;
                            for(int i=0;i<nr_clase;i++)
                                for(int j=i+1;j<nr_clase;j++)
                                    if(clase[i].getnume()==clase[j].getnume())
                                        egal=1;
                            for (int i = 0; i < nr_clase; i++) {
                                cout << clase[i] << endl;
                            }
                            if(egal==1)
                                cout<<"Exista clase ce par a fi identice!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        case (2): {
                            cout<<"Clasa noua "<<endl;
                            cout<< "Pot exista maxim 12 clase, iar denumirea unei clase va fi de forma XY, X={9,10,11,12}, Y={A,B,C,D} si ar trebui sa difere de a celorlalte(optional). Un nume valid va fi marcat prin <<ACCEPTAT!>>."<< endl;
                            cin >> clase[nr_clase];
                            Diriginte d;
                            d=clase[nr_clase].getdiriginte();
                            D.push_back(d);
                            int ok=0;
                            for(auto & i : P)
                                if(d==i)ok=1;
                            if(ok==0){P.push_back(d);Pers.push_back(&P[P.size()-1]);}
                            nr_clase++;
                            cout<<endl<<endl<<endl;
                            break;
                        }


                        case(3):{
                            cout<<"Media unei clase "<<endl;
                            cout<<"Nume clasa(de forma XY, X={9,10,11,12}, Y={A,B,C,D}): ";
                            string s;
                            cin.get();
                            getline(cin,s);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++)
                            {
                                if(clase[i].getnume()==s){
                                    cout<<clase[i].MediaClasei()<<endl;
                                    ok=1;
                                    break;
                                }
                            }
                            if(ok==0)cout<<"Nu exista aceasta clasa!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        case (4): {
                            cout<<"Materie noua "<<endl;
                            string numeMaterie,numeClasa;
                            cout<<"Denumirea clasei: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Denumirea materie: ";
                            getline(cin,numeMaterie);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++)
                                if(clase[i].getnume()==numeClasa){
                                    ok=1;
                                    Materie m(numeMaterie);
                                    clase[i].adauga_materie_noua(m);
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        for(auto & k : E){
                                            if(clase[i].getelevi()[j].getnume_elev()==k->getnume_elev())
                                                k->aduga_materie(m);
                                        }
                                }
                            if(ok==0)cout<<"Nu exista aceasta clasa!!!";
                            cout<<endl<<endl<<endl;
                            break;
                        }


                        case (5): {
                            cout<<"Conditiile de promovare pentru orice materie sunt ca: numarul de note sa fie cel putin egal cu "<<Materie::get_nrminnote()<<" si ca media sa fie cel putin 5."<<endl;
                            cout<<"Elevi in stare de corigenta:"<<endl;
                            for(auto & i : E){
                                int ok=1;
                                if(i->get_materii().empty()) ok=0;
                                for(unsigned long long j=0;j<i->get_materii().size();j++)
                                    if(i->get_materii()[j].get_nr_note()<Materie::get_nrminnote()||i->get_materii()[j].medie()<5)
                                        ok=0;
                                if(ok==0)cout<<i->getnume_elev()<<endl;
                            }
                            cout<<endl<<endl<<endl;
                            break;
                        }

                        case (6): {
                            cout<<"Noile conditii de promovare"<<endl;
                            int min;
                            cout<<"Numar minim de note necesar promovarii: ";
                            cin>>min;
                            Materie::set_nrminnote(min);
                            cout<<endl<<endl<<endl;
                            break;
                        }


                        default:{
                            cout<<endl<<endl<<endl;
                            break;
                        }
                    }
                }while(n1!=0);
                cout<<endl<<endl<<endl<<endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                break;
            }




            case(2): {
                int n2;
                do{
                    cout<<"        OPTIUNI-ELEVI     "<<endl;
                    cout<<"Apasa 1 pentru a vizualiza datele unui elev"<<endl;
                    cout<<"Apasa 2 pentru a adauga un nou elev"<<endl;
                    cout<<"Apasa 3 pentru a exmatricula un elev"<<endl;
                    cout<<"Apasa 4 pentru a pune o nota"<<endl;
                    cout<<"Apasa 5 pentru a pune o absenta"<<endl;
                    cout<<"Apasa 6 pentru a vizualiza elevii liceului"<<endl;
                    cout<<"Apasa 7 pentru a vizualiza elevii bursieri ai liceului"<<endl;
                    cout<<"Apasa 8 pentru a adauga bursa"<<endl;
                    cout << "Apasa 0 pentru a te intoarce" << endl;
                    cin>>n2;
                    if(n2==0){break;}
                    switch (n2) {
                        case(1):{
                            cout<<"Datele unui elev"<<endl;
                            string numeElev,numeClasa;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++){
                                if(clase[i].getnume()==numeClasa)
                                {
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        if(clase[i].getelevi()[j].getnume_elev()==numeElev)
                                        {cout<<clase[i].getelevi()[j]<<endl;ok=1;}
                                }
                            }
                            if(ok==0)cout<<"Nu exista clasa mentionata ori elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        case(2):{
                            cout<<"Adauga elev nou"<<endl;
                            string numeClasa,numeElev;
                            cout<<"Numele clasei in care vrem sa-l adaugam: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele noului elev: ";
                            getline(cin,numeElev);
                            Elev* e= new Elev(numeElev);
                            Eref.push_back(e);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++)
                                if(clase[i].getnume()==numeClasa)
                                {clase[i].AdaugaElev(*e);++clase[i];cout<<endl;ok=1;Pers.push_back(e);E.push_back(e);}
                            if(ok==0)cout<<"Nu exista clasa mentionata!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        case(3):{
                            cout<<"Exmatriculeaza elev"<<endl;
                            string numeClasa,numeElev;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++)
                                if(clase[i].getnume()==numeClasa)
                                {clase[i].ExmatriculeazaElev(numeElev);
                                    vector<Elev*>Ee;
                                    for(auto & k : E){
                                        if(numeElev!=k->getnume_elev())
                                            Ee.push_back(k);
                                    }
                                    E.resize(0);
                                    for(auto k : Ee)E.push_back(k);
                                    cout<<endl;ok=1;}
                            if(ok==0)cout<<"Nu exista clasa mentionata sau elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        case(4):{
                            cout<<"Pune nota"<<endl;
                            string numeClasa,numeElev,materia;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            cout<<"Materia la care se pune nota(Matematica, Romana, Fizica, Informatica etc.): ";
                            getline(cin,materia);
                            int nota;
                            cout<<"Nota: ";
                            cin>>nota;
                            cout<<endl;
                            int ok=0;
                            for(int i=0;i<nr_clase;i++){
                                if(clase[i].getnume()==numeClasa)
                                {
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        if(clase[i].getelevi()[j].getnume_elev()==numeElev)
                                        {clase[i].getelevi()[j].PuneNota(materia,nota);
                                            for(auto & k : E){
                                                if(clase[i].getelevi()[j].getnume_elev()==k->getnume_elev())
                                                    k->PuneNota(materia,nota);
                                            }
                                            cout<<endl;ok=1;}

                                }
                            }
                            if(ok==0)cout<<"Nu exista clasa mentionata ori elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        case(5):{
                            cout<<"Pune absenta"<<endl;
                            string numeClasa,numeElev;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            int ok=0;
                            for(int i=0;i<nr_clase;i++){
                                if(clase[i].getnume()==numeClasa)
                                {
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        if(clase[i].getelevi()[j].getnume_elev()==numeElev)
                                        {clase[i].getelevi()[j].PuneAbsenta();
                                            for(auto & k : E){
                                                if(clase[i].getelevi()[j].getnume_elev()==k->getnume_elev())
                                                    k->PuneAbsenta();
                                            }
                                            cout<<endl;ok=1;}

                                }
                            }
                            if(ok==0)cout<<"Nu exista clasa mentionata ori elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        case(6):{
                            cout<<"Elevii liceului"<<endl;
                            for(auto & i : E)
                            {
                                i->afis();
                                Elev::scrie();
                            }
                            cout<<endl<<endl;
                            break;
                        }


                        case(7):{
                            cout<<"Bursierii liceului(in prezent)"<<endl;///Cel mai bun exemplu de downcasting:)))
                            int nr=0;
                            for(auto & i : E)
                            { if(dynamic_cast<Bursier*>(i)) {
                                    dynamic_cast<Bursier *>(i)->afis();//Se vede utilizare lui virtual si
                                    cout<<Bursier::scrie(nr);//se vede, ca desi se lucreaza cu un poiter de tipul bazei-Elev, el este convertit in (pointer de)tipul obiectului la care refera(derivat-Bursier) si se apeleaza o metoda specifica derivatei, care nu era permisa fara downcasting.
                                    cout<<endl<<endl;
                                    nr++;
                                }
                            }
                            cout<<"Sunt, deci, "<<nr<<" elevi bursieri.";
                            cout<<endl<<endl<<endl;
                            cout<<"Bursele detinute(sau care au fost detinute!) de fiecare"<<endl;
                            for(auto & i : B)
                            {
                                i->scrie();
                            }
                            cout<<endl<<endl;
                            break;
                            ///Nu puteam sa iterez direct in vectorul B, intrucat acolo se pot afla elevi cu mai multe burse, iar eu doresc sa stiu doar cati au bursa si care sunt acestia, nu specificatii despre bursa/bursele lor.
                        }


                        case(8):{
                            cout<<"Adauga bursa"<<endl;
                            string numeElev,numeClasa,bursa;
                            int suma;
                            cout<<"Numele clasei din care face parte: ";
                            cin.get();
                            getline(cin,numeClasa);
                            cout<<"Numele elevului: ";
                            getline(cin,numeElev);
                            cout<<"Bursa (Un elev nu poate primi aceeasi bursa de 2 ori!): ";
                            getline(cin,bursa);
                            cout<<"Suma: ";
                            cin>>suma;
                            int ok=0;
                            for(int i=0;i<nr_clase;i++){
                                if(clase[i].getnume()==numeClasa)
                                {
                                    for(int j=0;j<clase[i].getnrelevi();j++)
                                        if(clase[i].getelevi()[j].getnume_elev()==numeElev)
                                        {auto* b= new Bursier(clase[i].getelevi()[j],bursa,suma);
                                            Bref.push_back(b);
                                            int ok1=1;
                                            for(auto & k : B)
                                                if(k->getnume_elev()==b->getnume_elev()&&k->get_bursa()==b->get_bursa())ok1=0;
                                            if(ok1==1) B.push_back(b);
                                            int ok2=-1;
                                            for(unsigned long long k=0;k<E.size();k++)
                                                if(E[k]->getnume_elev()==b->getnume_elev())ok2=(int)k;
                                            if(ok2!=-1) E[ok2]=b;
                                            ok=1;}
                                }
                            }
                            if(ok==0)cout<<"Nu exista clasa mentionata ori elevul respectiv in clasa mentionata!!!"<<endl;
                            cout<<endl<<endl;
                            break;
                        }


                        default:{
                            cout<<endl<<endl<<endl;
                            break;
                        }
                    }
                }while(n2!=0);
                cout<<endl<<endl<<endl<<endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                break;
            }




            case(3): {
                int n3;
                do{
                    cout << "          OPTIUNI-PROFESORI     " << endl;
                    cout << "Apasa 1 pentru a OPTIUNI-DIRIGINTE" << endl;
                    cout << "Apasa 2 pentru a vizualiza profesorii" << endl;
                    cout << "Apasa 3 pentru a adauga un profesor" << endl;
                    cout << "Apasa 0 pentru a te intoarce" << endl;
                    cin>>n3;
                    if(n3==0){break;}
                    switch (n3) {
                        case (1): {
                            int a;
                            do {
                                cout << "          OPTIUNI-DIRIGINTE     " << endl;
                                cout << "Apasa 1 pentru a vizualiza datele unui diriginte" << endl;
                                cout << "Apasa 2 pentru a adauga ani vechime" << endl;
                                cout << "Apasa 3 pentru a schimba dirigintele unei clase" << endl;
                                cout << "Apasa 4 pentru a vizualiza dirigintii liceului"<<endl;
                                cout << "Apasa 0 pentru a te intoarce" << endl;
                                cin >> a;
                                if (a == 0) { break; }
                                switch (a) {
                                    case (1): {
                                        cout << "Datele unui diriginte" << endl;
                                        string numeClasa;
                                        cout << "Numele clasei: ";
                                        cin.get();
                                        getline(cin, numeClasa);
                                        int ok = 0;
                                        for (int i = 0; i < nr_clase; i++) {
                                            if (clase[i].getnume() == numeClasa) {
                                                cout << clase[i].getdiriginte() << endl;
                                                ok = 1;
                                            }
                                        }
                                        if (ok == 0)cout << "Nu exista clasa respectiva!!!" << endl;
                                        cout << endl;
                                        break;
                                    }

                                    case (2): {
                                        cout << "Adauga ani vechime" << endl;
                                        string numeClasa;
                                        cout << "Numele clasei: ";
                                        cin.get();
                                        getline(cin, numeClasa);
                                        int ok = 0;
                                        for (int i = 0; i < nr_clase; i++) {
                                            if (clase[i].getnume() == numeClasa) {
                                                for(auto & j : D)
                                                    if(j==clase[i].getdiriginte())
                                                        j.AdaugareVchime();
                                                for(auto & j : P)
                                                    if(j==clase[i].getdiriginte())
                                                        j.AdaugareVchime();
                                                clase[i].setvechime();
                                                cout << endl;
                                                ok = 1;
                                            }
                                        }
                                        if (ok == 0)cout << "Nu exista clasa respectiva!!!" << endl;
                                        cout << endl;
                                        break;
                                    }

                                    case (3): {
                                        cout << "Schimba dirigintele" << endl;
                                        string numeClasa;
                                        cout << "Numele clasei: ";
                                        cin.get();
                                        getline(cin, numeClasa);
                                        int ok = 0;
                                        for (int i = 0; i < nr_clase; i++) {
                                            if (clase[i].getnume() == numeClasa) {
                                                cout << "Datele noului diriginte: " << endl;
                                                auto* d=new Diriginte();
                                                Dref.push_back(d);
                                                cin>>*d;
                                                auto* p=new Diriginte();
                                                Dref.push_back(p);
                                                *p=clase[i].getdiriginte();
                                                int ok3=0;
                                                for(auto & j : D)
                                                    if(j==*d)
                                                        ok3=1;
                                                if(ok3==0){
                                                    int ok2=0;
                                                    for(auto & j : P)
                                                        if(j==*d)ok2=1;
                                                    if(ok2==0){P.push_back(*d);Pers.push_back(d);}
                                                    D.push_back(*d);
                                                    clase[i].SchimbaDiriginte(*d);
                                                    vector<Diriginte>Dd;
                                                    for(auto & k : D)
                                                        if(!(k==*p))
                                                            Dd.push_back(k);
                                                    D.resize(0);
                                                    for(const auto & l : Dd)
                                                        D.push_back(l);
                                                }
                                                cout << endl;
                                                ok = 1-ok3;
                                                break;
                                            }
                                        }
                                        if (ok == 0)cout << "Nu exista clasa respectiva ori este imposibil sa se schimbe dirigintele!!!" << endl;
                                        cout << endl;
                                        break;
                                    }

                                    case (4): {
                                        cout<<"Diriginti"<<endl;
                                        for(auto & i : D)
                                            Satut_cadru_didactic(i);
                                        cout << endl;
                                        break;
                                    }

                                    default: {
                                        cout << endl << endl;
                                        break;
                                    }
                                }
                            } while (a != 0);
                            cout << endl << endl << endl;
                            break;
                        }


                        case (2): {
                            cout << "Vizualizare - cadre didactice" << endl;
                            for(auto & i : P) {
                                int ok = 0;
                                for (auto & j : D)
                                    if (i == j) {
                                        ok = 1;
                                        Satut_cadru_didactic(j);
                                    }
                                if(ok==0) Satut_cadru_didactic(i);
                            }
                            cout << endl << endl << endl;
                            break;
                        }


                        case (3): {
                            cout << "Adauga profesor" << endl;
                            int ok=0;
                            auto* p=new Profesor();
                            Pref.push_back(p);
                            cin.get();
                            cin>>*p;
                            for(auto & i : P)
                                if(i==*p)ok=1;
                            if (ok == 1)cout << "Deja exista profesorul respectiv!!!" << endl;
                            else{
                                P.push_back(*p);
                                Pers.push_back(p);
                                cout<<endl;
                            }
                            cout << endl;
                            break;
                        }


                        default:{
                            cout<<endl<<endl<<endl;
                            break;
                        }
                    }
                }while(n3!=0);
                cout << endl << endl << endl << endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                break;
            }




            case(4):{
                cout<<"Persoanle care populeaza ori au populat liceul X:"<<endl;
                for(auto & Per : Pers)
                    Per->descriere();
                cout << endl << endl << endl << endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                break;
            }




            case(5):{
                cout<<"Index:";
                int index;
                cin>>index;
                cout<<endl;
                try {
                    if (index < 0 || index >= (int)E.size()) {
                        throw Exceptie();
                    } else {
                        cout <<"Elementul de la indexul "<<index<<" este: "<<E[index]->getnume_elev()<<"."<<endl;
                    }
                } catch (Exceptie& e) {
                    cout<<"Eroare: "<< e.what() <<endl;
                }
                cout << endl << endl << endl << endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                break;
            }






            case(6):{
                cout<<"Directorul liceului X:"<<endl;
                Satut_cadru_didactic(Dir);
                cout << endl << endl << endl << endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                break;
            }



            default:{
                cout<<endl<<endl<<endl<<endl;
                break;
            }
        }
    }while (n != 0);



    for(auto & i : Eref)delete i;
    for(auto & i : Bref)delete i;
    for(auto & i : Pref)delete i;
    for(auto & i : Dref)delete i;
}

