#ifndef UTILERIA_H
#define UTILERIA_H
#define MAXTAM 50
#include <iostream>
#include <fstream>
#include <limits>

typedef float Matriz;

void Eliminar(Matriz**, int n, int m);
void Imprimir(Matriz** matriz, int n, int m);
void CapturarMatriz(Matriz** matriz, int n, int m);
void Rellenar(Matriz** matriz, int n, int m);
void CapturaNumero(float& num, const char mensaje[], float limiteSuperior);
void CapturaNumero(int& num, const char mensaje[], int limiteSuperior);
Matriz** Crear(int, int);

#endif // !UTILERIA_H

