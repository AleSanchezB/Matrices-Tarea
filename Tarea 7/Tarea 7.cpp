#include <iostream>
#include <fstream>

#include "Operaciones.h"


void GuardarMatriz();
void SumaMatriz(int opcion);
void RestarMatrices(int opcion);
void MultiaMatrices(int opcion);
void MultiMatrizEsca(int opcion);
void TransponerMatriz(int opcion);
void Inversa();
void GuardarResultado(Matriz**, int, int);

void IngresarManual(int[], int[], int);

int menu();
int menuLeerMatriz();

enum { GMATRIZ = 1, SUMA, RESTA, MM, ME, TRANS, INV, SALIR };


void IngresarManual(int n[], int m[], int indice)
{
	std::cout << "Dame el numero filas de la matriz " << indice + 1 << ": " << std::endl;
	CapturaNumero(n[indice], "", 20);

	std::cout << "Dame el numero columnas de la matriz " << indice + 1 << ": " << std::endl;
	CapturaNumero(m[indice], "", 20);
}

int main()
{
	bool salir = false;

	srand(time(NULL));
	int opcion, opcion2;
	while (!salir)
	{
		try
		{
			opcion = menu();
			opcion2 = menuLeerMatriz();
			switch (opcion)
			{
			case GMATRIZ:
				GuardarMatriz();
				break;
			case SUMA:
				SumaMatriz(opcion2);
				break;
			case RESTA:
				RestarMatrices(opcion2);
				break;
			case MM:
				MultiaMatrices(opcion2);
				break;
			case ME:
				MultiMatrizEsca(opcion2);
				break;
			case TRANS:
				TransponerMatriz(opcion2);
				break;
			case INV:
				Inversa();
				break;
			case SALIR:
				salir = true;
				break;
			default:
				break;
			}
			system("cls");
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			system("pause");
			system("cls");
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "No hay suficiente memoria: " << e.what() << std::endl;
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
	std::cout << "------- Menú -------" << std::endl;
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
	int opcion;
	CapturaNumero(opcion, "", 2);
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
		Rellenar(matriz, n[0], m[0]);
	}

	opcion = menuLeerMatriz();
	if (opcion == 1) matriz2 = LeerArchivo(n, m, 1);
	else
	{
		IngresarManual(n, m, 1);
		
		if (n[0] != n[1] || m[0] != m[1])
		{
			Eliminar(matriz, n[0], m[0]);
			throw std::exception("No se puede hacer esta operacion");
		}
		matriz2 = Crear(n[0], m[0]);
		Rellenar(matriz2, n[0], m[0]);
	}

	Matriz** resultado = SumaMatrices(matriz, matriz2, n[0], m[0]);

	std::cout << "matriz 1:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "matriz 2:" << std::endl;
	Imprimir(matriz2, n[0], m[0]);

	std::cout << "resultado:" << std::endl;
	Imprimir(resultado, n[0], m[0]);

	GuardarResultado(resultado,n[0],m[0]);
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
		Rellenar(matriz, n[0], m[0]);
	}

	opcion = menuLeerMatriz();
	if (opcion == 1) matriz2 = LeerArchivo(n, m, 1);
	else
	{

		IngresarManual(n, m, 1);

		if (n[0] != n[1] || m[0] != m[1])
		{
			Eliminar(matriz, n[0], m[0]);
			throw std::exception("No se peuede hacer esta operacion");
		}
		matriz2 = Crear(n[0], m[0]);
		Rellenar(matriz2, n[0], m[0]);
	}

	Matriz** resultado = RestaMatrices(matriz, matriz2, n[0], m[0]);

	std::cout << "matriz 1:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "matriz 2:" << std::endl;
	Imprimir(matriz2, n[0], m[0]);

	std::cout << "resultado:" << std::endl;
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
		Rellenar(matriz, n[0], m[0]);
	}

	opcion = menuLeerMatriz();
	if (opcion == 1) matriz2 = LeerArchivo(n, m, 1);
	else
	{

		IngresarManual(n, m, 1);

		if (m[0] != n[1])
		{
			Eliminar(matriz, n[0], m[0]);
			throw std::exception("No se peuede hacer esta operacion");
		}
		matriz2 = Crear(n[1], m[1]);
		Rellenar(matriz2, n[1], m[1]);
	}

	Matriz** resultado = MultiplicacionMatrices(matriz, matriz2, n[0], m[0], n[1], m[1]);

	std::cout << "matriz 1:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "matriz 2:" << std::endl;
	Imprimir(matriz2, n[1], m[1]);

	std::cout << "resultado:" << std::endl;
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
		Rellenar(matriz, n[0], m[0]);
	}
	std::cout << "Dame el escalar: " << std::endl;
	CapturaNumero(escalar, "", 3.4e38);

	Matriz** resultado = MultiplicacionEscalar(matriz,escalar ,n[0], m[0]);

	std::cout << "matriz 1:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "resultado:" << std::endl;
	Imprimir(resultado, n[0], m[0]);

	GuardarResultado(resultado, n[0], m[0]);

	Eliminar(matriz, n[0], m[0]);
	Eliminar(resultado, n[0], m[0]);
}
void Inversa()
{

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
		Rellenar(matriz, n[0], m[0]);
	}

	Matriz** resultado = MatrizTranspuesta(matriz, n[0], m[0]);

	std::cout << "matriz:" << std::endl;
	Imprimir(matriz, n[0], m[0]);

	std::cout << "resultado:" << std::endl;
	Imprimir(resultado, m[0], n[0]);

	GuardarResultado(resultado, m[0], n[0]);

	Eliminar(matriz, n[0], m[0]);
	Eliminar(resultado, m[0], n[0]);
}

void GuardarResultado(Matriz** matriz, int n, int m)
{
	int opcion;

	std::cout << "\nDesea guardar el resultado en un archivo?\n1.- Si\n2.-No" << std::endl;
	CapturaNumero(opcion, "", 2);

	if (opcion == 1)
		GuardarResultadoEnArchivo(matriz,n,m);
}