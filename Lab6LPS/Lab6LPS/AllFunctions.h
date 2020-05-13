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

struct dataNasterii {
    int data;
    int luna;
    int anul;
};

struct Agenda {
    int id;
    string nume;
    dataNasterii datan;
    string adresa;
    string telefon;
    string email;
};

void readTextFile(vector <Agenda>& array, const string& file);
void writeBinFile(vector<Agenda>& array, const string& file);
Agenda parse(vector <Agenda>& array, const string& line);
void readBinFile(vector<Agenda>& array, const string& file);
void writeElements(vector<Agenda>& array);
Agenda createBuff();
void addElement(vector<Agenda>& array);
void changeElement(vector<Agenda>& array);
void swap(string* xp, string* yp);
void sortByName(vector<Agenda>& array);
void sortTwoKeys(vector<Agenda>& array);
void eldest(vector<Agenda>& array);
void deleteElem(vector<Agenda>& array, int position);
#endif