#include <iostream>

// Ejercicio 1
//int f(int x){
//    return x+1;
//}
//
//int main() {
//    std::cout << "El resultado es :" << f(10) << std::endl;
//    return 0;
//}

// Ejercicio 2
//int f(int x, int y){
//    return x + y;
//}
//
//int main() {
//    int x = 10;
//    int y = 4;
//    std::cout << "El resultado de sumar " << x << " + " << y << " es :" << f(x, y) << std::endl;
//    return 0;
//}


// Ejercicio 3
//int f(int x, int y){
//    if (x > y) {
//        return x + y;
//    } else {
//        return x * y;
//    }
//}
//
//int main() {
//    int x = 10;
//    int y = 11;
//    std::cout << "El resultado es: " << f(x, y) << std::endl;
//    return 0;
//}

// Ejercicio 4
//int esPrimo(int x){
//    for(int i = 2; i < x; i++) {
//        if (x % i == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    int a = 0;
//    std::cout << "Ingrese un numero: " << std::endl;
//    std::cin >> a;
//    bool primo = esPrimo(a);
//    if (primo) {
//        std::cout << "El numero es primo" << std::endl;
//    } else {
//        std::cout << "El numero no es primo" << std::endl;
//    }
//    return 0;
//}

// Ejercicio 5
// Escribir la función de Fibonacci que dado un entero n devuelve el n-ésimo número de Fibonacci. Los números
// de Fibonacci empiezan con F0 = 0 y F1 = 1. Fn = Fn−1 + Fn−2
//int Fibonacci(int x){
//    if (x == 0) {
//        return 0;
//    }
//    if (x == 1) {
//        return 1;
//    }
//    return Fibonacci(x-1) + Fibonacci(x-2) ;
//}
//
//int FibonacciFor(int x){
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
//}
//
//int FibonacciWhile(int x){
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
//}
//
//int main() {
//    int a = 0;
//    std::cout << "Ingrese un numero: " << std::endl;
//    std::cin >> a;
//    std::cout << "El n-esimo numero de la secuencia de Fibonacci es: " << Fibonacci(a) << std::endl;
//    return 0;
//}


// Ejercicio 6
// Escribir la función que dado n ∈ N devuelve la suma de todos los números impares menores que n.

// ESTE ME SUMA EL NUMERO TAMBIEN. NO SE ME OCURRE COMO HACER PARA NO SUMARLO.
//int sumaImparesMenores(int x){
//    if (x == 0) {
//        return 0;
//    }
//    if (x % 2 == 1) {
//        return x + sumaImparesMenores(x - 1);
//    }
//    return sumaImparesMenores(x - 1);
//}
//
//int sumaImparesMenoresFor(int x){
//    int sum = 0;
//    for(int i=1; i<x; i++) {
//        if (i % 2 == 1) {
//            sum += i;
//        }
//    }
//    return sum;
//}
//
//int sumaImparesMenoresWhile(int x){
//    int sum = 0;
//    int i = 1;
//    while(i<x) {
//        if (i % 2 == 1) {
//            sum += i;
//        }
//        i++;
//    }
//    return sum;
//}


// Ejercicio 7
// Escribir la función sumaDivisores que dado n ∈ N, devuelve la suma de todos sus divisores entre [1, n]. Para
//   la versión recursiva, es conveniente utilizar una función divisoresHasta.

//int sumaDivisores(n) {
//
//}

//int sumaDivisoresFor(int n) {
//    int sum = 0;
//    for(int i = 1; i <= n; i++) {
//        if (n % i == 0) {
//            sum = sum + i;
//        }
//    }
//    return sum;
//}
//
int sumaDivisoresWhile(int n) {
   int sum = 0;
   int i = 1;
   while (i <= n) {
       if (n % i == 0) {
           sum = sum + i;
       }
       i++;
   }
   return sum;
}


int main() {
   int a = 0;
   std::cout << "Ingrese un numero: " << std::endl;
   std::cin >> a;
   int b = sumaDivisoresWhile(a);
   std::cout << "La suma de los divisores hasta " << a << " es: " << b << std::endl;
   return 0;
}


// int main() {
//     std::cout << sizeof(char) << std::endl;
//     std::cout << sizeof(bool) << std::endl;
//     std::cout << sizeof(int) << std::endl;
//     std::cout << sizeof(uint16_t) << std::endl;
//     std::cout << sizeof(uint32_t) << std::endl;
//     std::cout << sizeof(uint64_t) << std::endl;
//     std::cout << sizeof(short) << std::endl;
// }
