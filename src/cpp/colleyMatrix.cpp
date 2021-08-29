#include "colleyMatrix.h"

vector<double> colleyMatrix(int participantes, vector<Partido> partidos) {
  // Inicializar matriz de Colley
  vector<vector<double>> matriz =
    vector<vector<double>>(participantes, vector<double>(participantes, 0));
  for (int i = 0; i < participantes; i++) { matriz[i][i] = 2; }

  // Inicializar contadores
  vector<int> ganados  = vector<int>(participantes, 0);
  vector<int> perdidos = vector<int>(participantes, 0);

  // Procesar partidos
  for (Partido p : partidos) {
    ganados[p.ganador()]++;
    perdidos[p.perdedor()]++;

    matriz[p.ganador()][p.ganador()]++;
    matriz[p.ganador()][p.perdedor()]--;
    matriz[p.perdedor()][p.ganador()]--;
    matriz[p.perdedor()][p.perdedor()]++;
  }

  // Calcular vector de extensión
  vector<double> extension = vector<double>(participantes);
  for (int i = 0; i < participantes; i++) {
    extension[i] = 1+(ganados[i]-perdidos[i])/2.0; }

  // Realizar eliminación gaussiana
  eliminacionGaussiana(matriz, extension);

  // Realizar sustitución en reversa
  vector<double> resultados = susReversa(matriz, extension);

	return resultados;
}

void eliminacionGaussiana(vector<vector<double>>& matriz, vector<double>& ext) {
  int tamanio = matriz.size();

  for (int paso = 1; paso < tamanio; paso++) {
    for (int fila = paso+1; fila <= tamanio; fila++) {
      // Calcular multiplicador
      double multiplicador = matriz[fila-1][paso-1]/matriz[paso-1][paso-1];

      // Restar multiplo a la fila
      for (int columna = paso; columna <= tamanio; columna++) {
        matriz[fila-1][columna-1] -= matriz[paso-1][columna-1]*multiplicador;
      }
      ext[fila-1] -= ext[paso-1]*multiplicador;
    }
  }
}

vector<double> susReversa(vector<vector<double>>& matriz, vector<double>& ext) {
  int tamanio = matriz.size();
  vector<double> solucion = vector<double>(tamanio);

  for (int fila = tamanio; fila >= 1; fila--) {
    // Calcular la suma de los demás términos de la ecuación
    double sumaDeRestoDeLaFila = 0;
    for (int columna = fila+1; columna <= tamanio; columna++) {
      sumaDeRestoDeLaFila += matriz[fila-1][columna-1]*solucion[columna-1];
    }

    // Despejar la coordenada sin resolver, y calcular
    solucion[fila-1] = (ext[fila-1]-sumaDeRestoDeLaFila)/matriz[fila-1][fila-1];
  }

	return solucion;
}
