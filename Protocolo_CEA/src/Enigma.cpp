#include "../include/Enigma.h"

Enigma::Enigma(string clave, int a, int b, int c)
{
    n_rotores_pe=3;
    pos_inicial=clave;
    tam = alfabeto.size();
    r1=elegir_rotores(a);
    r2=elegir_rotores(b);
    r3=elegir_rotores(c);
    int n_1 = generar_Aleatorio_Max(tam);
    int n_2 = generar_Aleatorio_Max(tam);
    while(n_2==n_1){
        n_2 = generar_Aleatorio_Max(alfabeto.size());
    }
    sk += alfabeto[n_1];
    sk += alfabeto[n_2];
    ///cout <<"SWEBADA: "<<sk<<endl;
    l1 = limite[a-1];
    l2 = limite[b-1];
    l3 = limite[c-1];
}
Enigma::Enigma(string clave,int a, int b, int c, string override, string n)
{
    n_rotores_pe=3;
    pos_inicial=clave;
    tam = alfabeto.size();
    sk = n;
    r1=elegir_rotores(a);
    r2=elegir_rotores(b);
    r3=elegir_rotores(c);
    l1=override[0];
    l2=override[1];
    l3=override[2];
}
string Enigma::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;

    int desplaza1, desplaza2, desplaza3;
    desplaza1 = alfabeto.find(pos_inicial[0]);
    desplaza2 = alfabeto.find(pos_inicial[1]);
    desplaza3 = alfabeto.find(pos_inicial[2]);

    for(int i=0;i<mensaje_original.length();i++){
        if(mensaje_original[i]==sk[0]){
            mensaje_original[i]=sk[1];
        }
        if(mensaje_original[i]==sk[1]){
            mensaje_original[i]=sk[0];
        }
        string tmp;
        int tmp2;
        desplaza3=modulo(desplaza1+1,tam);
        if(desplaza3==alfabeto.find(l3)){
            desplaza2 = modulo(desplaza2+1,tam);
        }
        if(desplaza2==modulo(alfabeto.find(l2)-1,tam)){
            desplaza2 = modulo(desplaza2+1,tam);
            desplaza1 = modulo(desplaza1+1,tam);
        }
        tmp=r3[modulo(alfabeto.find(mensaje_original[i])+desplaza3,tam)];
        tmp=r2[modulo(alfabeto.find(tmp)-desplaza3+desplaza2,tam)];
        tmp=r1[modulo(alfabeto.find(tmp)-desplaza2+desplaza1,tam)];

        tmp=reflect[modulo(alfabeto.find(tmp)-desplaza1,tam)];

        tmp2=modulo(r1.find(alfabeto[modulo(alfabeto.find(tmp)+desplaza1,tam)])-desplaza1,tam);
        tmp2=modulo(r2.find(alfabeto[modulo(tmp2+desplaza2,tam)])-desplaza2,tam);
        tmp=alfabeto[modulo(r3.find(alfabeto[modulo(tmp2+desplaza3,tam)])-desplaza3,tam)];
        mensaje_encriptado+=tmp;
        if(mensaje_encriptado[i]==sk[0]){
            mensaje_encriptado[i]=sk[1];
        }
        if(mensaje_encriptado[i]==sk[1]){
            mensaje_encriptado[i]=sk[1];
        }
    }
    return mensaje_encriptado;
}
string Enigma::Desencriptado(string mensaje_encriptado)
{
    string mensaje_desencriptado;
    int desplaza1, desplaza2, desplaza3;
    desplaza1 = alfabeto.find(pos_inicial[0]);
    desplaza2 = alfabeto.find(pos_inicial[1]);
    desplaza3 = alfabeto.find(pos_inicial[2]);
    for(int i=0;i<mensaje_encriptado.length();i++){
        if(mensaje_encriptado[i]==sk[0]){
            mensaje_encriptado[i]=sk[1];
        }
        if(mensaje_encriptado[i]==sk[1]){
            mensaje_encriptado[i]=sk[0];
        }
        string tmp;
        int tmp2;
        desplaza3=modulo(desplaza1+1,tam);
        if(desplaza3==alfabeto.find(l3)){
            desplaza2 = modulo(desplaza2+1,tam);
        }
        if(desplaza2==modulo(alfabeto.find(l2)-1,tam)){
            desplaza2 = modulo(desplaza2+1,tam);
            desplaza1 = modulo(desplaza1+1,tam);
        }
        tmp=r3[modulo(alfabeto.find(mensaje_encriptado[i])+desplaza3,tam)];
        tmp=r2[modulo(alfabeto.find(tmp)-desplaza3+desplaza2,tam)];
        tmp=r1[modulo(alfabeto.find(tmp)-desplaza2+desplaza1,tam)];

        tmp=reflect[modulo(alfabeto.find(tmp)-desplaza1,tam)];

        tmp2=modulo(r1.find(alfabeto[modulo(alfabeto.find(tmp)+desplaza1,tam)])-desplaza1,tam);
        tmp2=modulo(r2.find(alfabeto[modulo(tmp2+desplaza2,tam)])-desplaza2,tam);
        tmp=alfabeto[modulo(r3.find(alfabeto[modulo(tmp2+desplaza3,tam)])-desplaza3,tam)];
        mensaje_desencriptado+=tmp;
        if(mensaje_desencriptado[i]==sk[0]){
            mensaje_desencriptado[i]=sk[1];
        }
        if(mensaje_desencriptado[i]==sk[1]){
            mensaje_desencriptado[i]=sk[1];
        }
    }
    return mensaje_desencriptado;
}
string Enigma::elegir_rotores(int a)
{
    switch(a){
    case 1:
        return rotor_i;
    case 2:
        return rotor_i2;
    case 3:
        return rotor_i3;
    case 4:
        return rotor_i4;
    case 5:
        return rotor_i5;
    case 6:
        return rotor_i6;
    case 7:
        return rotor_i7;
    case 8:
        return rotor_i8;
    }
}
/*string mensaje_encriptado;

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
    return mensaje_encriptado;*/
/*string cuack =alfabeto[rotor_i3.find(i)];


        ///cuack = modulo(cuack+1,alfabeto.size());
        string cuack2 = rotor_i3.find(mensaje_original[cuack]);

        ///cuack2 = modulo(cuack2-1,alfabeto.size());
        int cuack3 = rotor_i2.find(mensaje_original[cuack2]);

        ///int cuack4 = rotor_i.find
        mensaje_encriptado+=alfabeto[cuack3];*/
