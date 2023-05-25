#include "Utileria.h"

void Rellenar(Matriz** matriz, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << "Elemento (" << i + 1 << ", " << j + 1 << "): ";
			CapturaNumero(matriz[i][j],"", 1000);
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

void CapturaNumero(int& num, const char mensaje[], int limiteSuperior)
{
	std::cout << mensaje;
	std::cin >> num;
	while (std::cin.fail() || num <= 0 || num != (int)num || num > limiteSuperior)
	{
		std::cout << "Error: valor no v\240lido ";
		if (std::cin.fail())
		{
			std::cout << ", se espera un n\243mero" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		else
		{
			if (num <= 0) std::cout << ", se espera un n\243mero positivo" << std::endl;
			if (num > limiteSuperior) std::cout << ", se espera un n\243mero menor a " << limiteSuperior << std::endl;
			else std::cout << ", se espera un n\243mero entero" << std::endl;
		}
		std::cout << "\nDame un n\243mero entero positivo: \n";
		std::cin >> num;
	}
}


void CapturaNumero(float& num, const char mensaje[], float limiteSuperior)
{
	std::cout << mensaje;
	std::cin >> num;
	while (std::cin.fail() || num <= 0 || num > limiteSuperior)
	{
		std::cout << "Error: valor no v\240lido ";
		if (std::cin.fail())
		{
			std::cout << ", se espera un n\243mero" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		else
		{
			if (num <= 0) std::cout << ", se espera un n\243mero positivo" << std::endl;
			else if (num > limiteSuperior) std::cout << ", se espera un n\243mero menor a " << limiteSuperior << std::endl;
			else std::cout << ", se espera un n\243mero entero" << std::endl;
		}
		std::cout << "\nDame un n\243mero entero positivo: \n";
		std::cin >> num;
	}
}
