#include <iostream>

#include <conio.h>

#include <cstdlib>

using namespace std;

int
Pell(int n) {

  if (n == 1)

  {

    return true;

  } else

  {

    int a = 0;

    int b = 1;

    int c = 2 * b + a;

    while (c < n)

    {

      a = b;

      b = c;

      c = 2 * b + a;

    }

    return c == n;

  }

}

bool isPrime(int n) {

  if (n <= 1)

    return false;

  for (int i = 2; i < n; i++)

    if (n % i == 0)

      return false;

  return true;

}

int
main() {

  int key;

  int number, valueFrom, valueTo, count, validCount;

  int j;

  do

  {

    system("cls");

    cout << "1. De verificat daca numarul nnumarul este Pell sau nu." <<

      endl;

    cout <<

      "2. De indicat toate numerele din intervalul [a; b], care sunt Pell. "

      <<
      endl;

    cout << "3. De afisat primele n numere Pell" << endl;

    cout <<

      "4. De afisat toate numerele din intervalul [a,b] care satisfac II variante "

      <<
      endl;

    cout << "5. De afisat cel mai mare numar Pell" << endl;

    cout << "0. Exit" << endl;

    cout << "\t\t Selecteaza Optiunea ==> ";

    cin >> key;

    switch (key)

    {

    case 1:

      system("cls");

      cout << "Dati numarul de verificare" << endl;

      cin >> number;

      (Pell(number) ==

        1) ? cout << "Este numar Pell" << endl: cout << "Nu este Pell" <<
        endl;

      getch();

      break;

    case 2:

      cout << "Dati a al intervalului [a; b]" << endl;

      cin >> valueFrom;

      cout << "Dati b al intervalului [a; b]" << endl;

      cin >> valueTo;

      cout << "Numerele Pell din intervalul [" << valueFrom << ";" <<

        valueFrom << "] sunt:" << endl;

      for (int i = valueFrom; i < valueTo; i++)

      {

        if (Pell(i) == 1)

        {

          cout << i << " ";

        }

      }

      getch();

      break;

    case 3:

      j = 1;

      validCount = 0;

      cout << "Dati N a primelor Pell numere" << endl;

      cin >> count;

      cout << "Primele" << count << " numere sunt:" << endl;

      while (count != validCount)

      {

        if (Pell(j) == 1)

        {

          validCount++;

          cout << j << " ";

        }

        j++;

      }

      getch();

      break;

    case 4:

      cout << "Dati a al intervalului [a; b]" << endl;

      cin >> valueFrom;

      cout << "Dati b al intervalului [a; b]" << endl;

      cin >> valueTo;

      cout << "Numerele Pell din intervalul [" << valueFrom << ";" <<

        valueFrom << "] care satisfac conditia 2 sunt:" << endl;

      for (int i = valueFrom; i < valueTo; i++)

      {

        if (Pell(i) == 1 && isPrime(i))

        {

          cout << i << " ";

        }

      }

      getch();

      break;

    case 5:

      cout << "Cel mai mare numar Pell este:" << endl;

      for (int i = 999999; i > 0; i--) {

        if (Pell(i) == 1) {
          cout << i << endl;
          break;
        }
      }

      getch();
      break;
    }
  }
  while (key != 0);
}