#include "Utileria.h"

void Rellenar(Matriz** matriz, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matriz[i][j] = rand() % 30;
		}
	}
}
void Imprimir(Matriz** matriz, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << matriz[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void Eliminar(Matriz** matriz, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matriz[i];
	}
	delete[] matriz;
	matriz = NULL;
}
Matriz** Crear(int n, int m)
{
	Matriz** matriz = new Matriz * [n];
	for (int i = 0; i < n; i++)
	{
		matriz[i] = new Matriz[m];
	}
	return matriz;
}