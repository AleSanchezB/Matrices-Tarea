#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "Utileria.h"

void GuardarMatrizEnArchivo();
void GuardarResultadoEnArchivo(Matriz** matriz, int n, int m);
Matriz** LeerArchivo(int n[], int m[], int indice);

Matriz** MatrizTranspuesta(Matriz**, int, int);

Matriz** MultiplicacionMatrices(Matriz**, Matriz**, int, int, int, int);
Matriz** RestaMatrices(Matriz**, Matriz**, int, int);
Matriz** SumaMatrices(Matriz**, Matriz**, int, int);
Matriz** MultiplicacionEscalar(Matriz**, float, int, int);
Matriz** InvertirMatriz(Matriz**, int);
#endif // OPERACIONES
