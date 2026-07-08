/*Desarrolla un programa que solicite 10 numeros enteros
se pide :
- Calcular la suma total
- Determinar el numeros mayor
- Determinar el numero menor
- Calcular el promedio
- Hacer uso de arreglos
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f, g, h, i, j, suma;
    int *pa = &a, *pb = &b, *pc = &c, *pd = &d, *pe = &e, *pf = &f, *pg = &g, *ph = &h, *pi = &i, *pj = &j *ps = &suma;

    cout << "Digite el valor de a : "; cin >> *pa;
    cout << "Digite el valor de b : " ; cin >> *pb;
    cout << "Digite el valor de c : " ; cin >> *pc;
    cout << "Digite el valor de d : "; cin >> *pd;
    cout << "Digite el valor de e : " ; cin >> *pe;
    cout << "Digite el valor de f : " ; cin >> *pf;
    cout << "Digite el valor de g : "; cin >> *pg;
    cout << "Digite el valor de h : " ; cin >> *ph;
    cout << "Digite el valor de i : " ; cin >> *pi;
    cout << "Digite el valor de j : " ; cin >> *pj;


    *ps = *pa + *pb + *pc;

    cout << "La suma es: " << suma << endl;
    return 0;
}