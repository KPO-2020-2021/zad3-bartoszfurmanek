#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include "Wektor2D.hh"

#define WYMIAR_W 2
#define WYMIAR_K 2

/*!
 * Klasa reprezentująca macierz. Ilościa danych składowych
 * mozną manipulować za pomocą stałych WYMIAR_W (ilosc wierszy)
 * oraz WYMIAR_K (ilosc kolumn). Macierz można indeksować za
 * pomocą ().Na macierzy mozna wykonywa podstawowe dzialania matematyczne.
 */
class Macierz {

  int RozmiarK = WYMIAR_K;
  int RozmiarW = WYMIAR_W;
  double elem[WYMIAR_W][WYMIAR_K];
  
  public:

  double operator() (int IndeksW, int IndeksK)const;

  double& operator() (int IndeksW, int IndeksK);

  Macierz();

  Macierz(double, double, double, double); //Dla macierzy 2x2

  bool operator== (Macierz M)const;
  
  Macierz operator+ (Macierz M)const;

  Macierz operator- (Macierz M)const;
  
  Macierz operator* (Macierz M)const;

  Macierz operator* (double Liczba)const;
    
  friend Macierz operator* (double Liczba, Macierz M);

  Wektor2D operator* (Wektor2D W)const;

  friend std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


};

  Macierz MacierzObrotu(double alfa);

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);

#endif
