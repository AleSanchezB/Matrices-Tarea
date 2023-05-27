/*
Nombre: Tarea 7. La matriz recargada
Descripción: Este programa hace diferentes operaciones, como puede ser lo básico, suma y resta matrices
			 multipliacion, multiplicar matriz por escalar, invertir matriz y transponer matriz.
Fecha: 26/05/23
Autor: Braulio Alessandro Sanchez Bermudez
*/


#include <iostream>
#include <fstream>
#include "Operaciones.h"


void GuardarMatriz();
void SumaMatriz(int opcion);
void RestarMatrices(int opcion);
void MultiaMatrices(int opcion);
void MultiMatrizEsca(int opcion);
void TransponerMatriz(int opcion);
void Inversa(int opcion);
void GuardarResultado(Matriz**, int, int);
void IngresarManual(int[], int[], int);

int menu();
int menuLeerMatriz();

enum { GMATRIZ = 1, SUMA, RESTA, MM, ME, TRANS, INV, SALIR };


void IngresarManual(int n[], int m[], int indice)
{
	std::cout << "\nDame el numero filas de la matriz " << indice + 1 << ": " << std::endl;
	CapturaNumero(n[indice], "", MAXTAM);

	std::cout << "Dame el numero columnas de la matriz " << indice + 1 << ": " << std::endl;
	CapturaNumero(m[indice], "", MAXTAM);
}

int main()
{
	system("chcp 850");
	system("cls");

	bool salir = false;

	srand((unsigned int)(time(NULL)));
	int opcion;
	while (!salir)
	{
		try
		{
			opcion = menu();
			switch (opcion)
			{
			case GMATRIZ:
				GuardarMatriz();
				break;
			case SUMA:
				SumaMatriz(menuLeerMatriz());
				break;
			case RESTA:
				RestarMatrices(menuLeerMatriz());
				break;
			case MM:
				MultiaMatrices(menuLeerMatriz());
				break;
			case ME:
				MultiMatrizEsca(menuLeerMatriz());
				break;
			case TRANS:
				TransponerMatriz(menuLeerMatriz());
				break;
			case INV:
				Inversa(menuLeerMatriz());
				break;
			case SALIR:
				salir = true;
				break;
			default:
				break;
			}
			system("cls");
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "No hay suficiente memoria: " << e.what() << std::endl;
			system("pause");
			system("cls");
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			system("pause");
			system("cls");
		}
		catch (...)
		{
			std::cout << "Ha ocurrido un error, intente de nuevo" << std::endl;
			salir = true;
			system("pause");
			system("cls");
		}
	}
	return 0;
}

int menu()
{
	int opcion;
	std::cout << "------- Men\243 -------" << std::endl;
	std::cout << "1. Guardar una matriz en un archivo." << std::endl;
	std::cout << "2. Sumar dos matrices." << std::endl;
	std::cout << "3. Restar dos matrices." << std::endl;
	std::cout << "4. Multiplicar dos matrices." << std::endl;
	std::cout << "5. Multiplicar una matriz por un escalar." << std::endl;
	std::cout << "6. Transponer una matriz." << std::endl;
	std::cout << "7. Invertir una matriz." << std::endl;
	std::cout << "8. Salir del programa." << std::endl;
	CapturaNumero(opcion, "", 8);
	return opcion;
}

int menuLeerMatriz()
{
	std::cout << "\n1. Leer matriz desde archivo" << std::endl;
	std::cout << "2. Ingresar matriz manualmente" << std::endl;
	std::cout << "3. Generar aleatorio" << std::endl;
	int opcion;
	CapturaNumero(opcion, "", 3);
	return opcion;
}

