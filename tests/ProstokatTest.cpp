#include "../tests/doctest/doctest.h"
#include "Prostokat.hh"

TEST_CASE("Test Prostokat - Konstruktor bezparametryczny"){                       
    Prostokat x;

    CHECK(((x[0]==Wektor2D(0,0)) && (x[1]==Wektor2D(0,0)) && (x[2]==Wektor2D(0,0)) && (x[3]==Wektor2D(0,0))));
}

TEST_CASE("Test Prostokat - Konstruktor parametryczny"){                       
    Prostokat x({1,7},{7,7},{7,5},{1,5});

    CHECK(((x[0]==Wektor2D(1,7)) && (x[1]==Wektor2D(7,7)) && (x[2]==Wektor2D(7,5)) && (x[3]==Wektor2D(1,5))));
}

TEST_CASE("Test Prostokat - indeksowanie 1"){                          
    Prostokat x({1,2},{3,4},{5,6},{7,8});

    CHECK((x[0]==Wektor2D(1,2) && x[1]==Wektor2D(3,4) && x[2]==Wektor2D(5,6) && x[3]==Wektor2D(7,8)));
}

TEST_CASE("Test Prostokat - indeksowanie 2"){                          
    Prostokat x;

    x[0]={1,2};
    x[1]={3,4};
    x[2]={5,6};
    x[3]={7,8};

    CHECK((x[0]==Wektor2D(1,2) && x[1]==Wektor2D(3,4) && x[2]==Wektor2D(5,6) && x[3]==Wektor2D(7,8)));
}

TEST_CASE("Test Prostokat - indeksowanie 3"){ //Zly indeks                         
    Prostokat x;

    WARN_THROWS(x[4]);
}

TEST_CASE("Test Prostokat - indeksowanie 3"){ //Zly indeks                         
    Prostokat x;

    WARN_THROWS(x[4]={1,2});
}

TEST_CASE("Test Prostokat - porownanie 1"){ //Rownosc                         
    Prostokat x,y;

    x[0]={1,2};

    y[0]={1,2};

    CHECK(x==y);
}

TEST_CASE("Test Prostokat - porownanie 2"){ //Minimalna nierownosc                        
    Prostokat x,y;

    x[0]={1.0001,2};

    y[0]={1,2};

    CHECK(x==y);
}

TEST_CASE("Test Prostokat - porownanie 3"){ //Nierownosc                       
    Prostokat x,y;

    x[0]={3,2};

    y[0]={1,2};

    CHECK(!(x==y));
}

TEST_CASE("Test Prostokat - porownanie 3"){ //Mala nierownosc przekraczajaca granice                      
    Prostokat x,y;

    x[0]={1.0011,2};

    y[0]={1,2};

    CHECK(!(x==y));
}

TEST_CASE("Test Prostokat - translacja 2"){  //Wartosci dodatnie                    
    Prostokat x({1,7},{7,7},{7,5},{1,5});

    x.Translacja({2,1});

    Prostokat y({3,8},{9,8},{9,6},{3,6});

    CHECK(x==y);
}

TEST_CASE("Test Prostokat - translacja 2"){  //Wartosci ujemne                    
    Prostokat x({1,7},{7,7},{7,5},{1,5});

    x.Translacja({-2,-3});

    Prostokat y({-1,4},{5,4},{5,2},{-1,2});

    CHECK(x==y);
}

TEST_CASE("Test Prostokat - obrot 1"){  //Kat dodatni 90                 
    Prostokat x({1,7},{7,7},{7,5},{1,5});

    x.Obrot(90);

    Prostokat y({-7,1},{-7,7},{-5,7},{-5,1});

    CHECK(x==y);
}

TEST_CASE("Test Prostokat - obrot 2"){  //Kat ujemny -90                   
    Prostokat x({1,7},{7,7},{7,5},{1,5});

    x.Obrot(-90);

    Prostokat y({7,-1},{7,-7},{5,-7},{5,-1});

    CHECK(x==y);
}
