#include <vector>
#include "partido.cpp"
using namespace std;

vector<double> colleyMatrix(int participantes, vector<Partido> partidos);
void eliminacionGaussiana(vector<vector<double>> &matriz, vector<double> &ext);
vector<double> susReversa(vector<vector<double>> &matriz, vector<double> &ext);
