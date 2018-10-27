#ifndef RSA_BLOCKS_H
#define RSA_BLOCKS_H

#include "Func.h"

class RSA_BLOCKS
{
    public:
        RSA_BLOCKS(int);
        RSA_BLOCKS(int,ZZ,ZZ);
        string Encriptado(string);
        string Desencriptado(string);
        ZZ Resto_Chino(ZZ);
        ///void menu();
        string rellenado_0(int);
        string rellenado_aux(ZZ,ZZ);
    private:
        string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        ZZ p;
        ZZ q;
        ZZ n;
        ZZ phi;
        ZZ e;
        ZZ d;
        ZZ e_pub;
        ZZ n_pub;

        int tam;
        void generar_claves(int);
};

#endif // RSA_BLOCKS_H
