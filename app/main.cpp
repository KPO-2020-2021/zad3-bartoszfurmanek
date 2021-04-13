// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>


#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

/*!
 * Funkcja służy do zapisu wspolrzednych wierzcholka do danego strumienia.
 * Pierwsze wspolrzedne zostaja zapisane ponownie, aby zachowac ciaglosc
 * przy wykonywaniu rysunku.
 * Argumenty: 
 *   StrmWy - Strumien do ktorego zostana zapisane dane.
 *   Pr - Prostokat ktorego wierzcholki maja zostac zapisane.
 * Zwraca:
 * True, jeżeli zapis uda sie pomyslnie, a w przeciwnym wypadku false.
 */
void ZapisWspolrzednychDoStrumienia(std::ostream& StrmWy, const Prostokat Pr)
{
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[3] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Funkcja służy do zapisu wspolrzednych prostokata od pliku w celu
 * narysowania i wyswietlenia go przez gnu-plot.
 * Argumenty: 
 *   sNazwaPliku - Nazwa pliku ktory ma przechowywac informacje o wierzcholkach
 *   Pr - Prostokat ktorego wierzcholki maja zostac zapisane.
 * Zwraca:
 * True, jeżeli zapis uda sie pomyslnie, a w przeciwnym wypadku false.
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, const Prostokat Pr)
{
  std::ofstream  StrmPlikowy;
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << "Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << " nie powiodla sie." << std::endl;
    return false;
  }
  ZapisWspolrzednychDoStrumienia(StrmPlikowy,Pr);
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}



int main()
{

  Prostokat             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   Pr[0]= Wektor2D(10,20);
   Pr[1]= Wektor2D(70,20);
   Pr[2]= Wektor2D(70,40);
   Pr[3]= Wektor2D(10,40);

  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);

  
  std::cout << Pr << std::endl;
  if (!ZapisWspolrzednychDoPliku("prostokat.dat",Pr)) 
  return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');

  Wektor2D Przesuniecie;
  std::cout << "Przyklad przesuniecia prostokata o wektor" << std::endl;
  std::cout << "Podaj wektor przesuniecia: ";
  std::cin >> Przesuniecie;
  std::cin.ignore(100000,'\n');
  Pr.Translacja(Przesuniecie);
  
  std::cout << std::endl << Pr << std::endl;
  if (!ZapisWspolrzednychDoPliku("prostokat.dat",Pr)) 
  return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');


  double Kat;
  int Powtorzenia;  
  std::cout << "Przyklad obrotu prostokata" << std::endl;
  std::cout << "Podaj kat obrotu prostokata: ";
  std::cin >> Kat;
  std::cin.ignore(100000,'\n');
  std::cout << "Podaj ilosc powtorzen obrotu: ";
  std::cin >> Powtorzenia;
  std::cin.ignore(100000,'\n');
  Pr.Obrot(Kat, Powtorzenia);

  std::cout << std::endl << Pr << std::endl;
  if (!ZapisWspolrzednychDoPliku("prostokat.dat",Pr)) 
  return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
  std::cin.ignore(100000,'\n');

  std::cout << "Przyklad Porownania dlugosci bokow" << std::endl << std::endl;

  Pr.PorownajBoki();

return 0;
}
