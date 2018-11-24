#include "Gamal.h"

int main()
{
    srand(time(NULL));
    /*void LFSR::Paso_A(int numero_de_bits, vector<int> numero_grande, short int op, int n_particiones){
        int n=numero_de_bits;
        int n_t=n/10;
        vector<int> seed;
        for(int i=0;i<n_t;i++){
            seed.push_back(numero_grande[i]);
        }
        switch(op){
            case 1:
                cout<<"Izquierda-Izquierda"<<endl;
                break;
            case 2:
                cout<<"Derecha-Derecha"<<endl;
                break;
            case 3:
                cout<<"Izquierda-Derecha"<<endl;
                break;
            case 4:
                cout<<"Derecha-Izquierda"<<endl;
                break;
        }
    }*/
    /*vector<int> lamp;
    lamp.push_back(8);
    lamp.push_back(3);
    lamp.push_back(1);
    vector<int> bih;
    bih.push_back(0);
    bih.push_back(1);
    bih.push_back(1);
    bih.push_back(0);
    LFSR cuack(8,bih,lamp);
    cuack.fill_seed();
    cout<<rand()%8<<endl;
    cout<<rand()%8<<endl;
    cout<<rand()%8<<endl;
    cout<<rand()%8<<endl;
    cout<<rand()%8<<endl;*/
    /*string a, b, c;
    cout << "e1: ";
    cin >> a;
    cout << "e2: ";
    cin >> b;
    cout << "p: ";
    cin >> c;

    Gamal Prueba(stringTozz(a), stringTozz(b), stringTozz(c));*/
    Gamal Animal(ZZ(2),ZZ(7),ZZ(29),ZZ(12),ZZ(5));
    string mensaje="ILIKEMATH";
    cout<<Animal.Encriptado(mensaje)<<endl;
    return 0;

}
