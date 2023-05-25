#include "Operaciones.h"

Matriz** LeerArchivo(int n[], int m[], int indice)
{
	char titulo[100];
	Matriz** matriz;
	char extension[] = ".txt";

	std::cout << "Ingrese el nombre del archivo a leer: " << std::endl;
	std::cin >> titulo;
	
	int i = 0;
	while (titulo[i] != '\0')
	{
		++i;
	}

	int j = 0;
	while (extension[j] != '\0')
	{
		titulo[i] = extension[j];
		++i;
		++j;
	}
	titulo[i] = '\0';

	std::ifstream archivo(titulo);

	if (!archivo)
	{
		throw std::exception("No se pudo abrir el archivo");
	}

	archivo >> n[indice] >> m[indice];
	matriz = Crear(n[indice], m[indice]);
	for (int i = 0; i < n[indice]; i++)
	{
		for (int j = 0; j < m[indice]; j++)
		{
			archivo >> matriz[i][j];
		}
	}

	archivo.close();
	return matriz;
}
void GuardarMatrizEnArchivo()
{
	int n, m;
	char titulo[100];
	char extension[] = ".txt";

	std::cout << "Dame el nombre del archivo donde deseas guardalo: " << std::endl;
	std::cin >> titulo;

	int i = 0;
	while (titulo[i] != '\0')
	{
		++i;
	}

	int j = 0;
	while (extension[j] != '\0')
	{
		titulo[i] = extension[j];
		++i;
		++j;
	}

	titulo[i] = '\0';

	std::cout << "Dame el numero de filas de la matriz: " << std::endl;
	std::cin >> n;

	std::cout << "Dame el numero de columnas de la matriz: " << std::endl;
	std::cin >> m;


	std::ofstream archivo(titulo);

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

void GuardarResultadoEnArchivo(Matriz** matriz, int n, int m)
{
	char titulo[100];
	char extension[] = ".txt";

	std::cout << "Dame el nombre del archivo donde deseas guardalo: " << std::endl;
	std::cin >> titulo;

	int i = 0;
	while (titulo[i] != '\0') 
	{
		++i;
	}

	int j = 0;
	while (extension[j] != '\0') 
	{
		titulo[i] = extension[j];
		++i;
		++j;
	}
	titulo[i] = '\0';

	std::ofstream archivo(titulo);

	archivo << n << " " << m << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			archivo << matriz[i][j] << " ";
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
Matriz** SumaMatrices(Matriz** A, Matriz** B, int FilasA, int ColumnasA)
{
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
Matriz** RestaMatrices(Matriz** A, Matriz** B, int FilasA, int ColumnasA)
{
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
Matriz** MultiplicacionEscalar(Matriz** matriz1, float escalar, int n, int m)
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