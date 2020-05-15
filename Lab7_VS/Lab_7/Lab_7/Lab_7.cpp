#include "all.h"

int main() {
    string file1 = "agenda.txt";
    string file2 = "bin.txt";
    Work work;
    char key;
    int deletePosition;

    work.readTextFile(file1);

    do {
        cout << endl
            << "Alege optiune: " << endl
            << "1. Copiaza datele in fisierul binar. " << endl
            << "2. Afiseaza din fisierul binar. " << endl
            << "3. Sorteza dupa nume. " << endl
            << "4. Sorteaza dupa an: " << endl
            << "5. Adauga un om nou: " << endl
            << "6. Sterge un om: " << endl
            << "7. Modifica un om: " << endl
            << "8. Cel mai tinar: " << endl
            << "0. Exit" << endl;

        cin >> key;
        system("CLS");

        switch (key) {
        case '1':
            work.writeBinFile(file2);
            cout << "Done";
            break;

        case '2':
            cout << "Binar: ";
            work.readBinFile(file2);
            break;

        case '3':
            cout << "Sortat: ";
            work.sortByName();
            break;

        case '4':
            cout << "Sortat: ";
            work.sortByYear();
            break;

        case '5':
            work.addAgenda();
            break;

        case '6':
            cout << "Poz de a sterge: ";
            cin >> deletePosition;
            work.deleteAgenda(deletePosition);
            break;

        case '7':
            work.updateAgenda();
            break;

        case '8':
            work.eldest();
            break;

        case '0':
            cout << "Done!";
            break;

        default:
            cout << "Wrong";
            break;
        }

    } while (key != '0');

    return 0;
}