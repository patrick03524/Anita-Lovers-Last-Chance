#include "RSA_BLOCKS.h"

RSA_BLOCKS::RSA_BLOCKS(int bits)
{
    ///menu();
    ///numeros de (2^bits)/2 a (2^bits)-1
    generar_claves(bits);
    e_pub=e;
    n_pub=n;
    cout<<"E_DEL_MEN: "<<e_pub<<endl;
    cout<<"N_DEL_MEN: "<<n_pub<<endl;
}
RSA_BLOCKS::RSA_BLOCKS(int bits, ZZ e2, ZZ n2)
{
    generar_claves(bits);
    e_pub=e2;
    n_pub=n2;
}
RSA_BLOCKS::RSA_BLOCKS(ZZ p_1,ZZ q_1,ZZ e_1,ZZ d_1,ZZ e_2,ZZ n_2)
{
    p = p_1;
    q = q_1;
    e = e_1;
    d = d_1;
    n = p_1 * q_1;
    phi = (p-ZZ(1))*(q-ZZ(1));
    ///cout<<"PHI_: "<<phi<<endl;
    e_pub = e_2;
    n_pub = n_2;
    cout<<"P:"<<p<<endl;
    cout<<"Q:"<<q<<endl;
    cout<<"N: "<<n<<endl;
    cout<<"PHI: "<<phi<<endl;
    cout <<"E:"<<e<<endl;
    cout <<"D:"<<d<<endl;
    cout<<"E_DEL_MEN: "<<e_pub<<endl;
    cout<<"N_DEL_MEN: "<<n_pub<<endl;
}
void RSA_BLOCKS::generar_claves(int bits)
{
    ZZ min;
    min = (2^bits)/2;
    p=generar_Aleatorio_bits(bits);
    while(!ProbPrime(p) || p<min){
        p=generar_Aleatorio(bits);
        ///cout<<"NEL"<<endl;
    }
    cout<<"P:"<<p<<endl;
    q=generar_Aleatorio_bits(bits);
     while(!ProbPrime(q) || q<min){
        q=generar_Aleatorio(bits);
        ///cout<<"NEL"<<endl;
    }
    cout<<"Q:"<<q<<endl;
    n=p*q;
    cout<<"N: "<<n<<endl;
    phi=phi_euler(p,q);
    cout<<"PHI: "<<phi<<endl;
    e=generar_Aleatorio_Max(phi);
    while(euclides(e,phi)!=1){
        e=generar_Aleatorio_Max(phi);
    }
    cout <<"E:"<<e<<endl;
    tam=alfabeto.length();
    ///cout<<"TAM: "<<tam<<endl;
    d=inversa(e,phi);
    cout <<"D:"<<d<<endl;

}
ZZ RSA_BLOCKS::Resto_Chino(ZZ num){     ///algoritmo exponenciaci�n r�pida binaria � Teorema Chino del Resto
    ZZ dp = modulo(d,p-1);
    ZZ dq = modulo(d,q-1);
    ZZ D1 = exponenciacion_modular(num,dp,p);
    ZZ D2 = exponenciacion_modular(num,dq,q);
    ZZ P = p*q;
    ZZ P1 = P/p;        ///ZZ P1 = q;
    ZZ P2 = P/q;        ///ZZ P2 = p;
    ZZ Q1 = inversa(P1,p);
    ZZ Q2 = inversa(P2,q);
    ZZ resultado = modulo(D1 * P1 * Q1,P);
    resultado += modulo(D2 * P2 * Q2,P);
    resultado = modulo(resultado,P);
    return resultado;
}
string RSA_BLOCKS::rellenado_0(int a)
{
    string llenar = int_to_string(a);
    string treat_fill = int_to_string(alfabeto.size());
    while(llenar.size()<treat_fill.size()){
        llenar = '0' + llenar;       ///llenado al principio
    }
    return llenar;
}
string  RSA_BLOCKS::rellenado_aux(ZZ a, ZZ n_1)
{
    string llenar = zz_To_String(a);
    string treat_fill = zz_To_String(n_1);
    while(llenar.size()<treat_fill.size()){
        llenar = '0' + llenar;       ///llenado al principio
    }
    return llenar;
}
string RSA_BLOCKS::rellenado_aux_esp(ZZ a,ZZ n_1)
{
    string llenar = zz_To_String(a);
    string treat_fill = zz_To_String(n_1);
    while(llenar.size()<(treat_fill.size()-1)){
        llenar = '0' + llenar;       ///llenado al principio
    }
    return llenar;
}
string RSA_BLOCKS::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;
    string mensaje_1_paso,mensaje_2_paso,mensaje_3_paso;
    vector<string> bloques, k1, k2;
    string bleach1 = zz_To_String(n);
    string bleach2 = zz_To_String(n_pub);
    int bloques1 = bleach1.size();
    int bloques2 = bleach2.size();

    string temp1,temp2,temp3,temp4;
    ///int treat_num = zz_To_String(n).size()-1;
    for(unsigned int i=0; i<mensaje_original.size();i++){
        temp1+=rellenado_0(alfabeto.find(mensaje_original[i]));
    }
    cout <<temp1<<endl;
    while(modulo(ZZ(temp1.size()),ZZ(bloques2-1))!=0){
        temp1+=zz_To_String(ZZ(alfabeto.find('W')));
    }
    cout <<temp1<<endl;
    for(unsigned int i = 0; i<temp1.size();i++){
        temp2+=temp1[i];
        if(temp2.size()==bloques2-1){
            bloques.push_back(temp2);
            cout<<"B"<<i/5+1<<": "<<temp2<<endl;
            temp2 = "";
        }
    }
    cout<<temp1<<endl;
    for(unsigned int i = 0; i<bloques.size();i++){
        ZZ pos = exponenciacion_modular(string_To_ZZ(bloques[i]),e_pub,n_pub);
        mensaje_1_paso+= rellenado_aux(pos,n_pub);
    }
    cout<<"C: "<<mensaje_1_paso<<endl;
    for(unsigned int i = 0; i<mensaje_1_paso.size(); i++){
        temp3+=mensaje_1_paso[i];
        if(i==(mensaje_1_paso.size()-1)){
            for(unsigned int j = temp3.size(); j<bloques1-1;j++){
                temp3+=zz_To_String(ZZ(alfabeto.find('W')));
                k1.push_back(temp3.substr(0,bloques1-1));
                cout<<"B_AD: "<<temp3.substr(0,bloques1-1)<<endl;
                temp3="";
            }
        }
        if(temp3.size()==bloques1-1){
            k1.push_back(temp3);
            cout<<"B"<<i/5+1<<": "<<temp3<<endl;
            temp3="";
        }
    }
    for(unsigned int i = 0; i<k1.size();i++){
        ZZ pos = exponenciacion_modular(string_To_ZZ(k1[i]),d,n);
        mensaje_2_paso+=rellenado_aux(pos,n);
    }
    cout<<"R: "<<mensaje_2_paso<<endl;
    for(unsigned int i = 0; i<mensaje_2_paso.size(); i++){
        temp4+=mensaje_2_paso[i];
        if(i==mensaje_2_paso.size()-1){
            for(unsigned int j = temp4.size(); j<bloques2-1;j++){
                temp4+=zz_To_String(ZZ(alfabeto.find('W')));
                k2.push_back(temp4.substr(0,bloques2-1));
                cout<<"B_AD: "<<temp4.substr(0,bloques2-1)<<endl;
                temp4="";
            }
        }
        if(temp4.size()==bloques2-1){
            k2.push_back(temp4);
            cout<<"B"<<i/5+1<<": "<<temp4<<endl;
            temp4="";
        }
    }
    for(unsigned int i = 0; i<k2.size();i++){
        ZZ pos = exponenciacion_modular(string_To_ZZ(k2[i]),e_pub,n_pub);
        mensaje_3_paso+=rellenado_aux(pos,n_pub);
    }
    cout<<"F: "<<mensaje_3_paso<<endl;
    /*///R�BRICA
    for(unsigned int i = 0; i<mensaje_1_paso.size(); i++){
        temp3+=mensaje_1_paso[i];
        if(temp3.size()==bloques1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp3),d,n);
            mensaje_2_paso+=rellenado_aux(pos,n);
        }
        if(i==mensaje_1_paso.size()-1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp3),d,n);
            mensaje_2_paso+=rellenado_aux(pos,n);
        }
    }
    cout<<temp3<<endl;
    ///FIRMA DIGITAL

    for(unsigned int i = 0; i<mensaje_2_paso.size();i++){
        temp4+=mensaje_2_paso[i];
        if(temp4.size()==bloques2){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp4),e_pub,n_pub);
            mensaje_3_paso+=rellenado_aux(pos,n_pub);
        }
        if(i==mensaje_2_paso.size()-1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp4),e_pub,n_pub);
            mensaje_3_paso+=rellenado_aux(pos,n_pub);
        }
    }*/
    mensaje_encriptado = mensaje_3_paso;
    return mensaje_encriptado;
}
string RSA_BLOCKS::Desencriptado(string mensaje_encriptado)
{
    string mensaje_desencriptado;
    string mensaje_1_paso,mensaje_2_paso,mensaje_3_paso;
    vector<string> bloques, k1, k2;
    string bleach1 = zz_To_String(n);
    string bleach2 = zz_To_String(n_pub);
    int bloques1 = bleach1.size();
    int bloques2 = bleach2.size();
    string temp1,temp2,temp3,temp4;

    /*while(modulo(ZZ(mensaje_encriptado.size()),ZZ(bleach1.size()-1))!=0){
        temp1+=zz_To_String(ZZ(alfabeto.find('W')));
    }*/
    for(unsigned int i = 0; i<mensaje_encriptado.size();i++){
        temp1+=mensaje_encriptado[i];
        if(i==mensaje_encriptado.size()-1){
            for(unsigned int j = temp1.size(); j<bloques1-1;j++){
                temp1+=zz_To_String(ZZ(alfabeto.find('W')));
                k2.push_back(temp1.substr(0,bloques1));
            }
        }
        if(temp1.size()==bloques1){
            k2.push_back(temp1);
            cout<<"B"<<i/5+1<<": "<<temp1<<endl;
            temp1 = "";
        }
    }
    for(unsigned int i=0; i<k2.size();i++){
        ZZ pos = Resto_Chino(string_To_ZZ(k2[i]));
        ///mensaje_1_paso+= rellenado_aux(pos,n);
        mensaje_1_paso+= rellenado_aux_esp(pos,n);
    }
    cout<<"R-1: "<<mensaje_1_paso<<endl;
        for(unsigned int i = 0; i<mensaje_1_paso.size(); i++){
        temp2+=mensaje_1_paso[i];
        if(i==(mensaje_1_paso.size()-1)){
            for(unsigned int j = temp2.size(); j<bloques2-1;j++){
                temp2+=zz_To_String(ZZ(alfabeto.find('W')));
                k1.push_back(temp2.substr(0,bloques2));
                cout<<"B_AD: "<<temp2.substr(0,bloques2)<<endl;
                temp2="";
            }
        }
        if(temp2.size()==bloques2){
            k1.push_back(temp2);
            cout<<"B"<<i/5+1<<": "<<temp2<<endl;
            temp2="";
        }
    }
    for(unsigned int i = 0; i<k1.size();i++){
        ZZ pos = exponenciacion_modular(string_To_ZZ(k1[i]),e_pub,n_pub);
        ///mensaje_2_paso+=rellenado_aux(pos,n_pub);
        mensaje_2_paso+=rellenado_aux_esp(pos,n_pub);
    }
    cout<<"F-1: "<<mensaje_2_paso<<endl;
    for(unsigned int i = 0; i<mensaje_2_paso.size();i++){
        temp3+=mensaje_2_paso[i];
        if(i==mensaje_2_paso.size()-1){
            for(unsigned int j = temp3.size(); j<bloques1-1;j++){
                temp3+=zz_To_String(ZZ(alfabeto.find('W')));
                bloques.push_back(temp3.substr(0,bloques1));
                cout<<"B_AD: "<<temp3.substr(0,bloques1)<<endl;
                temp3="";
            }
        }
        if(temp3.size()==bloques1){
            bloques.push_back(temp3);
            cout<<"B"<<i/5+1<<": "<<temp3<<endl;
            temp3 = "";
        }
    }
    for(unsigned int i=0; i<bloques.size();i++){
        ZZ pos = Resto_Chino(string_To_ZZ(bloques[i]));
        ///mensaje_3_paso+= rellenado_aux(pos,n);
        mensaje_3_paso+= rellenado_aux_esp(pos,n);
    }
    cout<<mensaje_3_paso<<endl;
    for(unsigned int i = 0; i<mensaje_3_paso.size();i+=int_to_string(alfabeto.size()).size()){
        mensaje_desencriptado+=alfabeto[string_to_int(mensaje_3_paso.substr(i,int_to_string(alfabeto.size()).size()))];
    }
    return mensaje_desencriptado;
}
