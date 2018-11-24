#ifndef GAMAL_H
#define GAMAL_H
#include "LFSR.h"

class Gamal
{
    public:
        Gamal(int);
        Gamal(ZZ,ZZ,ZZ,ZZ,ZZ);
        string Encriptado(string);
        string Desencriptado(string);
    private:
        ZZ p;
        ZZ e_1;
        ZZ e_2;
        ZZ d;
        ZZ r;
        int n_bits;
        ///string alfabeto = "0123456789abcdefghijklmnopqrstuvwxyz.,ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        void generar_claves(int);
        void impr_claves();
};

#endif // GAMAL_H
