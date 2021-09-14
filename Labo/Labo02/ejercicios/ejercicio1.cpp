#include <iostream>
#include <math.h>

// Ejercicio 1.
// Repetición controlada por un contador. Escriba un programa que cargue y analice los resultados de los exámenes
// de un curso de 10 estudiantes. Las clasificaciones son números enteros en el rango [0, 10] y deben ser cargadas
// por teclado una a una, utilizando la función cin, vista el laboratorio 01. Muestre por pantalla la suma total
// de las calificaciones de todos los estudiantes y el promedio de la clase para este examen (con decimales).

void ejercicio1() {
    int sum = 0;
    int nota;
    int i = 0;
    while (i < 10) {
        std::cout << "Ingrese una nota entre 0 y 10 (Faltan " << 10 - i << " notas):" << std::endl;
        std::cin >> nota;
        if (0 <= nota && nota <= 10) {
            sum += nota;
            i++;
        } else {
            std::cout << "Nota ingresada invalida. Debe ser un numero entero entre 0 y 10." << std::endl;
        }
    }
    float prom = (float)sum / 10;
    std::cout << "La suma de las notas es: " << sum << std::endl;
    std::cout << "El promedio de notas es: " << prom << std::endl;
}

// Ejercicio 2.
// Repetición controlada por un centinela. Modificar el programa anterior para que el
// número de estudiantes sea arbitrario. Por ejemplo: Ingrese la nota (-1 para terminar):

void ejercicio2() {
    int sum = 0;
    int nota = 0;
    int i = 0;
    while (nota != -1) {
        std::cout << "Ingrese una nota entre 0 y 10 (Ingrese -1 para terminar):" << std::endl;
        std::cin >> nota;
        if (0 <= nota && nota <= 10) {
            sum += nota;
            i++;
        } else {
            if (nota == -1 ) {
                std::cout << "Ingresado el valor -1. Fin de la entrada." << std::endl;
            } else {
                std::cout << "Nota ingresada invalida. Debe ser un numero entero entre 0 y 10." << std::endl;
            }
        }
    }
    float prom = (float)sum / (float)i;
    std::cout << "La suma de las notas es: " << sum << std::endl;
    std::cout << "El promedio de notas es: " << prom << std::endl;
}


// Ejercicio 3.
// Repetición controlada por un centinela y uso de contadores. Modificar el ejercicio anterior de
// manera que cuente la cantidad de alumnos que aprobaron y reprobaron el examen (nota mayor a 6). La cantidad
// de alumnos total no puede ser menor a 6 (frente a este caso, mostrar un error por pantalla). En el caso de
// más de dos tercios de los alumnos hayan aprobado, indicar por pantalla un mensaje que avise que se puede
// incrementar el número de plazas en el curso.

void ejercicio3() {
    int nota = 0;
    int alumnos = 0;
    int alumnosAprobados = 0;
    while (nota != -1) {
        std::cout << "Ingrese una nota entre 0 y 10 (Ingrese -1 para terminar):" << std::endl;
        std::cin >> nota;
        if (0 <= nota && nota <= 10) {
            if (6 <= nota) {
                alumnosAprobados++;
            }
            alumnos++;
        } else {
            if (nota == -1 ) {
                std::cout << "Ingresado el valor -1. Fin de la entrada." << std::endl;
            } else {
                std::cout << "Nota ingresada invalida. Debe ser un numero entero entre 0 y 10." << std::endl;
            }
        }
    }
    if (alumnos < 6 ) {
        std::cout << "Error: Cantidad de alumnos demasiado baja. La cantidad de alumnos debe ser mayor a 6." << std::endl;
    } else {
        std::cout << "La cantidad de alumnos aprobados es: " << alumnosAprobados << std::endl;
        std::cout << "La cantidad de alumnos desaprobados es: " << alumnos - alumnosAprobados << std::endl;
        if ( 2.0/3.0 <= (float)alumnosAprobados/(float)alumnos) {
            std::cout << "Se puede incrementar el numero de plazas en el curso." << std::endl;
        }
    }
}


//Ejercicio 4.
// Repetición controlada por un centinela y uso de acumuladores.
// Escriba un programa que reciba como entrada un entero de tipo binario, conteniendo sólo 0s y 1s, para imprimir
// luego por pantalla el equivalente decimal. Se supone que la entrada es válida respetando la premisa de los 0s y 1s.
// En forma parecida al sistema numérico decimal, donde el dı́gito más a la derecha tiene un valor posicional de 1 y el
// siguiente dı́gito a la izquierda tiene un valor posicional de 10, después 100, después 1000, etc., en el sistema
// numérico binario, el dı́gito más a la derecha tiene un valor posicional de 1, el siguiente dı́gito a la izquierda
// tiene un valor posicional de 2, luego 4, luego 8, etc. Ası́, el número decimal 432 se puede interpretar como
// 4 * 100 + 3 * 10 + 2 * 1.
// El equivalente decimal del número binario 1010 es 0 * 1 + 1 * 2 + 0 * 4 + 1 * 8, o 0 + 2 +0 + 8, o 10.
// Ayuda: use los operadores módulo y división para elegir los dı́gitos del número binario uno a la vez, de derecha
//a izquierda.

int potenciaDe2(int n) {
    int res = 1;
    for(int i = 0; i < n; i++) {
        res = res * 2;
    }
    return res;
}

