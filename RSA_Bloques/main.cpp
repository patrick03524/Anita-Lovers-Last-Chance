#include "RSA_BLOCKS.h"

int main()
{
    /*cout << "-----------------------------------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "------------------BIENVENIDO-------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "----------------------RSA----------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "----------------------CON----------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "--------------------BLOQUES--------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    system("pause");
    system("cls");
    unsigned short int op;
    cout << "Ingrese la opcion que quiera realizar" <<endl;
    cout << "1.- Instanciar y Asignar Claves" <<endl;
    cout << "2.- Cifrado" <<endl;
    cout << "3.- Descifrado" <<endl;
    cout << "4.- Salir" <<endl;
    cout << "Opcion: ";
    cin >> op;
    while(op!=4){
        switch(op)
        {
        case 1:
            ///instanciar xd
        case 2:
            ///cifrado
            break;
        case 3:
            ///Descifrado"
            break;
        default:
            cout << "jajajaja nel prro "<<endl;
            break;
        }
        cout << "Ingrese la opcion otra ves: ";
        cin >> op;
    }
    system("cls");
    cout <<"Eligio la opcion 4"<<endl;
    cout <<"Ta luegorl"<<endl;*/
    RSA_BLOCKS cuack(8,ZZ(3),ZZ(1003));
    string damn = cuack.Encriptado("come here");
    string damn2 = cuack.Desencriptado(damn);
    cout <<"DES"<<damn2<<endl;
    return 0;
}
