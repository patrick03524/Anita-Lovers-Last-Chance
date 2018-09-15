#include "Enigma.h"

int main()
{
    srand(time(NULL));
    string ducky, clave, randonm;
    cout <<"Según la cantidad de Rotores que actualmente hay ingrese las posiciones iniciales de los rotores"<<endl;
    cout <<"Ingrese las primeras posiciones: ";
    cin >> clave;
    Enigma e(clave);
    string m = e.Encriptado("GATOS");
    cout <<"ENCRIPTA3: "<<m<<endl;
    string d = e.Desencriptado(m);
    cout <<"DESCIFRA3: "<<d<<endl;

    return 0;
}
