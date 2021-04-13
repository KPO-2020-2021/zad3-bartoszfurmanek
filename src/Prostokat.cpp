#include "Prostokat.hh"
#define PI 3.1415926535

/*!
 * Metoda służąca do indeksowania prostokata.
 * Argumenty:
 *    this - indeksowany prostokat
 *    Indeks - indeks rządanego wierzcholka.
 * Zwraca:
 *    Wektor reprezentujacy rzadany wierzcholek
 */
Wektor2D Prostokat::operator[](int Indeks)const
{return Punkt[Indeks];}


/*!
 * Metoda służąca do indeksowania prostokata.
 * Argumenty:
 *    this - indeksowany prostokat
 *    Indeks - indeks rządanego wierzcholka.
 * Zwraca:
 *    Referencja do wektora, ktory reprezentuje rzadany wierzcholek
 */
Wektor2D& Prostokat::operator[](int Indeks)
{return Punkt[Indeks];}


/*!
 * Metoda służąca do indeksowania prostokata.
 * Argumenty:
 *    this - Indeksowany prostokat.
 *    IndeksP - Indeks prostokata (numer wierzcholka)
 *    IndeksW - Indeks wektora (numer skladowej)
 * Zwraca:
 *    Wartosc danej skladowej wektora reprezentujacego wierzcholek prostokata.
 */
double Prostokat::operator()(int IndeksP, int IndeksW)const
{return (Punkt[IndeksP])[IndeksW];}


/*!
 * Metoda służąca do indeksowania prosotkata.
 * Argumenty:
 *    this - Indeksowany prostokat.
 *    IndeksP - Indeks prostokata (numer wierzcholka)
 *    IndeksW - Indeks wektora (numer skladowej)
 * Zwraca:
 *    Referencja do danej wartosci skladowej wektora reprezentujacego wierzcholek prostokata.
 */
double& Prostokat::operator()(int IndeksP, int IndeksW)
{return (Punkt[IndeksP])[IndeksW];}


/*!
 * Metoda służąca do obracania prostokata o zadany kat
 * Argumenty:
 *    this - Prostokat
 *    alfa - Kat obrotu macierzy
 *    Powtorzenia - Ilosc powtorzen obrotow o kat alfa
 * Zwraca:
 *    Obrocony prostokat
 */
Prostokat& Prostokat::Obrot(double alfa, int Powtorzenia)
{
alfa*=(double)Powtorzenia;
alfa=fmod(alfa, 360);  //Usuniecie okresow (Dzielenie z reszta). To działanie ma na celu zminimalizowanie ilości błędów obliczeń
if(alfa<0)
    {
    alfa+=360; //Zmiana na dodatni kat
    }
alfa=(alfa*PI)/180.0; //Zamiana na radiany
for(int i=0; i<4; i++)
    {
    (*this)[i] = MacierzObrotu(alfa) * (*this)[i];  //Wymnożenie każdego wierzcholka przez macierz obrotu
    }
return *this;
}


/*!
 * Metoda służąca do przesuwania prostokata o zadany wektor
 * Argumenty:
 *    this - Prostokat.
 *    W - Wektor przesuniecia.
 * Zwraca:
 *    Przesuniety prostokat.
 */
Prostokat& Prostokat::Translacja(Wektor2D W)
{
for(int i=0; i<4; i++)
    {
    (*this)[i]=(*this)[i]+W;  //Przesuniecie kazdego wierzcholka o wektor
    }
return *this;
}


/*!
 * Funkcja służąca do wypisywania wierzcholkow prostokata na strumien.
 * Argumenty:
 *    Strm - Strumien, na ktory zostana wypisane wierzcholki.
 *    Pr - Wypisywany prostokat.
 * Zwraca:
 *    Strumien, na ktory zostaly wypisane dane.
 */
std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr)
{
for(int i=0; i<4; i++)
    {
    Strm << std::setw(16) << std::fixed << std::setprecision(10) << Pr[i] << std::endl;
    }
return Strm;
}

/*!
 * Metoda służąca do porownywania bokow prostokata i wypisywania informacji o nich.
 * Argumenty:
 *    this - Prostokat
 */
void Prostokat::PorownajBoki()const
{
double bok1, bok2, bok3, bok4;

bok1=(*this)[0].Odleglosc((*this)[1]);
bok2=(*this)[1].Odleglosc((*this)[2]);
bok3=(*this)[2].Odleglosc((*this)[3]);
bok4=(*this)[3].Odleglosc((*this)[0]);

if(bok1>bok2)
    {
    std::cout << "Dluzsze przeciwlegle boki";
    }
else
    {
    std::cout << "Krotsze przeciwlegle boki";
    }

if(abs(bok1-bok3)<=0.0001)
    {
    std::cout << " sa sobie rowne." << std::endl;
    }
else
    {
    std::cout << " nie sa sobie rowne." << std::endl;
    }
std::cout << "Dlugosc pierwszego boku: " << std::setprecision(20) << bok1 << std::endl;
std::cout << "Dlugosc pierwszego boku: " << std::setprecision(20) << bok3 << std::endl << std::endl;

if(bok1<bok2)
    {
    std::cout << "Dluzsze przeciwlegle boki";
    }
else
    {
    std::cout << "Krotsze przeciwlegle boki";
    }

if(abs(bok2-bok4)<=0.0001)
    {
    std::cout << " sa sobie rowne." << std::endl;
    }
else
    {
    std::cout << " nie sa sobie rowne." << std::endl;
    }
std::cout << "Dlugosc pierwszego boku: " << std::setprecision(20) << bok2 << std::endl;
std::cout << "Dlugosc pierwszego boku: " << std::setprecision(20) << bok4 << std::endl << std::endl;
}






