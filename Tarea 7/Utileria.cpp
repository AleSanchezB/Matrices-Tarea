#include "Utileria.h"

void CapturarMatriz(Matriz** matriz, int n, int m)
{
	std::cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << "Elemento (" << i + 1 << ", " << j + 1 << "): ";
			CapturaNumero(matriz[i][j], "", 100000, -100000);
		}
	}
}
void Rellenar(Matriz** matriz, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matriz[i][j] = (Matriz)(rand() % 100);
		}
	}
}
void Imprimir(Matriz** matriz, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << matriz[i][j] << "          ";
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

void CapturaNumero(int& num, const char mensaje[], int limiteSuperior, int limiteInferior /*= 0*/)
{
	std::cout << mensaje;
	std::cin >> num;
	while (std::cin.fail() || num <= limiteInferior || num != (int)num || num > limiteSuperior)
	{
		std::cout << "Error: valor no v\240lido";
		if (std::cin.fail())
		{
			std::cout << ", se espera un n\243mero" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		else
		{
			if (num <= limiteInferior) std::cout << ", se espera un n\243mero positivo o mayor a " << limiteInferior << std::endl;
			if (num > limiteSuperior) std::cout << ", se espera un n\243mero menor a " << limiteSuperior << std::endl;
			else std::cout << ", se espera un n\243mero entero" << std::endl;
		}
		std::cout << "\nDame un n\243mero entero positivo: \n";
		std::cin >> num;
	}
}


void CapturaNumero(float& num, const char mensaje[], float limiteSuperior, float limiteInferior /*= 0*/)
{
	std::cout << mensaje;
	std::cin >> num;
	while (std::cin.fail() || num <= limiteInferior || num > limiteSuperior)
	{
		std::cout << "Error: valor no v\240lido";
		if (std::cin.fail())
		{
			std::cout << ", se espera un n\243mero" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		else
		{
			if (num <= limiteInferior) std::cout << ", se espera un n\243mero positivo o mayor a " << limiteInferior << std::endl;
			else if (num > limiteSuperior) std::cout << ", se espera un n\243mero menor a " << limiteSuperior << std::endl;
			else std::cout << ", se espera un n\243mero entero" << std::endl;
		}
		std::cout << "\nDame un n\243mero entero positivo: \n";
		std::cin >> num;
	}
}