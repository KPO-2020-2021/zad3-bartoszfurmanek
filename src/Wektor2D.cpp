#include "Wektor2D.hh"
#include <iostream>


/*!
 * Metoda służąca do indeksowania Wektora.
 * Argumenty:
 *    Wektor2D - indeksowany wektor
 *    Indeks - indeks rządanej składowej.
 * Zwraca:
 *    Wartośc składowej Wektora o zadanym indeksie.
 */
double Wektor2D::operator [](int Indeks)const
{
return Wektor[Indeks];
}


/*!
 * Metoda służąca do indeksowania Wektora.
 * Argumenty:
 *    Wektor2D - indeksowany wektor
 *    Indeks - indeks rządanej składowej.
 * Zwraca:
 *    Referencje do składowej wektora o danym indeksie.
 */
double& Wektor2D::operator[](int Indeks)
{
return Wektor[Indeks];
}


/*!
 * Konstruktor bezparametryczny dla Wektora.
 */
Wektor2D::Wektor2D()
{
for(int i=0; i<Rozmiar; i++)
    {
    Wektor[i]=0;
    }
}


/*!
 * Konstruktor parametryczny dla Wektora w dwóch wymiarach.
 */
Wektor2D::Wektor2D(double elem0, double elem1)
{
Wektor[0]=elem0;
Wektor[1]=elem1;
}

/*!
 * Metoda służąca do dodawania wektorów.
 * Argumenty:
 *    this - Pierwszy wektorowy składnik dodawania.
 *    W - Drugi wektorowy składnik dodawania.
 * Zwraca:
 *    Sume dwóch wektorów.
 */
Wektor2D Wektor2D::operator+ (Wektor2D W)const
{
Wektor2D Wynik;
for(int i=0; i<this->Rozmiar; i++)
    {
    Wynik[i] = (*this)[i] + W[i];
    }
return Wynik;
}

/*!
 * Metoda służąca do odejmowania wektorów.
 * Argumenty:
 *    this - Pierwszy wektorowy składnik odejmowania.
 *    W - Drugi wektorowy składnik odejmowania.
 * Zwraca:
 *    Różnice dwóch wektorów.
 */
Wektor2D Wektor2D::operator- (Wektor2D W)const
{
Wektor2D Wynik;
for(int i=0; i<this->Rozmiar; i++)
    {
    Wynik[i] = (*this)[i] - W[i];
    }
return Wynik;
}


/*!
 * Metoda służąca do mnożenia wektora przez skalar.
 * Argumenty:
 *    this - Wektor.
 *    Liczba - Wartośc skalarna przez, która wektor będzie mnożony.
 * Zwraca:
 *    Przemnożony wektor.
 */
Wektor2D Wektor2D::operator* (double Liczba)const
{
Wektor2D Wynik;

for(int i=0; i<this->Rozmiar; i++)
    {
    Wynik[i] = (*this)[i] * Liczba;
    }
return Wynik;
}


/*!
 * Funkcja służąca do mnożenia wektora przez skalar (W kolejnosci skalar * wektor).
 * Argumenty:
 *    Liczba - Wartośc skalarna przez, która wektor będzie mnożony.
 *    W - Przemnażany wektor.
 * Zwraca:
 *    Przemnożony wektor.
 */
Wektor2D operator * (double Liczba, Wektor2D W)
{
Wektor2D Wynik;

for(int i=0; i<W.Rozmiar; i++)
    {
    Wynik[i] = W[i] * Liczba;
    }

return Wynik;
}

/*!
 * Metoda służąca do porównywania wektorów.
 * Argumenty:
 *    this - Pierwszy składnik porownywania.
 *    W - Drugi składnik porownywania.
 * Zwraca:
 *    True, jeżeli wektory są takie same lub False, jeżeli nie są.
 */
bool Wektor2D::operator == (Wektor2D W)const
{
for(int i=0; i<Rozmiar; i++)
    {
    if((*this)[i]!=W[i])
        {return false;}
    }
return true;
}

/*!
 * Metoda służąca do obliczania odległości między dwoma wektorami.
 * Argumenty:
 *    this - Pierwszy wektor.
 *    W - Drugi wektor.
 * Zwraca:
 *    Odlegość między wektorem this a wektorem W.
 */
double Wektor2D::Odleglosc(Wektor2D W)const
{
double Wynik=0;
for(int i=0; i<ROZMIAR_WEKTORA; i++)
    {
    Wynik += pow(((*this)[i]-W[i]),2);
    }
Wynik = sqrt(Wynik);
return Wynik;
}

/*!
 * Funkcja służąca do wczytywania wektora z danego strumienia.
 * Argumenty:
 *    Strm - Strumień, z którego wektor ma zostać wczytany.
 *    Wek - Referencja do wektora, do którego dane mają zostać zapisane.
 * Zwraca:
 *    Strumień z którego wektor został wczytany.
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
for (int i=0; i<Wek.Rozmiar; i++)
    {
    Strm >> Wek[i];
    if(Strm.fail())
        {
        Strm.setstate(std::ios::failbit);
        throw std::runtime_error("Blad wczytania wektora");
        return Strm;
        }
    }
return Strm;
}


/*!
 * Funkcja służąca do przekazywania wektora do danego strumienia.
 * Argumenty:
 *    Strm - Strumień, na który wektor ma zostać wypisany.
 *    Wek - Wektor, ktory ma zostać wypisany.
 * Zwraca:
 *    Strumień na który wektor został wypisany.
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
for (int i=0; i<Wek.Rozmiar; i++)
    {
    Strm << Wek[i];
    if(i!=(Wek.Rozmiar-1))
        {
        Strm << " ";
        }
    }
return Strm;
}






