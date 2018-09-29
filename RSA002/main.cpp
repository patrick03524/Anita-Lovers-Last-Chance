#include "RSA.h"

int main()
{
    /*ZZ a;
    int bits =1024;
    GenPrime(a,bits);
    cout <<a<<endl;
    cout <<ProbPrime(a)<<endl;*/
    /*
    ZZ a;
    GenPrime(a,8);
    cout<<"ZZ:"<<a<<endl;
    int number = ZZ_to_int(a);
    cout <<"INT: "<<number<<endl;
    */
    /*ZZ a;
    ZZ b;
    ZZ c;
    a=generar_Aleatorio(16);
    b=generar_Aleatorio(8);
    c=generar_Aleatorio(16);
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
    cout <<modulo(a,b)<<endl;
    cout <<""<<exponenciacion_modular(a,ZZ(2),b)<<endl;*/
    string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
    int tam=alfabeto.length();
    string mensaje_original="t";
    string mensaje_encriptado,mensaje_desencriptado;
    /*ZZ a,b;
    int bits;
    cout<<"Ingresar la Clave publica del men"<<endl;
    cout<<"E: ";
    cin >> a;
    cout<<"N: ";
    cin >> b;
    cout<<"ingrese la cantidad de Bits: ";
    cin >> bits;
    RSA pichulin(bits);
    pichulin.ingresar_clave_pub(a,b);*/
    ZZ e;
    ZZ n;
    ZZ d;
    e=ZZ(587);
    n=ZZ(2809);
    d=ZZ(1047);
    /*RSA pichulin(16);
    encriptado=pichulin.Encriptado("Ellanuncateamo9");
    cout<<"E: "<<encriptado<<endl;
    desencriptado=pichulin.Desencriptado(encriptado);
    cout <<"D: "<<desencriptado<<endl;*/
    int allahu_akbar;
    for(unsigned int i=0;i<mensaje_original.length();i++){
        allahu_akbar=alfabeto.find(mensaje_original[i]);
        cout<<allahu_akbar<<endl;
        ZZ cuack = exponenciacion_modular(ZZ(allahu_akbar),e,n);
        cout<<cuack<<endl;
        cuack=modulo(cuack,ZZ(tam));
        cout<<cuack<<endl;
        allahu_akbar=ZZ_to_int(cuack);
        cout<<allahu_akbar<<endl;
        mensaje_encriptado+=alfabeto[allahu_akbar];
    }
    cout<<"Encriptado: "<<mensaje_encriptado<<endl;
    allahu_akbar=0;
    for(unsigned int i=0;i<mensaje_encriptado.length();i++){
        allahu_akbar=alfabeto.find(mensaje_encriptado[i]);
        cout<<allahu_akbar<<endl;
        ZZ cuack = exponenciacion_modular(ZZ(allahu_akbar),d,n);
        cout<<cuack<<endl;
        cuack=modulo(cuack,ZZ(tam));
        cout<<cuack<<endl;
        allahu_akbar=ZZ_to_int(cuack);
        cout<<allahu_akbar<<endl;
        mensaje_desencriptado+=alfabeto[allahu_akbar];
    }
    cout<<"Desencriptado: "<<mensaje_desencriptado<<endl;
    return 0;
}
