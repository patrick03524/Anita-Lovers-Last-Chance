#include "Func.h"

int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
int generar_Aleatorio(){

    int numero_aleatorio=rand();  ///Numeros entre 1-zptrme
    return numero_aleatorio;
}
int generar_Aleatorio_Max(int max){

    int numero_aleatorio=rand()%(max);  ///Numeros entre 1-1000
    return numero_aleatorio;
}
