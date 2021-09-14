#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino
int fibonacci(int n){
  int fib = 1;
  int fibAnterior = 0;
  if (n == 0) {
    return fibAnterior;
  }
  if (n == 1) {
    return fib;
  }
  for(int i=2; i<=n; i++) {
    fib = fib + fibAnterior;  
    fibAnterior = fib - fibAnterior;
  }
  return fib;
}


int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}