#include "../tests/doctest/doctest.h"
#include "Macierz2x2.hh"

#define PI 3.1415926535

//TEST MACIERZY

TEST_CASE("Test Macierz - Konstruktor bezparametryczny"){                       
    Macierz x;

    CHECK(((x(0,0)==0)&&(x(0,1)==0)&&(x(1,0)==0)&&(x(1,1)==0)));
}

TEST_CASE("Test Macierz - Konstruktor parametryczny"){                       
    Macierz x(1,3,4.5,6);

    CHECK(((x(0,0)==1)&&(x(0,1)==3)&&(x(1,0)==4.5)&&(x(1,1)==6)));
}

TEST_CASE("Test Macierz - porownanie 1"){  //Rownosc                             
    Macierz x(1,2,3,4), y(1,2,3,4);

    CHECK(x==y);
}

TEST_CASE("Test Macierz - porownanie 2"){  //Rownosc                             
    Macierz x(1,2.23,3.234,-4.0978), y(1,2.23,3.234,-4.0978);

    CHECK(x==y);
}

TEST_CASE("Test Macierz - porownanie 3"){  //Minimalna nierownosc                            
Macierz x(1,2,3,0.0001), y(1,2,3,0.0009);

    CHECK(x==y);
}

TEST_CASE("Test Macierz - porownanie 4"){  //Nierownosc                          
    Macierz x(2,2,2,7), y(2,2,2,5);

    CHECK(!(x==y));
}

  TEST_CASE("Test Macierz - dodawanie 1"){                          
    Macierz x(1,2,3,4), y(3,2,1,0), z(4,4,4,4);

    CHECK((x+y)==z);
}

TEST_CASE("Test Macierz - dodawanie 2"){                          
    Macierz x(1.75,2.68,3.72,8.21), y(3.24,2.79,2.23,7.74), z(4.99,5.47,5.95,15.95);

    CHECK((x+y)==z);
}

TEST_CASE("Test Macierz - odejmowanie 1"){                          
    Macierz x(1,2,6,2), y(3,2,7,1), z(-2,0,-1,1);

    CHECK((x-y)==z);
}

TEST_CASE("Test Macierz - odejmowanie 2"){                          
    Macierz x(1.75,2.68,2.24,-7.81), y(3.24,0.79,0.5,3.21), z(-1.49,1.89,1.74,-11.02);

    CHECK((x-y)==z);
}

TEST_CASE("Test Macierz - mnozenie przez skalar 1"){                          
    Macierz x(4,9,1,-6), y(12,27,3,-18);

    CHECK((3*x)==y);
}

TEST_CASE("Test Macierz - mnozenie przez skalar 2"){                          
    Macierz x(4,9,1,-6), y(12,27,3,-18);

    CHECK((x*3)==y);
}

TEST_CASE("Test Macierz - mnozenie przez skalar3"){                          
    Macierz x(4.25,9.2,-1.75,0.2), y(12.75,27.6,-5.250,0.6);

    CHECK((3*x)==y);
}

TEST_CASE("Test Macierz - mnozenie przez skalar 4"){                          
    Macierz x(4.25,9.2,-1.75,0.2), y(12.75,27.6,-5.250,0.6);

    CHECK((x*3)==y);
}

TEST_CASE("Test Macierz - mnozenie macierzy przez wektor"){                          
    Macierz x(1,2,3,4);
    Wektor2D y(2,4), z(10,22);

    CHECK((x*y)==z);
}

TEST_CASE("Test Macierz - mnozenie macierzy przez wektor"){                          
    Macierz x(1.75,-2.2,3.33,4);
    Wektor2D y(2.7,-4.1), z(13.745,-7.409);

    CHECK((x*y)==z);
}

TEST_CASE("Test Macierz - indeksowanie 1"){                          
    Macierz x(4,9,1,6);

    CHECK((x(0,0)==4 && x(0,1)==9 && x(1,0)==1 && x(1,1)==6));
}

TEST_CASE("Test Macierz - indeksowanie 2"){                          
    Macierz x;

    x(0,0)=4;
    x(0,1)=9;
    x(1,0)=1;
    x(1,1)=6;

    CHECK((x(0,0)==4 && x(0,1)==9 && x(1,0)==1 && x(1,1)==6));
}

TEST_CASE("Test Macierz - indeksowanie 3"){                          
    Macierz x(4,9,1,6);

    WARN_THROWS(x(1,3));
}

TEST_CASE("Test Macierz - indeksowanie 4"){                          
    Macierz x(4,9,1,6);

    WARN_THROWS(x(3,1));
}

TEST_CASE("Test Macierz - indeksowanie 5"){                          
    Macierz x;

    WARN_THROWS(x(1,3)=5);
}

TEST_CASE("Test Macierz - indeksowanie 6"){                          
    Macierz x;

    WARN_THROWS(x(2,1)=5);
}

TEST_CASE("Test Macierz - macierz obortu 1"){ //90
    Macierz x, y(0,-1,1,0);

    x=MacierzObrotu(PI/2);

    CHECK(x==y);
}

TEST_CASE("Test Macierz - macierz obortu 1"){//-60
    Macierz x, y(0.5,sqrt(3)/2,-sqrt(3)/2,0.5);

    x=MacierzObrotu(-PI/3);

    CHECK(x==y);
}