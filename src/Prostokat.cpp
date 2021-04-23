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
{
if(Indeks >= 4)
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return Punkt[Indeks];
    }
}
/*!
 * Metoda służąca do indeksowania prostokata.
 * Argumenty:
 *    this - indeksowany prostokat
 *    Indeks - indeks rządanego wierzcholka.
 * Zwraca:
 *    Referencja do wektora, ktory reprezentuje rzadany wierzcholek
 */
Wektor2D& Prostokat::operator[](int Indeks)
{
if(Indeks >= 4)
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return Punkt[Indeks];
    }
}


/*!
 * Konstruktor bezparametryczny dla Prostokata.
 */
Prostokat::Prostokat()
{
    for(int i=0; i<4; i++)
        {
        Punkt[i]={0,0}; 
        }
}


/*!
 * Konstruktor parametryczny dla Prostokata.
 */
Prostokat::Prostokat(Wektor2D W0,Wektor2D W1,Wektor2D W2,Wektor2D W3)
{
Punkt[0]=W0;
Punkt[1]=W1;
Punkt[2]=W2;
Punkt[3]=W3;
}

/*!
 * Metoda służąca do porównywania prostokatow.
 * Argumenty:
 *    this - Pierwszy składnik porownywania.
 *    P - Drugi składnik porownywania.
 * Zwraca:
 *    True, jeżeli wektory są takie same lub False, jeżeli nie są.
 */
bool Prostokat::operator == (Prostokat P)const
{
for(int i=0; i<4; i++)
    {
    if(!((*this)[i]==P[i]))
        {return false;}
    }
return true;
}

/*!
 * Metoda służąca do obracania prostokata o zadany kat
 * Argumenty:
 *    this - Prostokat
 *    alfa - Kat obrotu macierzy
 *    Powtorzenia - Ilosc powtorzen obrotow o kat alfa
 * Zwraca:
 *    Obrocony prostokat
 */
Prostokat& Prostokat::Obrot(double alfa)
{
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
    std::cout<< std::endl<< "Dluzsze przeciwlegle boki";
    }
else
    {
    std::cout<< std::endl<< "Krotsze przeciwlegle boki";
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