void ejercicio4() {
    int binario;
    int i = 0;
    int decimal = 0;
    std::cout << "Ingrese un numero en binario: " << std::endl;
    std::cin >> binario;
    while (binario >= 1) {
        decimal += ((binario % 10) * potenciaDe2(i));
        binario = binario / 10;
        i++;
    }
    std::cout << "El numero en decimal es: " << decimal << std::endl;
}

// Ejercicio 5.
// Pasaje por valor y referencia.
// Escriba y utilice en un programa una función que reciba el radio de un cı́rculo
// (como un valor float), calcule e imprima el diámetro, la circunferencia y el área.
// Use el valor 3.14159 para π. Estos valores deben ser mostrados en pantalla desde el programa principal (main.cpp).

float calculoCirculo(float radio, float &diametro, float &circunferencia) {
    float pi = 3.14159;
    diametro = 2 * radio;
    circunferencia = 2 * pi * radio;
    return pi * radio * radio;
}

void ejercicio5() {
    float radio, diametro, circunferencia, area;
    std::cout << "Ingrese el radio..." << std::endl;
    std::cin >> radio;
    area = calculoCirculo(radio, diametro, circunferencia);
    std::cout << "El radio ingresado fue: " << radio << std::endl;
    std::cout << "El diametro del circulo es: " << diametro << std::endl;
    std::cout << "La circunferencia del circulo es: " << circunferencia << std::endl;
    std::cout << "El area del circulo es: " << area << std::endl;
}

//Ejercicio 6.
// Pasaje por valor y referencia.
// Escriba un programa completo en C++ con las dos funciones alternativas que se especifican a continuación,
// de las cuales cada una simplemente triplica la variable cuenta definida en main. Después compare y contraste
// ambos métodos. Estas dos funciones son:
//    1. la función triplicarPorValor, que pasa una copia de cuenta por valor, triplica la copia y devuelve el nuevo valor,
//    2. la función triplicarPorReferencia, que pasa cuenta por referencia a través de un parámetro por referencia y triplica el
//        valor original de cuenta a través de su alias (es decir, el parámetro por referencia).

// Ejercicio 7.
// Implementar la función swap: void swap(int& a, int& b), que cumpla con la siguiente especificación:
//
// proc swap (inout a:Z, inout b:Z) {
//      Pre {a = a0 ∧ b = b0 }
//      Post {a = b0 ∧ b = a0 }
// }

void swap(int &a, int &b) {
    a = b + a;
    b = a - b;
    a = a - b;
}

void ejercicio7() {
    int a,b;
    std::cout << "Ingrese el valor a:" << std::endl;
    std::cin >> a;
    std::cout << "Ingrese el valor b:" << std::endl;
    std::cin >> b;
    swap(a, b);
    std::cout << "a: " << a << ", b: " << b << std::endl;
}

// Ejercicio 8.
// La conjetura de Collatz dice que dado un número natural n y el proceso que describimos a continuación, sin
// importar cuál sea el número original, provocará que la serie siempre termine en 1. El proceso:
// Si n es par lo dividimos por 2
// Si n es impar lo multiplicamos por 3 y le sumamos 1 al resultado
// 1
// En este ejercicio, supondremos que la conjetura es cierta y se pide implementar una función que devuelva la cantidad de
//        pasos que se realizan desde el número original hasta llegar a 1 y que muestre en la salida estándar la sucesión de números
//        por la que pasa. Ejemplo: si calculamos collatz de 11, la cantidad de pasos es 15 y la sucesión es
//        11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
// Resolver este ejercicio utilizando el siguiente encabezado para la función.
// void collatz(int n, int& cantPasos)
// Implementar en versiones iterativa y recursiva.

bool esPar(int n) {
    return n % 2 == 0;
}

void collatz(int n, int &cantPasos) {
    std::cout << n << " " ;
    cantPasos++;
    while (1 < n) {
        if (esPar(n)) {
            n = n/2;
        } else {
            n = n * 3 + 1;
        }
        cantPasos++;
        std::cout << n << " ";
    }
}

void collatzRec(int n, int &cantPasos) {
    std::cout << n << " ";
    cantPasos++;
    if (n == 1) {
        return;
    }
    if (esPar(n)) {
        collatzRec(n/2, cantPasos);
    } else {
        collatzRec(n*3 + 1, cantPasos);
    }
}

void ejercicio8() {
    int n = 0;
    int cantPasos = 0;
    std::cout << "Ingrese un numero entero mayor que 1: " << std::endl;
    std::cin >> n;
    collatzRec(n, cantPasos);
    std::cout << std::endl;
    std::cout << "La cantidad de pasos necesarias fue: " << cantPasos << std::endl;
}

// Ejercicio 9.
// Implementar la función division que cumpla con la siguiente especificación:
//
// proc division (in dividendo Z, in divisor Z, out cociente:Z, out resto:Z) {
//      Pre {dividendo ≥ 0 ∧ divisor > 0}
//      Post {dividendo = divisor ∗ cociente + resto ∧ 0 ≤ resto < divisor}
// }
// Resolver este ejercicio en versiones iterativa y recursiva.

void division(int dividendo, int divisor, int& cociente, int& resto){
    resto = dividendo;
    cociente = 0;
    while (resto >= divisor) {
        resto = resto - divisor;
        cociente = cociente + 1; 
    }
}

void ejercicio9() {
    int dividendo, divisor, cociente, resto;
    std::cin >> dividendo;
    std::cin >> divisor;
    division(dividendo, divisor, cociente, resto);
    std::cout << dividendo << " " << divisor << " " << cociente << " " << resto << std::endl;
}

int main() {
    ejercicio8();
    return 0;
}
