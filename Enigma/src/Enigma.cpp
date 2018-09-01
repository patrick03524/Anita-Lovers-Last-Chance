#include "Enigma.h"

Enigma::Enigma()
{
    n_rotores_pe=3;
    pos_inicial="AAA";
}
string Enigma::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;
    for(int i=0; i<mensaje_original.size(); i++){
        /*string cuack =alfabeto[rotor_i3.find(i)];


        ///cuack = modulo(cuack+1,alfabeto.size());
        string cuack2 = rotor_i3.find(mensaje_original[cuack]);

        ///cuack2 = modulo(cuack2-1,alfabeto.size());
        int cuack3 = rotor_i2.find(mensaje_original[cuack2]);

        ///int cuack4 = rotor_i.find
        mensaje_encriptado+=alfabeto[cuack3];*/
        int cuack = alfabeto.find(mensaje_original[i]);
        string s_cuack;
        s_cuack += rotor_i3[cuack];
        cout <<s_cuack<<endl;
        int cuack2 = alfabeto.find(s_cuack);
        string s_cuack2;
        s_cuack2 += rotor_i2[cuack2];
        cout <<s_cuack2<<endl;
        int cuack3 = alfabeto.find(s_cuack2);
        string s_cuack3;
        s_cuack3 += rotor_i[cuack3];
        cout <<s_cuack3<<endl;
        int cuack4 = reflect.find(s_cuack3);

        string s_cuack4;
        s_cuack4 +=alfabeto[cuack4];
        cout <<s_cuack4<<endl;
        int cuack5 = rotor_i.find(s_cuack4);
        string s_cuack5;
        s_cuack5 +=alfabeto[cuack5];
        cout <<s_cuack5<<endl;
        int cuack6 = rotor_i2.find(s_cuack5);
        string s_cuack6;
        s_cuack6 += alfabeto[cuack6];
        cout <<s_cuack6<<endl;
        int cuack7 = rotor_i3.find(s_cuack6);
        string s_cuack7;
        s_cuack7 += alfabeto[cuack7];
        cout <<s_cuack7<<endl;

        mensaje_encriptado+=alfabeto[cuack7];
    }
    return mensaje_encriptado;
}
string Enigma::Desencriptado(string mensaje_encriptado)
{
    return "ella";
}
