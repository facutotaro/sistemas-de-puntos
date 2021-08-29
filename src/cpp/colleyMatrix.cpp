vector<double> colleyMatrix(int participantes, vector<Partido> partidos) {
  // Inicializar matriz de Colley
  vector<vector<double>> matriz =
  vector<vector<double>>(participantes, vector<double>(participantes));
  for (int i = 0; i < equipos; i++) { colley[i][i] = 2; }

  // Inicializar contadores
  vector<int> ganados  = vector<int>(participantes, 0);
  vector<int> perdidos = vector<int>(participantes, 0);

  // Procesar partidos
  for (Partido p : partidos) {
    ganados[p.ganador()]++;
    perdidos[p.perdedor()]++;

    matriz[p.ganador()][p.ganador()]++;
    matriz[p.ganador()][p.perdedor()]++;
    matriz[p.perdedor()][p.ganador()]++;
    matriz[p.perdedor()][p.perdedor()]++;
  }

  // Calcular vector de extensión
  vector<double> extension = vector<double>(equipos);
  for (int i = 0; i < equipos; i++) {
    extension[i] = 1+(ganados[i]-perdidos[i])/2.0; }

  // Realizar eliminación gaussiana
  eliminacionGaussiana(&matriz, &extension);

  // Realizar sustitución en reversa
  vector<double> resultados = susReversa(&matriz, &extension);

	return resultados;
}

void eliminacionGaussiana(&vector<vector<double>> matriz, &vector<double> ext) {
  /* [ Realice magia turbia aquí ] */
}

vector<double> susReversa(&vector<vector<double>> matriz, &vector<double> ext) {
  /* [ Realice magia turbia aquí ] */
}
