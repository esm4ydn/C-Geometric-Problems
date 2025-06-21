#ifndef UCGEN_H
#define UCGEN_H

#include "Nokta.h"
#include "DogruParcasi.h"

class Ucgen {
private:
    Nokta nokta1;
    Nokta nokta2;
    Nokta nokta3;

public:
    Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3);

    void setNokta1(const Nokta& nokta);
    Nokta getNokta1() const;
    void setNokta2(const Nokta& nokta);
    Nokta getNokta2() const;
    void setNokta3(const Nokta& nokta);
    Nokta getNokta3() const;

    std::string toString() const;
    double alan() const;
    double cevre() const;
    double* acilar() const;
};

#endif // UCGEN_H
