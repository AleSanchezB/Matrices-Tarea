#ifndef UTILERIA_H
#define UTILERIA_H
#include <iostream>
#include <fstream>
typedef double Matriz;

void Eliminar(Matriz**, int n, int m);
void Imprimir(Matriz** matriz, int n, int m);
void Rellenar(Matriz** matriz, int n, int m);
Matriz** Crear(int, int);

#endif // !UTILERIA_H