void GuardarMatriz()
{
	GuardarMatrizEnArchivo();
}
void SumaMatriz(int opcion)
{
	int n[2], m[2];
	Matriz** matriz;
	Matriz** matriz2;

	if (opcion == 1) matriz = LeerArchivo(n, m, 0);
	else
	{
		IngresarManual(n, m, 0);
		matriz = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz, n[0], m[0]);
		else
			CapturarMatriz(matriz, n[0], m[0]);
	}

	opcion = menuLeerMatriz();
	if (opcion == 1) matriz2 = LeerArchivo(n, m, 1);
	else
	{
		IngresarManual(n, m, 1);
		if (n[0] != n[1] || m[0] != m[1])
		{
			Eliminar(matriz, n[0], m[0]);
			throw std::runtime_error("No se puede hacer esta operaci\242n");
		}

		matriz2 = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz2, n[0], m[0]);
		else
			CapturarMatriz(matriz2, n[0], m[0]);
	}

	Matriz** resultado = SumaMatrices(matriz, matriz2, n[0], m[0]);

	std::cout << "\nMatriz 1:" << std::endl;
	Imprimir(matriz, n[0], m[0]);
	std::cout << "\nMatriz 2:" << std::endl;
	Imprimir(matriz2, n[0], m[0]);

	std::cout << "\nResultado:" << std::endl;
	Imprimir(resultado, n[0], m[0]);

	GuardarResultado(resultado, n[0], m[0]);
	Eliminar(matriz, n[0], m[0]);
	Eliminar(matriz2, n[0], m[0]);
	Eliminar(resultado, n[0], m[0]);
}
void RestarMatrices(int opcion)
{
	int n[2], m[2];
	Matriz** matriz;
	Matriz** matriz2;

	if (opcion == 1) matriz = LeerArchivo(n, m, 0);
	else
	{
		IngresarManual(n, m, 0);
		matriz = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz, n[0], m[0]);
		else
			CapturarMatriz(matriz, n[0], m[0]);
	}

	opcion = menuLeerMatriz();
	if (opcion == 1) matriz2 = LeerArchivo(n, m, 1);
	else
	{

		IngresarManual(n, m, 1);
		if (n[0] != n[1] || m[0] != m[1])
		{
			Eliminar(matriz, n[0], m[0]);
			throw std::runtime_error("No se puede hacer esta operaci\242n");
		}

		matriz2 = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz2, n[0], m[0]);
		else
			CapturarMatriz(matriz2, n[0], m[0]);
	}

	Matriz** resultado = RestaMatrices(matriz, matriz2, n[0], m[0]);

	std::cout << "\nMatriz 1:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "\nMatriz 2:" << std::endl;
	Imprimir(matriz2, n[0], m[0]);

	std::cout << "\nResultado:" << std::endl;
	Imprimir(resultado, n[0], m[0]);

	GuardarResultado(resultado, n[0], m[0]);

	Eliminar(matriz, n[0], m[0]);
	Eliminar(matriz2, n[0], m[0]);
	Eliminar(resultado, n[0], m[0]);
}
void MultiaMatrices(int opcion)
{
	int n[2], m[2];
	Matriz** matriz;
	Matriz** matriz2;

	if (opcion == 1) matriz = LeerArchivo(n, m, 0);
	else
	{
		IngresarManual(n, m, 0);
		matriz = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz, n[0], m[0]);
		else
			CapturarMatriz(matriz, n[0], m[0]);
	}

	opcion = menuLeerMatriz();
	if (opcion == 1) matriz2 = LeerArchivo(n, m, 1);
	else
	{

		IngresarManual(n, m, 1);

		if (m[0] != n[1])
		{
			Eliminar(matriz, n[0], m[0]);
			throw std::runtime_error("No se puede hacer esta operaci\242n");
		}
		matriz2 = Crear(n[1], m[1]);
		if (opcion == 3) Rellenar(matriz2, n[1], m[1]);
		else
			CapturarMatriz(matriz2, n[1], m[1]);
	}


	std::cout << "\nMatriz 1:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "\nMatriz 2:" << std::endl;
	Imprimir(matriz2, n[1], m[1]);

	Matriz** resultado = MultiplicacionMatrices(matriz, matriz2, n[0], m[0], n[1], m[1]);

	std::cout << "\nResultado:" << std::endl;
	Imprimir(resultado, n[0], m[1]);

	GuardarResultado(resultado, n[0], m[1]);

	Eliminar(matriz, n[0], m[0]);
	Eliminar(matriz2, n[1], m[1]);
	Eliminar(resultado, n[0], m[1]);
}
void MultiMatrizEsca(int opcion)
{
	int n[1], m[1];
	float escalar = 1.f;
	Matriz** matriz;

	if (opcion == 1) matriz = LeerArchivo(n, m, 0);
	else
	{
		IngresarManual(n, m, 0);
		matriz = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz, n[0], m[0]);
		else
			CapturarMatriz(matriz, n[0], m[0]);
	}

	std::cout << "\nDame el escalar: " << std::endl;
	CapturaNumero(escalar, "", 600000.f, -600000.f);

	Matriz** resultado = MultiplicacionEscalar(matriz, escalar, n[0], m[0]);

	std::cout << "\nMatriz 1 por Escalar " << escalar << " :" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "\nResultado:" << std::endl;
	Imprimir(resultado, n[0], m[0]);

	GuardarResultado(resultado, n[0], m[0]);

	Eliminar(matriz, n[0], m[0]);
	Eliminar(resultado, n[0], m[0]);
}
void Inversa(int opcion)
{
	int n[1], m[1];
	Matriz** matriz;
	if (opcion == 1) matriz = LeerArchivo(n, m, 0);
	else
	{

		IngresarManual(n, m, 0);

		if (m[0] != n[0])
		{
			throw std::runtime_error("No se puede hacer esta operaci\242n");
		}
		matriz = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz, n[0], m[0]);
		else
			CapturarMatriz(matriz, n[0], m[0]);
	}

	Matriz** resultado = InvertirMatriz(matriz, n[0]);

	std::cout << "\nMatriz:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "\nResultado:" << std::endl;
	Imprimir(resultado, m[0], n[0]);

	GuardarResultado(resultado, m[0], n[0]);

	Eliminar(matriz, n[0], n[0]);
	Eliminar(resultado, n[0], n[0]);
}
void TransponerMatriz(int opcion)
{
	int n[1], m[1];
	Matriz** matriz;

	if (opcion == 1) matriz = LeerArchivo(n, m, 0);
	else
	{
		IngresarManual(n, m, 0);
		matriz = Crear(n[0], m[0]);
		if (opcion == 3) Rellenar(matriz, n[0], m[0]);
		else
			CapturarMatriz(matriz, n[0], m[0]);
	}

	Matriz** resultado = MatrizTranspuesta(matriz, n[0], m[0]);

	std::cout << "\nMatriz:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "\nResultado:" << std::endl;
	Imprimir(resultado, m[0], n[0]);

	GuardarResultado(resultado, m[0], n[0]);

	Eliminar(matriz, n[0], m[0]);
	Eliminar(resultado, m[0], n[0]);
}

void GuardarResultado(Matriz** matriz, int n, int m)
{
	int opcion;

	std::cout << "\n¿Desea guardar el resultado en un archivo?\n1.- Si\n2.- No" << std::endl;
	CapturaNumero(opcion, "", 2);

	if (opcion == 1)
		GuardarResultadoEnArchivo(matriz, n, m);
}