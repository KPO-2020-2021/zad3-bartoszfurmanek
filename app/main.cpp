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

  Prostokat             Pr;     
  PzG::LaczeDoGNUPlota  Lacze;      //Zmienna do operowania na gnuplocie
  char                  Opcja;      //Zmienna przechowujaca informacje o wybranej opcji w menu
  double                Kat;        //Kat obrotu prostokata    
  int                   Powtorzenia;//Ilosc powtorzen obrotu prostokata
  Wektor2D              Przesuniecie;//Wektor przesuniecia prostokata

   Pr[0]= Wektor2D(10,20);
   Pr[1]= Wektor2D(70,20);
   Pr[2]= Wektor2D(70,40);
   Pr[3]= Wektor2D(10,40);      //Ustalenie wierzcholkow prostokata

  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);     //Podlaczenie pliku, w ktorym beda zapisywane wspolrzedne do rysowania

  Pr.PorownajBoki();

  std::cout<< std::endl;                                       //Wyswietlenie menu programu
  std::cout<< "o - obrot prostokata o wybrany kat, z wybrana iloscia powtorzen" << std::endl;
  std::cout<< "p - przesuniecie prostokata o zadany wektor" << std::endl;
  std::cout<< "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
  std::cout<< "b - porowanie bokow prostokata" << std::endl;
  std::cout<< "m - wyswietlenie menu" << std::endl;
  std::cout<< "k - koniec programu" << std::endl;
  std::cout<< std::endl;

  while(1)
    {
    std::cout<< "Wybrana opcja: ";
    std::cin>> Opcja;
    switch(Opcja)
        {
        case 'o':    //Wybor obortu prostokata
            {
            std::cout << "Podaj kat obrotu prostokata: ";
            std::cin >> Kat;
            std::cin.ignore(100000,'\n');
            std::cout << "Podaj ilosc powtorzen obrotu: ";
            std::cin >> Powtorzenia;
            std::cin.ignore(100000,'\n');
            
            Pr.Obrot(Kat, Powtorzenia);                  //Obrot prostokata

            Pr.PorownajBoki();                           //Porownanie dlugosci bokow prostokata

            if (!ZapisWspolrzednychDoPliku("prostokat.dat",Pr))
                {
                return 1;
                }
            Lacze.Rysuj();                                //Rysowania z pliku
            std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
            std::cin.ignore(100000,'\n');
            

            break;
            }
        case 'p':
            {
            std::cout << "Podaj wektor przesuniecia: ";
            std::cin >> Przesuniecie;
            std::cin.ignore(100000,'\n');

            Pr.Translacja(Przesuniecie);     //Przesuniecie prostokata o zadany wektora

            if (!ZapisWspolrzednychDoPliku("prostokat.dat",Pr)) 
                {
                return 1;
                }    
            Lacze.Rysuj();                              // Rysowanie z pliku
            std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
            std::cin.ignore(100000,'\n');

            break;
            }
        case 'w':       //Wyswietlenie wspolrzednych
            {
            std::cout<< std::endl<< Pr<< std::endl;
            break;
            }
        case 'b':       //Porownanie bokow
            {
            Pr.PorownajBoki(); 
            break;
            }
        case 'm':
            {
            std::cout<< std::endl;                                       //Wyswietlenie menu programu
            std::cout<< "o - obrot prostokata o wybrany kat, z wybrana iloscia powtorzen" << std::endl;
            std::cout<< "p - przesuniecie prostokata o zadany wektor" << std::endl;
            std::cout<< "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
            std::cout<< "b - porowanie bokow prostokata" << std::endl;
            std::cout<< "m - wyswietlenie menu" << std::endl;
            std::cout<< "k - koniec programu" << std::endl;
            std::cout<< std::endl;
            break;
            }
        case 'k':       //Koniec programu
            {
            std::cout<< std::endl << "KONIEC PROGRAMU" << std::endl;
            return 0;
            }
        default:        //Wybor zlej opcji
            {
            std::cout<< std::endl<< "Blad wyboru opcji, sprobuj ponownie"<< std::endl;
            }
        }
    }

}
