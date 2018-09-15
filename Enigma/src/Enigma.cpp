#include "Enigma.h"

Enigma::Enigma(string clave)
{
    n_rotores_pe=3;
    pos_inicial=clave;
    tam = alfabeto.size();
    int n_1 = generar_Aleatorio_Max(alfabeto.size());
    int n_2 = generar_Aleatorio_Max(alfabeto.size());
    if(n_2==n_1){
        n_2 = generar_Aleatorio_Max(alfabeto.size());
    }
    sk += alfabeto[n_1];
    sk += alfabeto[n_2];
    cout <<"SWEBADA: "<<sk<<endl;
}
Enigma::Enigma(string clave,string nepe)
{
    n_rotores_pe=3;
    pos_inicial=clave;
    tam = alfabeto.size();
    sk = nepe;
    cout <<"SWEBADA: "<<sk<<endl;
}
string Enigma::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;

    int desplaza1, desplaza2, desplaza3;
    desplaza3 = alfabeto.find(pos_inicial[0]);
    desplaza2 = alfabeto.find(pos_inicial[1]);
    desplaza1 = alfabeto.find(pos_inicial[2]);


    for(int i=0; i<mensaje_original.size(); i++){
        ///int ducky_one = desplaza1+i+1;
        desplaza1 = modulo(desplaza1+1,tam);

        if(mensaje_original[i]==sk[0]){
            mensaje_original[i]=sk[1];
        }
        if(mensaje_original[i]==sk[1]){
            mensaje_original[i]=sk[0];
        }
        if(alfabeto[desplaza1]==alfabeto[modulo(alfabeto.find('V')+1,tam)]){
            desplaza2=modulo(desplaza2+1,tam);
        }
        if(alfabeto[desplaza1]==alfabeto[modulo(alfabeto.find('V')+1,tam)] && alfabeto[desplaza2]==alfabeto[modulo(alfabeto.find('E')+1,tam)]){
            desplaza3 = modulo(desplaza3+1,tam);
        }

        int cuack = modulo(alfabeto.find(mensaje_original[i])+desplaza1,tam);
        string s_cuack;
        s_cuack += rotor_i3[cuack];
        ///cout <<s_cuack<<endl;
        int cuack2 = modulo(alfabeto.find(s_cuack)+desplaza2-desplaza1,tam);            ///-i-1
        string s_cuack2;
        s_cuack2 += rotor_i2[cuack2];
        ///cout <<s_cuack2<<endl;
        int cuack3 = modulo(alfabeto.find(s_cuack2)+desplaza3-desplaza2,tam);
        string s_cuack3;
        s_cuack3 += rotor_i[cuack3];
        ///cout <<s_cuack3<<endl;
        int cuack4 = modulo(reflect.find(s_cuack3)-desplaza3,tam);

        ///cuack4 = modulo(cuack4+desplaza3,tam);

        string s_cuack4;
        s_cuack4 +=alfabeto[modulo(cuack4,tam)];
        ///cout <<s_cuack4<<endl;
        int cuack5 = modulo(rotor_i.find(s_cuack4)-desplaza3+desplaza2,tam);                  ///+desplaza2
        string s_cuack5;
        s_cuack5 +=alfabeto[cuack5];
        ///cout <<s_cuack5<<endl;
        int cuack6 = modulo(rotor_i2.find(s_cuack5)-desplaza2+desplaza1,tam);   ///+i+1
        string s_cuack6;
        s_cuack6 += alfabeto[cuack6];
        ///cout <<s_cuack6<<endl;
        int cuack7 = modulo(rotor_i3.find(s_cuack6)-desplaza1,tam);             ///-i-1
        string s_cuack7;
        s_cuack7 += alfabeto[cuack7];
        ///cout <<s_cuack7<<endl;

        mensaje_encriptado+=alfabeto[cuack7];
    }
    return mensaje_encriptado;
}
string Enigma::Desencriptado(string mensaje_encriptado)
{
    string mensaje_desencriptado;
    int desplaza1, desplaza2, desplaza3;
    desplaza3 = alfabeto.find(pos_inicial[0]);
    desplaza2 = alfabeto.find(pos_inicial[1]);
    desplaza1 = alfabeto.find(pos_inicial[2]);


    for(int i=0; i<mensaje_encriptado.size(); i++){
        ///int ducky_one = desplaza1+i+1;
        desplaza1 = modulo(desplaza1+1,tam);
        if(alfabeto[desplaza1]==alfabeto[modulo(alfabeto.find('V')+1,tam)]){
            desplaza2=modulo(desplaza2+1,tam);
        }
        if(alfabeto[desplaza1]==alfabeto[modulo(alfabeto.find('V')+1,tam)] && alfabeto[desplaza2]==alfabeto[modulo(alfabeto.find('E')+1,tam)]){
            desplaza3 = modulo(desplaza3+1,tam);
        }

        int cuack = modulo(alfabeto.find(mensaje_encriptado[i])+desplaza1,tam);
        string s_cuack;
        s_cuack += rotor_i3[cuack];
        ///cout <<s_cuack<<endl;
        int cuack2 = modulo(alfabeto.find(s_cuack)+desplaza2-desplaza1,tam);
        string s_cuack2;
        s_cuack2 += rotor_i2[cuack2];
        ///cout <<s_cuack2<<endl;
        int cuack3 = modulo(alfabeto.find(s_cuack2)+desplaza3-desplaza2,tam);
        string s_cuack3;
        s_cuack3 += rotor_i[cuack3];
        ///cout <<s_cuack3<<endl;
        int cuack4 = modulo(reflect.find(s_cuack3)-desplaza3,tam);

        string s_cuack4;
        s_cuack4 +=alfabeto[modulo(cuack4,tam)];
        ///cout <<s_cuack4<<endl;
        int cuack5 = modulo(rotor_i.find(s_cuack4)-desplaza3+desplaza2,tam);
        string s_cuack5;
        s_cuack5 +=alfabeto[cuack5];
        ///cout <<s_cuack5<<endl;
        int cuack6 = modulo(rotor_i2.find(s_cuack5)-desplaza2+desplaza1,tam);
        string s_cuack6;
        s_cuack6 += alfabeto[cuack6];
        ///cout <<s_cuack6<<endl;
        int cuack7 = modulo(rotor_i3.find(s_cuack6)-desplaza1,tam);
        string s_cuack7;
        s_cuack7 += alfabeto[cuack7];
        ///cout <<s_cuack7<<endl;

        mensaje_desencriptado+=alfabeto[cuack7];
    }
    return mensaje_desencriptado;
}
/*string cuack =alfabeto[rotor_i3.find(i)];


        ///cuack = modulo(cuack+1,alfabeto.size());
        string cuack2 = rotor_i3.find(mensaje_original[cuack]);

        ///cuack2 = modulo(cuack2-1,alfabeto.size());
        int cuack3 = rotor_i2.find(mensaje_original[cuack2]);

        ///int cuack4 = rotor_i.find
        mensaje_encriptado+=alfabeto[cuack3];*/
