#include "DogruParcasi.h"
#include "Daire.h"
#include "Ucgen.h"
#include <locale>
#include "Nokta.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Turkish");

    cout << "NOKTA SINIFI İÇİN TEST ÇIKTILARI:" << endl;
    Nokta n1;
    Nokta n2(5);
    Nokta n3(3, 4);
    Nokta n4(n3);
    Nokta n5(n3, 1, -1);

    n1.yazdir(); n2.yazdir(); n3.yazdir(); n4.yazdir(); n5.yazdir();

    n1.setX(10); n1.yazdir();
    n2.set(25, 30); n2.yazdir();

    cout << "\nDOGRUPARCASI SINIFI İÇİN TEST SONUÇLARI:" << endl;
    DogruParcasi dp(n1, n3);
    DogruParcasi dp2(dp);
    DogruParcasi dp3(n3, 10, 45);

    dp.yazdir(); dp2.yazdir(); dp3.yazdir();

    dp2.setP1(Nokta());
    dp2.yazdir();
    cout << dp.uzunluk() << endl;
    cout << dp.ortaNokta().toString() << endl;

    cout << "\nDAIRE SINIFI İÇİN TEST SONUÇLARI:" << endl;
    Daire d1(Nokta(0, 0), 5), d2(d1), d3(d2, 3);
    d1.yazdir(); cout << d1.alan() << ", " << d1.cevre() << endl;
    d2.yazdir(); cout << d2.alan() << ", " << d2.cevre() << endl;
    d3.yazdir(); cout << d3.alan() << ", " << d3.cevre() << endl;

    cout << d1.kesisim(d2) << endl;
    cout << d1.kesisim(d3) << endl;

    cout << "\nUCGEN SINIFI İÇİN TEST SONUÇLARI:" << endl;
    Ucgen ucgen(Nokta(0, 0), Nokta(4, 0), Nokta(0, 3));
    cout << ucgen.toString() << endl;
    cout << ucgen.alan() << endl;
    cout << ucgen.cevre() << endl;
    double* acilar = ucgen.acilar();
    cout << acilar[0] << ", " << acilar[1] << ", " << acilar[2] << endl;
    delete[] acilar;

    return 0;
}
