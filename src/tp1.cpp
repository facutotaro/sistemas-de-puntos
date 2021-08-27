#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

vector<double> resolverColley(int equipos, vector<vector<double>> matriz, vector<double> extencion);

int main(int argc, char* argv[]) {
	// Abrir archivo de entrada
	ifstream entrada;
	entrada.open(argv[1]);

	// Leer cantidad de equipos
	int equipos;
	entrada >> equipos;

	// Inicializar contadores
	vector<int> ganados = vector<int>(equipos, 0);
	vector<int> perdidos = vector<int>(equipos, 0);

	// Inicializar matriz de Colley
	vector<vector<double>> colley = vector<vector<double>>(equipos, vector<double>(equipos, 0));
	for (int i = 0; i < equipos; i++) { colley[i][i] = 2; }

	// Leer cantidad de partidos
	int partidos;
	entrada >> partidos;

	// Procesar partidos
	for (int i = 0; i < partidos; i++) {
		int fecha, equipoA, puntajeA, equipoB, puntajeB;
		entrada >> fecha;
		entrada >> equipoA; equipoA--;
		entrada >> puntajeA;
		entrada >> equipoB; equipoB--;
		entrada >> puntajeB;

		// Actualizar contadores
		if (puntajeA > puntajeB) {
			ganados[equipoA]++;
			perdidos[equipoB]++;
		} else {
			perdidos[equipoA]++;
			ganados[equipoB]++;
		}

		// Actualizar matriz de Colley
		colley[equipoA][equipoA]++;
		colley[equipoB][equipoB]++;
		colley[equipoA][equipoB]++;
		colley[equipoB][equipoA]++;
	}

	// Cerrar archivo de entrada
	entrada.close();


	// Calcular calificaciones
	vector<double> resultados = vector<double>(equipos);
	{
		// Matriz de Colley
		if (!strcmp(argv[3],"0")) {
			vector<double> extencion = vector<double>(equipos);
			for (int i = 0; i < equipos; i++) { extencion[i] = 1+(ganados[i]-perdidos[i])/2.0; }
			resultados = resolverColley(equipos, colley, extencion);
		}

		// Porcentajes de victorias
		if (!strcmp(argv[3],"1")) {
			for (int i = 0; i < equipos; i++) {	resultados[i] = ganados[i]/(ganados[i]+perdidos[i]+0.0); }
		}

		// Método chingón
		if (!strcmp(argv[3],"2")) {
			for (int i = 0; i < equipos; i++) { resultados[i] = i/10.0;	}
		}
	}


	// Abrir archivo de salida
	ofstream salida;
	salida.open(argv[2]);

	// Volcar resultados
	for (int i = 0; i < equipos; i++) { salida << resultados[i] << endl; }

	// Cerrar archivo de salida
	salida.close();

	return 0;
}


vector<double> resolverColley(int equipos, vector<vector<double>> matriz, vector<double> extencion) {
	/* [ Realice magia turbia aquí ] */

	return vector<double>(equipos, 0.1234);
}
