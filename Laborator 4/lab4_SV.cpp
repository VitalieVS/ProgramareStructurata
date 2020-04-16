#include <iostream>
#define NMAX 100
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Array {
    public:
    void createMatrix(int matrix[NMAX][NMAX], int row, int col) {
       for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++){
               cout << "Dati elementul [ " << i << ", " << j << " ]" << endl;
               cin >> matrix[i][j];
           }
           cout << endl;
       }
    }
    void minMax(int matrix[NMAX][NMAX], int row, int col) {
        int max, maxI, maxJ, min, minI, minJ;
        max = matrix[0][0];
        min = matrix[0][0];
         for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++){
               if (max < matrix[i][j]) {
                   max = matrix[i][j];
                   maxI = i;
                   maxJ = j;
               }
                if (min > matrix[i][j]) {
                   min = matrix[i][j];
                   minI = i;
                   minJ = j;
               }
           }
         }
         cout << "Valoarea maxima:" << max << " i = " << maxI << " j =" << maxJ << endl;
         cout << "Valoarea minima:" << min << " i = " << minI << " j =" << minJ << endl;
    }
    
    void interschimbare(int matrix[NMAX][NMAX], int row, int col, int first, int second) {
    int temp;
        for (int i = 0; i < row; i++) {
            temp = matrix[i][first-1];
            matrix[i][first-1] = matrix[i][second-1];
            matrix[i][second-1] = temp;
        }
    }
    
       void showArr(int matrix[NMAX][NMAX], int row, int col) {
       for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++){
               cout << matrix[i][j] << " ";
           }
           cout << endl;
       }
    }
    
    void AddColumn(int matrix[NMAX][NMAX], int row, int col, int ora) {
    col++;
    int nr;
     for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++){
               if (j < col - 1 ) {
                   if (matrix[i][j] == ora) {
                       nr++;
                   }
               } else {
                       matrix[i][j] = nr;
                       nr = 0;
                   }
               }
           }
    }
    
    void matrixSort(int matrix[NMAX][NMAX], int &row, int &col){
	int temp, k;
	bool change;
	k = 0;
	do{
		k ++;
		change = 0;
		for( int i  = 0; i < row - k; i++){
			if(matrix[i][col - 1] > matrix[i + 1][col - 1]){
				for(int  j = 0; j < col; j ++){
					temp = matrix[i][j];
					matrix[i][j] = matrix[i+1][j];
					matrix[i+1][j] = temp;
				}
				change = 1;
			}
		}
	}while(change);
}

	void generateMatrix(int row, int col) {
		int generated[row][col];
			 for (int i = 0; i < row; i++) {
	           for (int j = 0; j < col; j++){
	           		if (i == 0 || j == 0 ) {
	           			generated[i][j] = 1;
			 }  else
			 {
			 	generated[i][j] = (i+1) * generated[i][j-1];
			 }
	           }
	           }
		 for (int i = 0; i < row; i++) {
	           for (int j = 0; j < col; j++){
	               cout << generated[i][j] << " ";
	           }
	           cout << endl;
	       }
	   }
	
};


int main() {
   int key;
   int row, col;
   int ore;
   int l1,l2;
   int matrix[NMAX][NMAX];
   cout << "Dati nr de linii" << endl;
   cin >> row;
   cout << "Dati nr de coloane" << endl;
   cin >> col;
   Array work;
   work.createMatrix(matrix, row, col);
  do {
    system("cls");
    cout << "1. De determinat in matrice valoarea minima si maxima." << endl;
    cout << "2. De interschimbat 2 coloane " << endl;
    cout << "3. De adaugat o coloana" << endl;
    cout << "4. De aranjat dupa coloana" << endl;
    cout << "5. De generat matricea" << endl;
    cout << "0. Exit" << endl;

    cout << "\t\t Selecteaza Optiunea ==> ";
    cin >> key;

    switch (key) {
    case 1:
      system("cls");
       work.minMax(matrix, row, col);
      getch();
      break;
      
    case 2:
      system("cls");
      work.showArr(matrix, row, col);
        cout << "Dati linia 1" << endl;
        cin >> l1;
        cout << "Dati linia 2" << endl;
        cin >> l2;
        work.interschimbare(matrix, row,col, l1,l2);
        work.showArr(matrix, row,col);
      
      getch();
      break;

    case 3:
      system("cls");
         work.showArr(matrix, row, col);
         cout << "Dati ora" << endl;
         cin >> ore;
         work.AddColumn(matrix, row, col, ore);
         work.showArr(matrix,row,col+1);
      getch();
      break;

    case 4:
      system("cls");
        work.showArr(matrix, row, col);
        work.matrixSort(matrix, row, col);
        cout << "------------------" << endl;
        work.showArr(matrix, row, col);
      getch();
      break;

    case 5:
      system("cls");
     	work.generateMatrix(row, col);
      getch();
      break;

    }
  }
  while (key != 0);
    return 0;
};
