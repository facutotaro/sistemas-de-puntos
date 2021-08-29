#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

#include "partido.cpp"
#include "colleyMatrix.h"
#include "winPercentage.h"
#include "ratingIndex.h"

int main(int argc, char* argv[]) {
	// Abrir archivo de entrada
	ifstream entrada;
	entrada.open(argv[1]);

	// Leer cantidad de participantes y de partidos
	int participantes, cantidadPartidos;
	entrada >> participantes;
	entrada >> cantidadPartidos;

	// Procesar partidos
	vector<Partido> partidos = vector<Partido>();
	for (int i = 0; i < cantidadPartidos; i++) {
		int fecha, equipoA, puntajeA, equipoB, puntajeB;
		entrada >> fecha;
		entrada >> equipoA;
		entrada >> puntajeA;
		entrada >> equipoB;
		entrada >> puntajeB;
		partidos.push_back(Partido(equipoA-1, equipoB-1, puntajeA, puntajeB));
	}

	// Cerrar archivo de entrada
	entrada.close();


	// Calcular calificaciones
	vector<double> resultados = vector<double>(participantes);
	{
		// Matriz de Colley
		if (!strcmp(argv[3],"0")) {
			resultados = colleyMatrix(participantes, partidos); }

		// Porcentaje de ganados
		if (!strcmp(argv[3],"1")) {
			resultados = winPercentage(participantes, partidos); }

		// Índice de rating
		if (!strcmp(argv[3],"2")) {
			resultados = ratingIndex(participantes, partidos); }
	}


	// Abrir archivo de salida
	ofstream salida;
	salida.open(argv[2]);

	// Volcar resultados
	for (int i = 0; i < participantes; i++) { salida << resultados[i] << endl; }

	// Cerrar archivo de salida
	salida.close();

	return 0;
}
