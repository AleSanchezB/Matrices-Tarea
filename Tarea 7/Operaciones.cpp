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
		throw std::runtime_error("No se pudo abrir el archivo");
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
	system("pause");
}

Matriz Determinante(Matriz** matriz, int n)
{
	if (n == 1) 
	{
		// Caso base: matriz de 1x1
		return matriz[0][0];
	}
	else 
	{
		Matriz det = 0;
		Matriz** submatriz = Crear(n - 1, n - 1);

		for (int i = 0; i < n; ++i) {
			// Obtiene la submatriz eliminando la primera fila y la columna i
			int submatriz_fila = 0;
			for (int j = 1; j < n; ++j) 
			{
				int submatriz_columna = 0;
				for (int k = 0; k < n; ++k) 
				{
					if (k != i) 
					{
						submatriz[submatriz_fila][submatriz_columna] = matriz[j][k];
						++submatriz_columna;
					}
				}
				++submatriz_fila;
			}

			// Calcula el cofactor como el determinante de la submatriz con signo alternante
			int signo = (i % 2 == 0) ? 1 : -1;
			Matriz cofactor = Determinante(submatriz, n - 1);
			det += signo * matriz[0][i] * cofactor;
		}

		Eliminar(submatriz, n - 1, n-1);
		return det;
	}
}


void InversaM(Matriz** matriz, Matriz** identidad, int n)
{
	if (Determinante(matriz, n) == 0)
		throw std::runtime_error("Esta matriz no tiene inversa");

	float aux, pivote;
	int fila_pivote;

	for (int i = 0; i < n; ++i) 
	{
		// Pivoteo parcial
		fila_pivote = i;
		while (matriz[fila_pivote][i] == 0) 
		{
			fila_pivote++;
			if (fila_pivote >= n)
				throw std::runtime_error("Esta matriz no tiene inversa");
		}
		// Intercambiar filas
		for (int j = 0; j < n; ++j) 
		{
			aux = matriz[i][j];
			matriz[i][j] = matriz[fila_pivote][j];
			matriz[fila_pivote][j] = aux;

			aux = identidad[i][j];
			identidad[i][j] = identidad[fila_pivote][j];
			identidad[fila_pivote][j] = aux;
		}

		pivote = matriz[i][i];

		// Haciendo los 1's principales.
		for (int j = 0; j < n; ++j) 
		{
			matriz[i][j] /= pivote;
			identidad[i][j] /= pivote;
		}

		// Reducir a cero arriba y abajo del 1 principal
		for (int j = 0; j < n; ++j) 
		{
			if (i != j) 
			{
				aux = matriz[j][i];
				for (int k = 0; k < n; ++k) 
				{
					matriz[j][k] -= aux * matriz[i][k];
					identidad[j][k] -= aux * identidad[i][k];
				}
			}
		}
	}
}

Matriz** InvertirMatriz(Matriz** A, int n)
{
	int i, j, k;
	float pivote, aux;
	Matriz** I = Crear(n, n);
	Matriz** matrizAux = Crear(n, n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			I[i][j] = 0;
			matrizAux[i][j] = A[i][j];
		}
		I[i][i] = 1;
	}

	for (i = 0; i < n; i++)
	{
		pivote = matrizAux[i][i];

		for (j = 0; j < n; j++)
		{
			matrizAux[i][j] = matrizAux[i][j] / pivote;
			I[i][j] = I[i][j] / pivote;
		}

		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				aux = matrizAux[j][i];

				for (k = 0; k < n; k++)
				{
					matrizAux[j][k] = matrizAux[j][k] - aux * matrizAux[i][k];
					I[j][k] = I[j][k] - aux * I[i][k];
				}
			}
		}
	}
	Eliminar(matrizAux, n, n);
	return I;
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

	for (int i = 0; i < FilasA; i++)
	{
		for (int j = 0; j < ColumnasB; j++)
		{
			resultado[i][j] = 0;
			for (int k = 0; k < ColumnasA; k++)
			{
				resultado[i][j] += A[i][k] * B[k][j];
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
			resultado[i][j] = matriz1[i][j] * escalar;
		}
	}
	return resultado;
}