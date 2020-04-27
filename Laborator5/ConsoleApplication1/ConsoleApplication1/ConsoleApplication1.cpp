#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <cstdlib>
#include <conio.h>



using namespace std;

class StringWork {
public:
	int countNumberOfWords(string sentence) {
		int numberOfWords = 0;
		size_t i;

		if (isalpha(sentence[0])) {
			numberOfWords++;
		}

		for (i = 1; i < sentence.length(); i++) {
			if ((isalpha(sentence[i])) && (!isalpha(sentence[i - 1]))) {
				numberOfWords++;
			}
		}
		return numberOfWords;
	}

	void TwoLetters(string sentence) {
		size_t i;
		istringstream ss(sentence);

		do {
			string word;
			ss >> word;
			for (i = 0; i < word.length(); i++) {
				if ((word[i] == word[i + 1]) && (isalpha(word[i]))) {
					cout << word << endl;
				}
			}
		} while (ss);
	}

	bool contain(string word) {
		size_t i;
		bool flag = true;
		for (i = 0; i < word.length(); i++) {
			if (word[i] == word[i + 1]) {
				flag = false;
			}
		}
		if (flag) {
			return true;
		}
		else return false;
	}


	string DeleteTwoLetters(string& sentence) {
		string result;
		size_t i;
		istringstream ss(sentence);
		do {
			string word;
			ss >> word;
			cout << word << endl;
			if (contain(word)) {
				result +=  " " + word;
			}
		} while (ss);
		sentence = result;
		return sentence;
	}

	int numberOfWordsInFile() {
		int sum = 0;
		string line;
		ifstream MyReadFile("ex.txt");
		while (getline(MyReadFile, line)) {
			sum += countNumberOfWords(line);
		}
		MyReadFile.close();
		return sum;
	}

	void writeToFile(string& sentence) {
		size_t i;
		ofstream out("out.txt");
		istringstream ss(sentence);
		do {
			string word;
			ss >> word;
			for (i = 0; i < word.length(); i++) {
				if ((word[i] == word[i + 1]) && (isalpha(word[i]))) {
					out << word << " ";
				}
			}
		} while (ss);
		out.close();
	}
	void deleteFromFile(string sentence) {
		size_t i;
		ofstream out("out.txt");
		out << DeleteTwoLetters(sentence) << " ";
		out.close();
	}
};


int main()
{
	StringWork work;
	string text;
	int key;

	cout << "Dati stringul" << endl;
	getline(cin, text);

	do {
		system("cls");
		cout << "1. De determinat numarul de cuvinte din fraza." << endl;
		cout << "2. De determinat cuvintele dintr-o fraza care are doua litere identice." << endl;
		cout << "3. De sters cuvintele dintr-o fraza care are 2 litere identice." << endl;
		cout << "4. In fisier de determinat numarul de cuvinte." << endl;
		cout << "5. De inscris in alt fisier cuvintele care au 2 litere identice." << endl;
		cout << "6. De sters cuvintele dintr-un fisier text care au 2 litere identice." << endl;
		cout << "0. Exit" << endl;

		cout << "\t\t Selecteaza Optiunea ==> ";
		cin >> key;

		switch (key) {
		case 1:
			system("cls");
			cout << "Numarul de cuvinte in fraza sunt: " << work.countNumberOfWords(text);
			_getch();
			break;

		case 2:
			system("cls");
			cout << "Cuvintele care au 2 litere identice:\n";
			work.TwoLetters(text);
			_getch();
			break;

		case 3:
			system("cls");
			cout << "Cuvintele cu 2 litere identice sterse: \n" << work.DeleteTwoLetters(text);
			_getch();
			break;

		case 4:
			system("cls");
			cout << "Numarul de cuvinte in fisier: \n" << work.numberOfWordsInFile();
			_getch();
			break;

		case 5:
			system("cls");
			work.writeToFile(text);
			cout << "In fisier au fost inscrise cuvintele ce satisfac conditia.";
			_getch();
			break;

		case 6:
			system("cls");
			work.deleteFromFile(text);
			cout << "Au fost sterse cuvintele ce satisfac conditia." << endl;
			_getch();
			break;
		}
	} while (key != 0);

}

