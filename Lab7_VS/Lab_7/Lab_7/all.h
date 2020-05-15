#ifndef AllFUNCTIONS
#define AllFUNCTIONS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

class Agenda {
private:
    int id;
    string nume;
    int data;
    int luna;
    int anul;
    string adresa;
    int telefon;
    string email;

public:
    Agenda();

    Agenda(const string& line);

    void writeElement();

    int getId();

    string getNume();

    int getData();

    int getLuna();

    int getAnul();
    
    string getAdresa();

    int getPhone();

    string getEmail();
};

class Work {
protected:
    vector<Agenda> group;

private:
    Agenda createAgenda();

public:
    void readTextFile(const string& file);

    void writeBinFile(const string& file);

    void readBinFile(const string& file);

    void writeElements();

    void sortByName();

    void sortByYear();

    void addAgenda();

    void updateAgenda();

    void deleteAgenda(int id);
    void eldest();
};

#endif