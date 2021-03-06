#include "ratingIndex.h"
#include <cassert>

vector<double> ratingIndex(int participantes, vector<Partido> partidos) {
  // Inicializar contadores
  vector<int> ganadosTotal = vector<int>(participantes, 0);
  vector<int> jugadosTotal = vector<int>(participantes, 0);
	vector<vector<double>> ganadosContra =
		vector<vector<double>>(participantes, vector<double>(participantes, 0));
	vector<vector<double>> jugadosContra =
		vector<vector<double>>(participantes, vector<double>(participantes, 0));

  // Contar
  for (Partido p : partidos) {
    ganadosTotal[p.ganador()]++;
    jugadosTotal[p.ganador()]++;
    jugadosTotal[p.perdedor()]++;
		ganadosContra[p.ganador()][p.perdedor()]++;
		jugadosContra[p.ganador()][p.perdedor()]++;
		jugadosContra[p.perdedor()][p.ganador()]++;
  }

  // Calcular porcentaje propio
  vector<double> porcentajesPropios = vector<double>(participantes, 0.5);
  for (int i = 0; i < participantes; i++) {
    if (jugadosTotal[i] == 0) { continue; }
    porcentajesPropios[i] = 1.0*ganadosTotal[i]/jugadosTotal[i];
  }

  // Calcular porcentaje de oponentes
  vector<double> porcentajesOponentes = vector<double>(participantes, 0.5);
  for (int i = 0; i < participantes; i++) {
		double porcentajeOponentes = 0;
		for (int oponente = 0; oponente < participantes; oponente++) {
			int ganadosContraOtro = ganadosTotal[oponente]-ganadosContra[oponente][i];
			int jugadosContraOtro = jugadosTotal[oponente]-jugadosContra[oponente][i];
      if (jugadosContraOtro == 0) { porcentajeOponentes += 0.5; continue; }
			porcentajeOponentes += 1.0 * jugadosContra[i][oponente] *
				ganadosContraOtro / jugadosContraOtro;
		}
    if (jugadosTotal[i] == 0) { continue; }
		porcentajesOponentes[i] = porcentajeOponentes / jugadosTotal[i];
  }

  // Calcular porcentaje de oponentes de oponentes
  vector<double>porcentajesOponentesOponentes=vector<double>(participantes,0.5);
  for (int i = 0; i < participantes; i++) {
		double porcentajeOponentesOponentes = 0;
		for (int oponente = 0; oponente < participantes; oponente++) {
			porcentajeOponentesOponentes += 1.0 * jugadosContra[i][oponente] *
				porcentajesOponentes[oponente];
		}
    if (jugadosTotal[i] == 0) { continue; }
		porcentajesOponentesOponentes[i] =
			porcentajeOponentesOponentes / jugadosTotal[i];
  }

	// Calcular ??ndices resultado
	vector<double> indicesResultado = vector<double>(participantes);
	for (int i = 0; i < participantes; i++) {
    indicesResultado[i] =
			0.25*porcentajesPropios[i] +
			0.50*porcentajesOponentes[i] +
			0.25*porcentajesOponentesOponentes[i];
	}

	return indicesResultado;
}
