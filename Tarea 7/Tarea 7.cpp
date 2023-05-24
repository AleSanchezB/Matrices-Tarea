#include <iostream>
#include <fstream>

typedef double Matriz;

void TransponerMatriz();
void Eliminar(Matriz**, int n, int m);
void Imprimir(Matriz** matriz, int n, int m);
void Rellenar(Matriz** matriz, int n, int m);
void GuardarMatrizEnArchivo();

bool leerArchivo();

Matriz** MatrizTranspuesta(Matriz** matriz, int n, int m);
Matriz** Crear(int n, int m);
Matriz** MultiplicacionMatrices(Matriz** matriz1, Matriz** matriz2, int FilasA, int ColumnasA, int FilasB, int ColumnasB);
Matriz** RestaMatrices(Matriz** matriz1, Matriz** matriz2, int n, int m);
Matriz** SumaMatrices(Matriz** matriz1, Matriz** matriz2, int n, int m);
Matriz** MultiplicacionEscalar(Matriz** matriz1, double escalar, int n, int m);

bool leerArchivo()
{
	char nombreArchivo[100];
	Matriz** matriz;
	int n, m;
	std::cout << "Ingrese el nombre del archivo a leer: " << std::endl;
	std::cin.getline(nombreArchivo, 50);

	std::ifstream archivo(nombreArchivo);

	if (!archivo.is_open())
	{
		//std::cout << "No se pudo abrir el archivo." << std::endl;
		throw std::exception("No se pudo abrir el archivo");
	}
	else
	{
		archivo >> n >> m;
		matriz = Crear(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				archivo >> matriz[i][j];
			}
		}
	}
	archivo.close();
}
void GuardarMatrizEnArchivo()
{
	int n, m;
	char titulo;

	std::cout << "Dame el numero de filas de la matriz: " << std::endl;
	std::cin >> n;

	std::cout << "Dame el numero de columnas de la matriz: " << std::endl;
	std::cin >> m;

	std::cout << "Dame el nombre del archivo donde deseas guardalo: " << std::endl;
	std::cin >> titulo;

	std::ofstream archivo(titulo + ".txt");

	if (!archivo.is_open())
	{
		std::cout << "No se pudo abrir el archivo." << std::endl;
		throw ("No se pudo abrir el archivo");
	}
	int x;
	archivo << n << " " << m << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << "Ingrese el valor de (" << i << ", " << j << std::endl;
			std::cin >> x;
			archivo << x << " ";
		}
		archivo << "\n";
	}
	archivo.close();
	std::cout << "Archivo guardado correctamente." << std::endl;
}
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
int main()
{
	bool salir = false;

	while (!salir)
	{
		try
		{
			srand(time(NULL));
			leerArchivo();
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
Matriz** MatrizTranspuesta(Matriz** matriz, int n, int m)
{
	Matriz** transpuesta = Crear(m, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			transpuesta[j][i] = matriz[i][j];
		}
	}
	return transpuesta;
}
Matriz** SumaMatrices(Matriz** matriz1, Matriz** matriz2, int n, int m)
{
	Matriz** resultado = Crear(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			resultado[i][j] = matriz1[i][j] + matriz2[i][j];
		}
	}

	return resultado;
}
Matriz** RestaMatrices(Matriz** matriz1, Matriz** matriz2, int n, int m)
{
	Matriz** resultado = Crear(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			resultado[i][j] = matriz1[i][j] - matriz2[i][j];
		}
	}

	return resultado;
}
Matriz** MultiplicacionMatrices(Matriz** matriz1, Matriz** matriz2, int FilasA, int ColumnasA, int FilasB, int ColumnasB)
{
	if (ColumnasA != FilasB) throw std::exception("No se peuede hacer esta operacion");

	Matriz** resultado = Crear(FilasA, ColumnasB);
	double suma = 0;

	for (int i = 0; i < FilasA; i++)
	{
		for (int j = 0; j < ColumnasB; j++)
		{
			for (int k = 0; k < ColumnasA; k++)
			{
				resultado[i][j] += matriz1[i][j] * matriz2[i][j];

			}
		}
	}
	return resultado;
}
Matriz** MultiplicacionEscalar(Matriz** matriz1, double escalar, int n, int m)
{
	Matriz** resultado = Crear(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			resultado[i][j] += matriz1[i][j] * escalar;
		}
	}
	return resultado;
}