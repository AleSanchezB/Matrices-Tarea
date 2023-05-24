#include "Operaciones.h"

Matriz** leerArchivo()
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
	return matriz;
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
Matriz** SumaMatrices(Matriz** A, Matriz** B, int FilasA, int ColumnasA, int FilasB, int ColumnasB)
{
	if (FilasA != FilasB || ColumnasA != ColumnasB)
		throw std::exception("No se peuede hacer esta operacion");

	Matriz** resultado = Crear(FilasA, ColumnasA);

	for (int i = 0; i < FilasA; i++)
	{
		for (int j = 0; j < ColumnasA; j++)
		{
			resultado[i][j] = A[i][j] + B[i][j];
		}
	}

	return resultado;
}
Matriz** RestaMatrices(Matriz** A, Matriz** B, int FilasA, int ColumnasA, int FilasB, int ColumnasB)
{
	if (ColumnasA != FilasB) throw std::exception("No se peuede hacer esta operacion");

	Matriz** resultado = Crear(FilasA, ColumnasA);

	for (int i = 0; i < FilasA; i++)
	{
		for (int j = 0; j < ColumnasA; j++)
		{
			resultado[i][j] = A[i][j] - B[i][j];
		}
	}

	return resultado;
}
Matriz** MultiplicacionMatrices(Matriz** A, Matriz** B, int FilasA, int ColumnasA, int FilasB, int ColumnasB)
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
				resultado[i][j] += A[i][j] * B[i][j];

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