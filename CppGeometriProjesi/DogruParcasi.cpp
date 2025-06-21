#include "DogruParcasi.h"
#include <iostream>
#include <cmath>
#include "Nokta.h"

using namespace std;

DogruParcasi::DogruParcasi() : p1(Nokta()), p2(Nokta()) {}

DogruParcasi::DogruParcasi(const Nokta& nokta1, const Nokta& nokta2) : p1(nokta1), p2(nokta2) {}

DogruParcasi::DogruParcasi(const DogruParcasi& other) : p1(other.p1), p2(other.p2) {}

DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    double x2 = ortaNokta.getX() + uzunluk * cos(egim);
    double y2 = ortaNokta.getY() + uzunluk * sin(egim);
    p1.set(ortaNokta.getX() - (x2 - ortaNokta.getX()), ortaNokta.getY() - (y2 - ortaNokta.getY()));
    p2.set(x2, y2);
}

void DogruParcasi::setP1(const Nokta& nokta) { p1 = nokta; }
Nokta DogruParcasi::getP1() const { return p1; }
void DogruParcasi::setP2(const Nokta& nokta) { p2 = nokta; }
Nokta DogruParcasi::getP2() const { return p2; }

double DogruParcasi::uzunluk() const {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    return sqrt(dx * dx + dy * dy);
}

Nokta DogruParcasi::kesisimNoktasi(const Nokta& nokta) const {
    double egim_p1_p2 = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    double egim_dik = -1 / egim_p1_p2;
    double c_dik = nokta.getY() - egim_dik * nokta.getX();
    double kesisim_x = (c_dik - 0) / (egim_p1_p2 - egim_dik);
    double kesisim_y = egim_p1_p2 * kesisim_x;
    return Nokta(kesisim_x, kesisim_y);
}

Nokta DogruParcasi::ortaNokta() const {
    double ortaX = (p1.getX() + p2.getX()) / 2.0;
    double ortaY = (p1.getY() + p2.getY()) / 2.0;
    return Nokta(ortaX, ortaY);
}

string DogruParcasi::toString() const {
    return "P1: " + p1.toString() + ", P2: " + p2.toString();
}

void DogruParcasi::yazdir() const {
    cout << toString() << endl;
}
