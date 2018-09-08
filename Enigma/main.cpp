#include "Enigma.h"

int main()
{
    string ducky, clave;
    cout <<"Según la cantidad de Rotores que actualmente hay ingrese las posiciones iniciales de los rotores"<<endl;
    cout <<"Ingrese las primeras posiciones: ";
    cin >> clave;
    Enigma e(clave);
    string m = e.Encriptado("GATOS");
    cout <<m<<endl;
    return 0;
}
