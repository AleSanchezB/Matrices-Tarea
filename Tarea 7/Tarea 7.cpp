#include <iostream>
#include <fstream>

#include "Operaciones.h"


void GuardarMatriz();
void SumaMatriz();
void RestaMatrices();
void MultiaMatrices();
void MultiMatrizEsca();
void TransponerMatriz();
void Inversa();

void TransponerMatriz();
int menu();
enum {GMATRIZ, SUMA, RESTA, MM, ME, TRANS,INV, SALIR};
int main()
{
	bool salir = false;

	srand(time(NULL));
	int opcion;
	while (!salir)
	{
		try
		{
			opcion = menu();
			switch (opcion)
			{
			case GMATRIZ:
				break;
			case SUMA:
				break;
			case RESTA:
				break;
			case MM:
				break;
			case ME:
				break;
			case TRANS:
				TransponerMatriz();
				break;
			case INV:
				break;
			case SALIR:
				salir = true;
				break;
			default:
				break;
			}
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
		}
	}
}

int menu()
{

}
void GuardarMatriz()
{
	GuardarMatrizEnArchivo();
}
void SumaMatriz()
{
	SumaMatrices();
}
void RestaMatrices()
{

}
void MultiaMatrices()
{

}
void MultiMatrizEsca()
{

}
void Inversa()
{

}
void TransponerMatriz()
{
	int n = 2, m = 3;
	Matriz** matriz = Crear(n, m);
	Rellenar(matriz, n, m);
	Matriz** matrizR = MatrizTranspuesta(matriz, n, m);
	Imprimir(matriz, n, m);
	Imprimir(matrizR, m, n);

	Eliminar(matriz, n, m);
	Eliminar(matrizR, m, n);
}



