#include "Daire.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
#include "Nokta.h"

using namespace std;

Daire::Daire() : merkez(Nokta()), yaricap(0) {}

Daire::Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

Daire::Daire(const Daire& other) : merkez(other.merkez), yaricap(other.yaricap) {}

Daire::Daire(const Daire& other, double carpan) : merkez(other.merkez), yaricap(other.yaricap * carpan) {}

double Daire::alan() const {
    return M_PI * yaricap * yaricap;
}

double Daire::cevre() const {
    return 2 * M_PI * yaricap;
}

int Daire::kesisim(const Daire& diger) const {
    double merkez_mesafe = sqrt(pow((diger.merkez.getX() - merkez.getX()), 2) + pow((diger.merkez.getY() - merkez.getY()), 2));
    if (merkez_mesafe < abs(diger.yaricap - yaricap))
        return 0;
    else if (merkez_mesafe == abs(diger.yaricap - yaricap))
        return 1;
    else
        return 2;
}

string Daire::toString() const {
    return "Merkez: " + merkez.toString() + ", Yaricap: " + to_string(yaricap);
}

void Daire::yazdir() const {
    cout << toString() << endl;
}
