#include "Macierz2x2.hh"


#define MIN_ROZNICA 0.001


/*!
 * Metoda służąca do indeksowania macierzy.
 * Argumenty:
 *    this - Indeksowana macierz
 *    IndeksW - Indeks wiersza.
 *    IndeksK - Indeks kolumny.
 * Zwraca:
 *    Wartośc komorki macierzy o danym indeksie.
 */
double Macierz::operator() (int IndeksW, int IndeksK)const
{
if((IndeksW >= RozmiarW) && (IndeksK >= RozmiarK))
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return elem[IndeksW][IndeksK];
    }
}


/*!
 * Metoda służąca do indeksowania macierzy.
 * Argumenty:
 *    this - Indeksowana macierz
 *    IndeksW - Indeks wiersza.
 *    IndeksK - Indeks kolumny.
 * Zwraca:
 *    Referencja do komorki macierzy o danym indeksie.
 */
double& Macierz::operator() (int IndeksW, int IndeksK)
{
if((IndeksW >= RozmiarW) && (IndeksK >= RozmiarK))
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return elem[IndeksW][IndeksK];
    }
}

/*!
 * Konstruktor bezparametryczny dla macierzy.
 */
Macierz::Macierz()
{
for(int i=0; i<RozmiarW; i++)
    {
    for(int j=0; j<RozmiarK; j++)
        {
        elem[i][j]=0;
        }
    }
}

/*!
 * Konstruktor parametryczny dla macierzy.
 */
Macierz::Macierz(double elem0, double elem1, double elem2, double elem3)
{
elem[0][0]=elem0;
elem[0][1]=elem1;
elem[1][0]=elem2;
elem[1][1]=elem3;
}

bool Macierz::operator== (Macierz M)const
{
for(int i=0; i<RozmiarW; i++)
    {
    for(int j=0; j<RozmiarK; j++)
        {
        if((abs((*this)(i,j)-M(i,j)))>=MIN_ROZNICA)
        {return false;}
        }
    }
return true;
}

/*!
 * Metoda służąca do dodawania macierzy.
 * Argumenty:
 *    this - Pierwszy macierzowy składnik dodawania.
 *    M - Drugi macierzowy składnik dodawania.
 * Zwraca:
 *    Sume dwóch macierzy.
 */
Macierz Macierz::operator+ (Macierz M)const
{
Macierz Wynik;
for(int i=0; i<RozmiarW; i++)
    {
    for(int j=0; j<RozmiarK; j++)
        {
        Wynik(i,j) = (*this)(i,j) + M(i,j);
        }
    }
return Wynik;
}

/*!
 * Metoda służąca do odejmowania macierzy.
 * Argumenty:
 *    this - Pierwszy macierzowy składnik odejmowania.
 *    M - Drugi macierzowy składnik odejmowania.
 * Zwraca:
 *    Różnica dwóch macierzy.
 */
Macierz Macierz::operator- (Macierz M)const
{
Macierz Wynik;
for(int i=0; i<RozmiarW; i++)
    {
    for(int j=0; j<RozmiarK; j++)
        {
        Wynik(i,j) = (*this)(i,j) - M(i,j);
        }
    }
return Wynik;
}

/*!
 * Metoda służąca do mnożenia macierzy (o ile jest to algebraicznie możliwe).
 * Argumenty:
 *    this - Pierwszy macierzowy składnik mnożenia.
 *    M - Drugi macierzowy składnik mnożenia.
 * Zwraca:
 *    Iloczyn dwóch macierzy.
 */
Macierz Macierz::operator* (Macierz M)const
{
Macierz Wynik;
if(RozmiarK != RozmiarW)
    {
    throw std::runtime_error("Nie mozna mnozyc macierzy o takich wymiarach");
    }

int w,k;
for(int i=0; i<RozmiarW; i++)
    {
    for(int j=0; j<RozmiarK; j++)
        {
        Wynik(i,j)=0;
        w=k=0;
        while (w<RozmiarW && k<RozmiarK)
            {
            Wynik(i,j) += (*this)(i,k)*M(w,j);
            ++w;
            ++k;
            }
        }
    }
return Wynik;
}


/*!
 * Metoda służąca do mnożenia macierzy przez skalar.
 * Argumenty:
 *    this - Macierz.
 *    Liczba - Sklar.
 * Zwraca:
 *    Macierz, której każdy element został wymnożony przez skalar.
 */
