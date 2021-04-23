#include "../tests/doctest/doctest.h"
#include "Wektor2D.hh"

//TEST WEKTORA

TEST_CASE("Test Wektor - Konstruktor bezparametryczny"){                       
    Wektor2D x;

    CHECK(((x[0]==0)&&(x[1]==0)));
}

TEST_CASE("Test Wektor - Konstruktor parametryczny"){                       
    Wektor2D x(7,8);

    CHECK(((x[0]==7)&&(x[1]==8)));
}

TEST_CASE("Test Wektor - porownanie 1"){  //Rownosc                             
    Wektor2D x(1,2), y(1,2);

    CHECK(x==y);
}

TEST_CASE("Test Wektor - porownanie 2"){  //Rownosc                             
    Wektor2D x(1.54,2), y(1.54,2);

    CHECK(x==y);
}

TEST_CASE("Test Wektor - porownanie 3"){  //Minimalna nierownosc                            
    Wektor2D x(1.5432,2), y(1.5439,2);

    CHECK(x==y);
}

TEST_CASE("Test Wektor - porownanie 4"){  //Nierownosc                          
    Wektor2D x(2,2), y(1,3);

    CHECK(!(x==y));
}

TEST_CASE("Test Wektor - porownanie 5"){  //Nierownosc                           
    Wektor2D x(1.543,2), y(1.544,2);

    CHECK(!(x==y));
}

TEST_CASE("Test Wektor - dodawanie 1"){                          
    Wektor2D x(1,2), y(3,2), z(4,4);

    CHECK((x+y)==z);
}

TEST_CASE("Test Wektor - dodawanie 2"){                          
    Wektor2D x(1.75,2.68), y(3.24,2.79), z(4.99,5.47);

    CHECK((x+y)==z);
}

TEST_CASE("Test Wektor - dodawanie 3"){                          
    Wektor2D x(1.7512,2.6864), y(3.2432,2.7923), z(4.995,5.479);

    CHECK((x+y)==z);
}

TEST_CASE("Test Wektor - odejmowanie 1"){                          
    Wektor2D x(1,2), y(3,2), z(-2,0);

    CHECK((x-y)==z);
}

TEST_CASE("Test Wektor - odejmowanie 2"){                          
    Wektor2D x(1.75,2.68), y(3.24,0.79), z(-1.49,1.89);

    CHECK((x-y)==z);
}

TEST_CASE("Test Wektor - odejmowanie 3"){                          
    Wektor2D x(1.7512,2.6864), y(3.2437,2.7923), z(-1.4926, -0.106);

    CHECK((x-y)==z);
}

TEST_CASE("Test Wektor - mnozenie przez skalar 1"){                          
    Wektor2D x(4,9), y(12,27);

    CHECK((3*x)==y);
}

TEST_CASE("Test Wektor - mnozenie przez skalar 2"){                          
    Wektor2D x(4,9), y(12,27);

    CHECK((x*3)==y);
}

TEST_CASE("Test Wektor - mnozenie przez skalar3"){                          
    Wektor2D x(4.25,9.2), y(12.75,27.6);

    CHECK((3*x)==y);
}

TEST_CASE("Test Wektor - mnozenie przez skalar 4"){                          
    Wektor2D x(4.25,9.2), y(12.75,27.6);

    CHECK((x*3)==y);
}

TEST_CASE("Test Wektor - wypisywanie na strumien"){                          
    Wektor2D x(4.27,-6.32);

    std::ostringstream out;

    out << x;
    CHECK("4.27 -6.32" == out.str());
}

TEST_CASE("Test Wektor - wypisywanie na strumien"){  //Zaokraglenia                        
    Wektor2D x(2.0/3.0,1);

    std::ostringstream out;

    out << x;
    CHECK("0.666667 1" == out.str());
}

TEST_CASE("Test Wektor - wczytywanie ze strumienia"){                          
    Wektor2D x;

    std::ostringstream out;
    std::istringstream in("3 -11");
    in >> x;
    out << x;
    
    CHECK("3 -11" == out.str());
}

TEST_CASE("Test Wektor - indeksowanie 1"){                          
    Wektor2D x(4,9);

    CHECK((x[0]==4 && x[1]==9));
}

TEST_CASE("Test Wektor - indeksowanie 2"){                          
    Wektor2D x;

    x[0]=4;
    x[1]=9;

    CHECK((x[0]==4 && x[1]==9));
}

TEST_CASE("Test Wektor - indeksowanie 3"){                          
    Wektor2D x(4,9);

    WARN_THROWS(x[3]);
}

TEST_CASE("Test Wektor - indeksowanie 4"){                          
    Wektor2D x;

    WARN_THROWS(x[3]=5);
}