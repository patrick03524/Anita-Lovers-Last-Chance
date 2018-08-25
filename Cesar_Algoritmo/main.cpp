#include "Cesar.h"

int main()
{
    int clave;
    string mensaje_prron;
    cout <<"Ingresa una clave ctm :";
    cin >> clave;
    cout <<" "<<endl;
    cout <<"Ingresa el mensaje prron : ";
    cin >> mensaje_prron;
    cout <<" "<<endl;
    Cesar Emisor(clave);
    string mensaje_encriptado = Emisor.Encriptado(mensaje_prron);
    cout <<mensaje_encriptado<<endl;
    Cesar Receptor(clave);
    string mensaje_desencriptado = Receptor.Desencriptado(mensaje_encriptado);
    cout <<mensaje_desencriptado<<endl;
    return 0;
}
