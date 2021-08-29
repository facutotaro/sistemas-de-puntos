#include <cassert>

class Partido {
  public:
    Partido(int equipoA, int equipoB, int puntajeA, int puntajeB) {
        assert(equipoA != equipoB);
        assert(puntajeA != puntajeB);
        _ganador  = puntajeA > puntajeB ? equipoA : equipoB;
        _perdedor = puntajeA > puntajeB ? equipoB : equipoA;
    }

    int ganador()  { return _ganador; }
    int perdedor() { return _perdedor; }

  private:
    int _ganador, _perdedor;
};
