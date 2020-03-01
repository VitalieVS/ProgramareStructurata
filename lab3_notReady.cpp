#include <stdio.h>
#include <iostream>

using namespace std;

class Array
{
  int arr[33];
  float media;
  int min;
  int max;

public:
  void swap (int *xp, int *yp)
  {
    int temp = *xp;
     *xp = *yp;
     *yp = temp;
  }
  void setArr (int _arr[], int _n)
  {
    for (int i = 0; i < _n; i++)
      {
	arr[i] = _arr[i];
      }
  }

  void MinMax (int _n)
  {
    min = arr[0];
    max = arr[0];
    for (int i = 0; i < _n; i++)
      {
	(arr[i] < min) ? min = arr[i] : 0;
	(arr[i] > max) ? max = arr[i] : 0;
      }
    cout << "Minim: " << min << endl;
    cout << "Maxim: " << max << endl;
  }

  float average (int _n)
  {
    float media = 0;
    for (int i = 0; i < _n; i++)
      {
	media += arr[i];
      }
    return media / _n;
  }

  void sort (int _n)
  {
    int i, j;
    bool swapped;
    for (i = 0; i < _n - 1; i++)
      {
	swapped = false;
	for (j = 0; j < _n - i - 1; j++)
	  {
	    if (arr[j] > arr[j + 1])
	      {
		swap (&arr[j], &arr[j + 1]);
		swapped = true;
	      }
	  }

	if (swapped == false)
	  break;
      }
    for (i = 0; i < _n; i++)
      {
	cout << arr[i] << " ";
      }
  }

};

int
main ()
{
  int n;
  cout << "dati n" << endl;
  cin >> n;
  int array[n];

  for (int i = 0; i < n; i++)
    {
      cin >> array[i];
    }
  Array work;
  work.setArr (array, n);
  work.MinMax (n);
  cout << "Media:" << work.average (n) << endl;
  work.sort (n);


  return 0;
}
