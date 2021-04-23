#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Macierz2x2.hh"
#include <iomanip>
#include <cmath>

/*!
 * Klasa reprezentująca prostokat. Każdy wierzcholek prostokata
 * jest reprezentowany przez wektor2D. Wierzcholki można indeksować
 * za pomoca [] oraz (). Prostokat mozna obracac, przesuwac oraz
 * porownywac jego boki.
 */
class Prostokat {

Wektor2D Punkt[4];
  
public:

Wektor2D operator[](int Indeks)const;

Wektor2D& operator[](int Indeks);

Prostokat();

Prostokat(Wektor2D W0,Wektor2D W1,Wektor2D W2,Wektor2D W3);

bool operator == (Prostokat P)const;

Prostokat& Obrot(double alfa);

Prostokat& Translacja(Wektor2D W);

void PorownajBoki()const;

friend std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);


#endif
