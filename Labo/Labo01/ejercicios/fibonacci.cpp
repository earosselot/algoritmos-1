#include <iostream>

// Ejercicio 5
// Escribir la función de Fibonacci que dado un entero n devuelve el n-ésimo número de Fibonacci. Los números
// de Fibonacci empiezan con F0 = 0 y F1 = 1. Fn = Fn−1 + Fn−2

// int Fibonacci(int x){
//    if (x == 0) {
//        return 0;
//    }
//    if (x == 1) {
//        return 1;
//    }
//    return Fibonacci(x-1) + Fibonacci(x-2) ;
// }

// int FibonacciFor(int x){
//    int fibAnterior = 1;
//    int fibAnterior2 = 0;
//    int fib;
//    if (x==0) {
//        return fibAnterior2;
//    }
//    if (x == 1) {
//        return fibAnterior;
//    }
//    for(int i=2; i<=x; i++) {
//        fib = fibAnterior + fibAnterior2;
//        fibAnterior2 = fibAnterior;
//        fibAnterior = fib;
//    }
//    return fib;
// }

int FibonacciFor2(int x){
  int fib = 1;
  int fibAnterior = 0;
  if (x==0) {
    return fibAnterior;
  }
  if (x == 1) {
    return fib;
  }
  for(int i=2; i<=x; i++) {
    fib = fib + fibAnterior;  
    fibAnterior = fib - fibAnterior;
  }
  return fib;
}

// int FibonacciWhile(int x){
//    int fibAnterior = 1;
//    int fibAnterior2 = 0;
//    int fib;
//    if (x == 0) {
//        return fibAnterior2;
//    }
//    if (x == 1) {
//        return fibAnterior;
//    }
//    int i = 2;
//    while(i <= x) {
//        fib = fibAnterior + fibAnterior2;
//        fibAnterior2 = fibAnterior;
//        fibAnterior = fib;
//        i = i + 1;
//    }
//    return fib;
// }

int main() {
   int a = 0;
   std::cout << "Ingrese un numero: " << std::endl;
   std::cin >> a;
   std::cout << "El n-esimo numero de la secuencia de Fibonacci es: " << FibonacciFor2(a) << std::endl;
   return 0;
}