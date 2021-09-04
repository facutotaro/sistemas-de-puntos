#include <vector>
#include <map>
#include <fstream>
using namespace std;

#include "partido.cpp"

/* Asigna a cada ID de participante un número entre 0 y n exclusive */
/* Guarda un archivo con la traducción y otro con la decodificación */
/* arg1 = entrada, arg2 = (out)traducción, arg3 = (out)codificación */

int main(int argc, char* argv[]) {
	// Abrir archivos de entrada y salida
	ifstream entrada;
	ofstream salida, codigo;
	entrada.open(argv[1]);
	salida.open(argv[2]);
	codigo.open(argv[3]);

	// Leer cantidad de participantes y de partidos, y copiar a la salida
	int participantes, cantidadPartidos;
	entrada >> participantes;
	entrada >> cantidadPartidos;
	salida << participantes << ' ' << cantidadPartidos << endl;

	// Inicializar diccionario de codificación
	map<int, int> codigos = map<int, int>();

	// Procesar partidos
	for (int i = 0; i < cantidadPartidos; i++) {
		int fecha, equipoA, puntajeA, equipoB, puntajeB;

		// Leer el partido sin codificar desde el archivo de entrada
		entrada >> fecha;
		entrada >> equipoA;
		entrada >> puntajeA;
		entrada >> equipoB;
		entrada >> puntajeB;

		// En caso de encontrar un equipo por primera vez, generar su codificación
		if (codigos.count(equipoA) == 0) {
			codigos[equipoA] = codigos.size()+1;
			codigo << equipoA << endl;
		}
		if (codigos.count(equipoB) == 0) {
			codigos[equipoB] = codigos.size()+1;
			codigo << equipoB << endl;
		}

		// Guardar el partido codificado en el archivo de salida
		salida << fecha            << ' ';
		salida << codigos[equipoA] << ' ';
		salida << puntajeA         << ' ';
		salida << codigos[equipoB] << ' ';
		salida << puntajeB         << endl;
	}

	// Cerrar archivos
	entrada.close();
	salida.close();
	codigo.close();

	return 0;
}
