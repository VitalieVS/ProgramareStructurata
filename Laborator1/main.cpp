#include <iostream>
#include <cmath>

using namespace std;

int
main ()
{
  int n, max, min, onRoute, value, compare, count = 0, routeCount = 0;
  float average;
  max = 0;
  min = 25;

  cout << "Dati numarul de troleibuze" << endl;
  cin >> n;
  cout << "Dati valoarea de a compara" << endl;
  cin >> compare;
  cout << "Dati ora de determinare" << endl;
  cin >> onRoute;

  for (int i = 1; i <= n; i++)
    {
      cout << "Dati ora troleibuzului " << i << ":" << endl;
      cin >> value;

      (value > max) ? max = value : 0;
      (value < min) ? min = value : 0;
      average += value;

      (value > compare) ? count++ : 0;
      (value == onRoute) ? routeCount++ : 0;
    }
  average /= n;

  cout << "Valoarea maxima:" << max << endl;
  cout << "Valoarea minima:" << min << endl;
  cout << "Decalajul:" << max - min << endl;
  cout << "Media valorilor:" << roundf (average * 100) / 100 << endl;
  cout << "Numarul de valori mai mari decit valoarea indicata:" << count <<
    endl;
  cout << "Numarul de troleibuze aflate pe ruta:" << routeCount << endl;
  return 0;
}
