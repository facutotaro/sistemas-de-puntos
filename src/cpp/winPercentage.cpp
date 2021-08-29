#include "winPercentage.h"
#include <cassert>

vector<double> winPercentage(int participantes, vector<Partido> partidos) {
  // Inicializar contadores
  vector<int> ganados = vector<int>(participantes, 0);
  vector<int> jugados = vector<int>(participantes, 0);

  // Contar
  for (Partido p : partidos) {
    ganados[p.ganador()]++;
    jugados[p.ganador()]++;
    jugados[p.perdedor()]++;
  }

  // Calcular porcentaje
  vector<double> resultados = vector<double>(participantes);
  for (int i = 0; i < participantes; i++) {
    assert(jugados[i] > 0);
    resultados[i] = 1.0*ganados[i]/jugados[i];
  }

	return resultados;
}
