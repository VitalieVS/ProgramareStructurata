#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Array {
  int arr[33];
  float media;
  int min;
  int max;
  int count;

  public:
    void swap(int * xp, int * yp) {
      int temp = * xp;
      * xp = * yp;
      * yp = temp;
    }
  void setArr(int _arr[], int _n) {
    for (int i = 0; i < _n; i++) {
      arr[i] = _arr[i];
    }
  }

  void MinMax(int _n) {
    min = arr[0];
    max = arr[0];
    for (int i = 0; i < _n; i++) {
      (arr[i] < min) ? min = arr[i]: 0;
      (arr[i] > max) ? max = arr[i]: 0;
    }
    cout << "Minim: " << min << endl;
    cout << "Maxim: " << max << endl;
  }

  float average(int _n) {
    float media = 0;
    for (int i = 0; i < _n; i++) {
      media += arr[i];
    }
    return media / _n;
  }

  void sort(int _n) {
    int i, j;
    bool swapped;
    for (i = 0; i < _n - 1; i++) {
      swapped = false;
      for (j = 0; j < _n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          swap( & arr[j], & arr[j + 1]);
          swapped = true;
        }
      }

      if (swapped == false)
        break;
    }
    for (i = 0; i < _n; i++) {
      cout << arr[i] << " ";
    }
  }

  void rotateRight(int _n) {
    int i, aux;
    if (_n == 0)
      cout << "Nu poate fi rotat" << endl;
    aux = arr[_n - 1];
    for (i = _n - 1; i > 0; i--)
      arr[i] = arr[i - 1];
    arr[0] = aux;
    for (i = 0; i < _n; i++) {
      cout << arr[i] << " ";
    }
  }

  void addData(int _n) {
    cout << "Dati numarul de date dorite de a adauga" << endl;
    cin >> count;
    for (int i = _n; i < _n + count; i++) {
      cout << "Dati elementul " << i + 1 << endl;
      cin >> arr[i];
    }
    for (int i = 0; i < _n + count; i++) {
      cout << arr[i] << " ";
    }
    count += _n;
  }

  void deleteElement(int _n, int k) {
    for (int i = k - 1; i < count; i++) {
      arr[i] = arr[i + 1];
    }
    count--;
    for (int i = 0; i < count; i++) {
      cout << arr[i] << " ";
    }
  }

  void onRoute() {
    int value;
    int onRouteCount = 0;
    cout << "Dati valoare de deteerminare a troleibuzelor pe ruta" << endl;
    cin >> value;

    for (int i = 0; i < count; i++) {
      (arr[i] >= value) ? onRouteCount++ : 0;
    }
    cout << "Numarul de troleibuze pe ruta este:" << onRouteCount << endl;
  }

};

int
main() {
  int n, el, key;

  cout << "Dati numarul de troleibuze" << endl;
  cin >> n;
  int array[n];

  for (int i = 0; i < n; i++) {
    cout << "Troleibuzul" << i << endl;
    cin >> array[i];
  }

  Array work;
  work.setArr(array, n);

  do {
    system("cls");
    cout << "1. De determinat in tabel valoarea minima si maxima." << endl;
    cout << "2. De determinat media aritmetica in tabel " << endl;
    cout << "3. De aranjat tabelul in ordine crescatoare" << endl;
    cout << "4. De efectuat rotirea la dreapta" << endl;
    cout << "5. De adaugat date in tabelul de numere" << endl;
    cout << "6. De sters date din tabelul de numere" << endl;
    cout << "7. De calculat numarul de troleibuze pe ruta" << endl;
    cout << "0. Exit" << endl;

    cout << "\t\t Selecteaza Optiunea ==> ";
    cin >> key;

    switch (key) {
    case 1:
      system("cls");
      work.MinMax(n);
      getch();
      break;
      
    case 2:
      system("cls");
      cout << "Media:" << work.average(n) << endl;
      getch();
      break;

    case 3:
      system("cls");
      cout << "Tabelul Sortat:" << endl;
      work.sort(n);
      getch();
      break;

    case 4:
      system("cls");
      cout << "Rotire la dreapta:" << endl;
      work.rotateRight(n);
      getch();
      break;

    case 5:
      system("cls");
      cout << "Adauga elemente" << endl;
      work.addData(n);
      getch();
      break;

    case 6:
      system("cls");
      cout << "Sterge date din tabelul de numere" << endl;
      cout << "Dati numarul elementului ce trebuie sters" << endl;
      cin >> el;
      work.deleteElement(n, el);
      getch();
      break;

    case 7:
      system("cls");
      cout << "Numarul de troleibuze pe ruta" << endl;
      work.onRoute();
      getch();
      break;

    }
  }
  while (key != 0);

}
