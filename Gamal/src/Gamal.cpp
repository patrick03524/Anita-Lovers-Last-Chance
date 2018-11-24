#include "Gamal.h"

Gamal::Gamal(int cuack_bits)
{
    n_bits = cuack_bits;
    generar_claves(cuack_bits);
    impr_claves();
}
Gamal::Gamal(ZZ e1,ZZ e2,ZZ n_pub,ZZ d_pes,ZZ r_pes)
{
    e_1 = e1;
    e_2 = e2;
    p = n_pub;
    d = d_pes;
    r = r_pes;
}
string Gamal::Encriptado(string mensaje_original)
{
    ///string mensaje_encriptado;
    ZZ C_Mac_mani_1 = exponenciacion_modular(e_1,r,p);
    ZZ K_Granny_Tranny_M = exponenciacion_modular(e_2,r,p);

    string hidra_str;
    for(int i = 0; i < mensaje_original.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(mensaje_original[i]));
        string nume = zz_To_String(to_ZZ(alfabeto.find(alfabeto[alfabeto.size()-1])));
        int num_pos = zz_To_String(pos).size();
        if(num_pos < nume.size()){
            hidra_str += "0";
            num_pos++;
        }
        hidra_str += zz_To_String(pos);
    }
    cout<<"H: "<<hidra_str<<endl;
    ZZ temp = to_ZZ(hidra_str.size());
    ZZ N_1 = to_ZZ(zz_To_String(p).size()-1);
    while(modulo(temp,N_1) != 0){
        int pos = alfabeto.find("W");
        hidra_str += zz_To_String(to_ZZ(pos));
        temp = to_ZZ(hidra_str.size());
    }
    cout<<"H2: "<<hidra_str<<endl;
    string dig_2;
    for(int j = 0; j < hidra_str.size();){
        int temp = 0;
        string temp_1;
        while(temp < to_int(N_1)){ Gamal Animal(ZZ(2),ZZ(7),ZZ(29),ZZ(12),ZZ(5));
            temp_1 += hidra_str[j];
            ++temp;
            ++j;
        }
        ///cout<<"B: "<<temp_1<<endl;
        ZZ temp_2 = modulo(string_To_ZZ(temp_1)*K_Granny_Tranny_M,p);
        ///cout<<"C: "<<temp_2<<endl;
        ZZ cont_num = to_ZZ(zz_To_String(temp_2).size());
        while(cont_num < zz_To_String(p).size()){
            dig_2 += "0";
            ++cont_num;
        }
        dig_2 += zz_To_String(temp_2);
    }
    int tama = zz_To_String(p).size()-zz_To_String(C_Mac_mani_1).size();
    string mensaje_encriptado(tama,'0');
    mensaje_encriptado += zz_To_String(C_Mac_mani_1);
    mensaje_encriptado += dig_2;
    return mensaje_encriptado;
}
string Gamal::Desencriptado(string mensaje_encriptado)
{
    string C = mensaje_encriptado.substr(0,zz_To_String(p).size());
    mensaje_encriptado = mensaje_encriptado.substr(zz_To_String(p).size());
    ZZ Km = exponenciacion_modular(string_To_ZZ(C),d,p);
    string resultado;
    int num = (zz_To_String(p).size());
    for(int i = 0; i < mensaje_encriptado.size();){
        int a = 0;
        string temp;
        while(a < num){
            a++;
            temp += mensaje_encriptado[i];
            ++i;
        }
        ZZ valor = modulo(string_To_ZZ(temp)*inversa(Km,p),p);
        int x = zz_To_String(valor).size();
        while(x < zz_To_String(p).size()-1){
            resultado += "0";
            ++x;
        }
        resultado += zz_To_String(valor);
    }
    string dig = zz_To_String(to_ZZ(alfabeto.size()-1));
    string mensaje_desencriptado;
    for(int j = 0; j < resultado.size();){
        int s = 0;
        string tempi;
        while(s < dig.size()){
            tempi += resultado[j];
            ++s;
            ++j;
        }
        mensaje_desencriptado += alfabeto[to_int(string_To_ZZ(tempi))];
    }
    while(mensaje_desencriptado[mensaje_desencriptado.size()-1] == 'w'){
        mensaje_desencriptado.erase(mensaje_desencriptado.size()-1);
    }
    return mensaje_desencriptado;
}
void Gamal::generar_claves(int cuack_bits)
{
    p = generar_Aleatorio_Prime(cuack_bits);
    e_1 = Find_Gen(p);
    d = ZZ(2)+generar_Aleatorio_Max(p - ZZ(4));
    e_2 = exponenciacion_modular(e_1,d,p);
    ///Clave publica
    r = ZZ(2)+generar_Aleatorio_Max(p - ZZ(4));
}
void Gamal::impr_claves()
{
    cout<<"P: "<<p<<endl;
    cout<<"E1: "<<e_1<<endl;
    cout<<"E2: "<<e_2<<endl;
    cout<<"R: "<<r<<endl;
    cout<<"D: "<<d<<endl;
}
