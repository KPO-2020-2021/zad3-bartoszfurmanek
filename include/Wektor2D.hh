#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <tgmath.h>
#include <math.h>

#define ROZMIAR_WEKTORA 2



/*!
 * Klasa reprezentująca wektor. Ilościa danych składowych
 * mozną manipulować za pomocą stałej ROZMIAR_WEKTORA. Klasa
 * może reprezentować wektor o różnych wymiarach. Wektor można
 * indeksować za pomocą operatora []. Na wektorze mozna wykonywać
 * podstawowe dzialania matematyczne.
 */
class Wektor2D {

  int Rozmiar = ROZMIAR_WEKTORA;
  double Wektor[ROZMIAR_WEKTORA];

  public:

  friend class Macierz;

  double operator[](int Indeks)const;

  double& operator[](int Indeks);

  Wektor2D();

  Wektor2D(double, double);   //Tylko dla wektora 2D
  
  Wektor2D operator+ (Wektor2D W)const;

  Wektor2D operator- (Wektor2D W)const;

  Wektor2D operator* (double Liczba)const;
  
  bool operator == (Wektor2D W)const;

  double Odleglosc(Wektor2D W)const;
  
  friend Wektor2D operator *(double Liczba, Wektor2D W);
  
  friend std::istream& operator >> (std::istream &Strm, Wektor2D &Wek); 

  friend std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);
 
};

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
