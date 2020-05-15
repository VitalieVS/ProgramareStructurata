#include "all.h"

Agenda::Agenda() {
    id = 0;
    nume = "";
    data = 0;
    luna = 0;
    anul = 0;
    adresa = "";
    telefon = 0;
    email = "";
};

Agenda::Agenda(const string& line) {
    int elemN = 0;
    string word;
    istringstream stream(line);
    while (stream) {
        stream >> word;

        switch (elemN) {
        case 0:
            id = stoi(word);
            break;
        case 1:
            nume = word;
            break;
        case 2:
            data = stoi(word);
            break;
        case 3:
            luna = stoi(word);
            break;
        case 4:
            anul = stoi(word);
            break;
        case 5:
            adresa = word;
            break;
        case 6:
            telefon = stoi(word);
            break;
        case 7:
            email = word;
        }
        elemN++;
    }
}

void Agenda::writeElement() {
    cout << "Id: " << id
        << " Nume: " << nume
        << " Data Nasterii: " << data << '.' << luna << '.' << anul
        << " Telefon: " << telefon
        << " Email: " << email << endl;
}

int Agenda::getId() {
    return id;
}

string Agenda::getNume() {
    return nume;
}

string Agenda::getAdresa() {
    return adresa;
}

int Agenda::getData() {
    return data;
}

int Agenda::getLuna() {
    return luna;
}

int Agenda::getAnul() {
    return anul;
}

int Agenda::getPhone() {
    return telefon;
}

string Agenda::getEmail() {
    return email;
}

void Work::readTextFile(const string& file) {
    string line;
    ifstream readFile(file);

    while (getline(readFile, line)) {
        Agenda buffer(line);
        group.push_back(buffer);
    }
    readFile.close();
}

void Work::writeBinFile(const string& file) {
    Agenda agenda;
    ofstream writeFile(file, ios::binary);
    for (auto& agenda : group) {
        writeFile.write((char*)&agenda, sizeof(group));
    }

    writeFile.close();
}

void Work::readBinFile(const string& file) {
    group.clear();
    Agenda agenda;

    ifstream readFile(file, ios::binary);
    while (readFile.read((char*)&agenda, sizeof(agenda))) {
       cout << agenda.getId();
        group.push_back(agenda);
    }
    readFile.close();
    writeElements();
}

void Work::writeElements() {
    for (int i = 0; i < group.size(); i++) {
        group[i].writeElement();
    }
}


void Work::sortByName() {
   for (int i = 0; i < group.size() - 1; i++)
        for (int j = 0; j < group.size() - i - 1; j++)
          if (group[j].getNume() > group[j + 1].getNume())
              swap(group[j], group[j + 1]);
          writeElements();
}

void Work::sortByYear() {
    for (int i = 0; i < group.size() - 1; i++)
        for (int j = 0; j < group.size() - i - 1; j++)
            if (group[j].getAnul() > group[j + 1].getAnul())
                swap(group[j], group[j + 1]);

    writeElements();
}

Agenda Work::createAgenda() {
    string line;
    cin.ignore(1000, '\n');

    cout << "ID Nume DataN LunaN AnulN Adresa Telefon Email:"
        << endl;
    getline(cin, line);
    cout << line;
    Agenda agenda(line);
    return agenda;
}

void Work::addAgenda() {
    group.push_back(createAgenda());
    writeElements();
}

void Work::updateAgenda() {
    Agenda agenda = createAgenda();

    if (agenda.getId() >= 0 && agenda.getId() < group.size()) {
        group[agenda.getId()] = agenda;
    }
    else {
        cout << "Optiune gresita";
    }

    writeElements();
}

void Work::deleteAgenda(int id) {
    if (id < group.size() && id > 0) {
        group.erase(group.begin() + id);
        writeElements();
    }
    else {
        cout << "Pozitie gresita";
    }
}

void Work::eldest() {
    int max = 0;
    string name;
    for (int i = 0; i < group.size(); i++) {
        if (group[i].getAnul() > max) {
            max = group[i].getAnul();
            name = group[i].getNume();
        }
    }
    cout << "Cel mai tinar este nascut in: " << max << " Si il cheama:" << name;
}