Macierz Macierz::operator* (double Liczba)const
{
Macierz Wynik;

for(int i=0; i<RozmiarW; i++)
    {
    for(int j=0; j<RozmiarK; j++)
        {
        Wynik(i,j) = (*this)(i,j)*Liczba;
        }
    }
return Wynik;
}


/*!
 * Funkcja służąca do mnożenia macierzy przez skalar (Realizuje mnożenie w kolejności skalar*macierz).
 * Argumenty:
 *    M - Macierz.
 *    Liczba - Sklar.
 * Zwraca:
 *    Macierz, której każdy element został wymnożony przez skalar.
 */
Macierz operator* (double Liczba, Macierz M)
{
Macierz Wynik;
for(int i=0; i<M.RozmiarW; i++)
    {
    for(int j=0; j<M.RozmiarK; j++)
        {
        Wynik(i,j) = M(i,j)*Liczba;
        }
    }
return Wynik;
}


/*!
 * Funkcja sluzaca do generowania macierzy(2x2) obrotu o kąt alfa.
 * Argumenty:
 *    alfa - kat obrotu.
 * Zwraca:
 *    Macierz obrotu o kat alfa.
 */
Macierz MacierzObrotu(double alfa)
{
Macierz M;
M(0,0)=cos(alfa);
M(0,1)=-sin(alfa);
M(1,0)=sin(alfa);
M(1,1)=cos(alfa);
return M;
}

/*!
 * Metoda służąca do mnożenia macierzy przez wektor (O ile jest to algebraicznie możliwe).
 * Argumenty:
 *    this - Macierz.
 *    W - Wektor.
 * Zwraca:
 *    Wektor, będący wynikiem mnożenia macierzy przez wektor.
 */
Wektor2D Macierz::operator* (Wektor2D W)const
{
Wektor2D Wynik;

if(RozmiarK != W.Rozmiar)
    {
    throw std::runtime_error("Nie mozna mnozyc macierzy o takich wymiarach");
    }

int w,k;
for(int i=0; i<RozmiarW; i++)
    {
    for(int j=0; j<RozmiarK; j++)
        {
        Wynik[i]=0;
        w=k=0;
        while (w<RozmiarW && k<RozmiarK)
            {
            Wynik[i] += (*this)(i,k)*W[w];
            ++w;
            ++k;
            }
        }
    }
return Wynik;
}

/*!
 * Funkcja służąca do przekazywania macierzy do danego strumienia.
 * Argumenty:
 *    Strm - Strumień, na który macierz ma zostać wypisany.
 *    MAc - Macierz, ktora ma zostać wypisana.
 * Zwraca:
 *    Strumień na który macierz została wypisana.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
for(int i=0; i<Mac.RozmiarW; i++)
    {
    for(int j=0; j<Mac.RozmiarK; j++)
        {
        Strm << Mac(i,j);
        if(j!=(Mac.RozmiarK-1))
            {
            Strm << " ";
            }
        }
    Strm << std::endl;
    }
return Strm;
}


double Macierz::Wyznacznik()const
{
    int i,j,k;
    double mnoznik;
    double Macierz[WYMIAR][WYMIAR];        //Macierz pomocnicza
    double Wyznacznik=1;

    if(this->RozmiarW!=this->RozmiarK)
        {
            throw std::runtime_error("Blad: Macierz nie jest kwadratowa");
            exit(0);
        }

    for(i=0; i<this->RozmiarW; i++)
        {
        for(j=0; j<this->RozmiarK; j++)
            {
            Macierz[i][j]= (*this)(i,j);
            }    
        }

    for(i=0; i<this->RozmiarW; i++)
        {
            if(Macierz[i][i]==0)
                {
                    throw std::runtime_error("Blad: Macierz osobliwa");
                    exit(0);
                }
            for(j=i+1; j<this->RozmiarW; j++)
                {
                    mnoznik = Macierz[j][i]/Macierz[i][i];
                    for(k=0;k<this->RozmiarW;k++)
			            {
			  		    Macierz[j][k] = Macierz[j][k] - mnoznik*Macierz[i][k];
			            }
                }
        }

       for(i=0; i<this->RozmiarW; i++)
        {
        Wyznacznik *= Macierz[i][i];    
        }     
    return Wyznacznik;
}



