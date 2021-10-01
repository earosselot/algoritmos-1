#include <iostream>

using namespace std;

int maximo(int x, int y)
{
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  if (x > y)
    return x;
  else
    return y;
}

int minimo(int x, int y)
{
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  if (x < y)
    return x;
  else
    return y;
}

int maximoComunDivisor(int x, int y)
{
  int mayor = maximo(x, y);
  int menor = minimo(x, y);
  int resto = 1;
  while (resto != 0 && menor != 0)
  {
    resto = mayor % menor;
    mayor = menor;
    menor = resto;
  }
  if (resto == 0)
    return mayor;
  else
    return 1;
}

int main()
{
  /* No hace falta modificar el main */
  int a, b;
  //Leo a
  cin >> a >> b;

  int res = maximoComunDivisor(a, b);

  //Devuelvo el maximo comun divisor
  cout << res;
  return 0;
}
