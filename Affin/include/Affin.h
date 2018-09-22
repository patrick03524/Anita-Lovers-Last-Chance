#ifndef AFFIN_H
#define AFFIN_H
#include "Func.h"

class Affin
{
    public:
        Affin();
        Affin(int, int);
        string Affin_Encriptacion(string);
        string Affin_Desencriptacion(string);
    private:
        string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
        int clave_a;
        int clave_b;
        int inversa_a;
        int tam;
};

#endif // AFFIN_H
