#include "AllFunctions.h"

void readTextFile(vector<Agenda> &array, const string& file)
{
    string line;
   ifstream readFile(file);

    while (getline(readFile, line)) {
       array.push_back(parse(array, line));
    }
   readFile.close();
}

Agenda parse(vector <Agenda>& array, const string& line) {
        Agenda buffer;
        int elementNumber = 0;
        string word;
        istringstream stream(line);
        while (stream) {
            stream >> word;
            switch (elementNumber) {
            case 0:
                buffer.id = stoi(word);
                break;
            case 1:
                buffer.nume = word;
                break;
            case 2:
                buffer.datan.data = stoi(word);
                break;
            case 3:
                buffer.datan.luna = stoi(word);
                break;
            case 4:
                buffer.datan.anul = stoi(word);
                break;
            case 5:
                buffer.adresa = word;
                break;
            case 6:
                buffer.telefon= word;
                break;
            case 7:
                buffer.email = word;
            }
            elementNumber++;
        }
        return buffer;
    }

void writeBinFile(vector<Agenda>& array, const string& file) {
    ofstream writeFile(file, ios::binary);

    for (int i = 0; i < array.size(); i++) {
        writeFile.write((char*)&array[i], sizeof(Agenda));
    }
    writeFile.close();
}

void readBinFile(vector<Agenda>& array, const string& file) {
    Agenda buffer;
    vector <Agenda> arr;

    ifstream readFile(file, ios::binary);
    while (readFile.read((char*)&buffer, sizeof(Agenda))) {
        arr.push_back(buffer);
    }

    readFile.close();
    writeElements(arr);
}

void writeElements(vector<Agenda>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout << "Id: " << array[i].id
            << " Nume: " << array[i].nume
            << "\n Data Nasterii: " << array[i].datan.data
            << " Luna Nasterii: " << array[i].datan.luna
            << "\n Anul Nasterii: " << array[i].datan.anul
            << " Adresa: " << array[i].adresa
            << " Nr de telefon: " << array[i].telefon
            << " Email: " << array[i].email << "\n -----------------" << endl;
    }
}

Agenda createBuff() {
    Agenda buffer;
    cout << "Id: ";
    cin >> buffer.id;
    cout << "Nume: ";
    cin >> buffer.nume;
    cout << "Data Nasterii: ";
    cin >> buffer.datan.data;
    cout << "Luna Nasterii: ";
    cin >> buffer.datan.luna;
    cout << "Anul Nasterii: ";
    cin >> buffer.datan.anul;
    cout << "Adresa: ";
    cin >> buffer.adresa;
    cout << "Telefon: ";
    cin >> buffer.telefon;
    cout << "Email: ";
    cin >> buffer.email;
    return buffer;
}

void addElement(vector<Agenda>& array) {
    array.push_back(createBuff());
    writeElements(array);
}

void changeElement(vector<Agenda>& array) {
    Agenda buffer = createBuff();
    if (buffer.id < array.size() || buffer.id > 0) {
        array[buffer.id].id = buffer.id;
        array[buffer.id].nume = buffer.nume;
        array[buffer.id].nume = buffer.nume;
        array[buffer.id].datan.data = buffer.datan.data;
        array[buffer.id].datan.luna = buffer.datan.luna;
        array[buffer.id].datan.anul = buffer.datan.anul;
        array[buffer.id].adresa = buffer.adresa;
        array[buffer.id].telefon = buffer.telefon;
        array[buffer.id].email = buffer.email;
        writeElements(array);
    }
    else {
        cout << "ID incorect";
    }
}

void swap(string* xp, string* yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortByName(vector<Agenda>& array) {
    for (int i = 0; i < array.size() - 1; i++)
        for (int j = 0; j < array.size() - i - 1; j++)
            if (array[j].nume > array[j+1].nume)
                swap(&array[j].nume, &array[j+1].nume);
                    writeElements(array);
}

void sortBy(vector<Agenda>& array) {
    for (int i = 0; i < array.size() - 1; i++)
        for (int j = 0; j < array.size() - i - 1; j++)
            if (array[j].nume > array[j+1].nume)
                swap(&array[j].nume, &array[j+1].nume);
    writeElements(array);
}

void sortTwoKeys(vector<Agenda>& array) {
    int key;
    Agenda count;
    for (int i = 0; i < array.size() - 1; i++) {
        count = array[i];
        key = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j].id < array[key].id) {
                key = j;
            }
            if (array[j].id == array[key].id) {
                if (array[j].datan.anul < array[key].datan.anul) {
                    key = j;
                }
                if (array[j].nume == array[key].nume) {
                    if (array[j].telefon < array[key].telefon) {
                        key = j;
                    }
                }
            }
        }

        if (key != i) {
            array[i] = array[key];
            array[key] = count;
        }
    }
    writeElements(array);
}

void eldest(vector<Agenda>& array) {
    int max = 0;
    for (int i = 0; i < array.size(); i++) {
        if (array[i].datan.anul > max) {
            max = array[i].datan.anul;
        }
    }
    cout << "Cel mai tinar este nascut in: " << max;
}

void deleteElem(vector<Agenda>& array, int position) {
    if (position < array.size() || position > 0) {
        array.erase(array.begin() + position);
        writeElements(array);
    }
    else {
        cout << "Pozitie gresita";
    }
}
