#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "Utileria.h"

void GuardarMatrizEnArchivo();
Matriz** leerArchivo();

Matriz** MatrizTranspuesta(Matriz**, int, int);

Matriz** MultiplicacionMatrices(Matriz**, Matriz**, int, int, int, int);
Matriz** RestaMatrices(Matriz**, Matriz**, int, int, int, int);
Matriz** SumaMatrices(Matriz**, Matriz**, int, int, int, int);
Matriz** MultiplicacionEscalar(Matriz**, double, int, int);
#endif // OPERACIONES
