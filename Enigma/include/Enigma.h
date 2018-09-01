#ifndef ENIGMA_H
#define ENIGMA_H
#include "Func.h"

class Enigma
{
    public:
        Enigma();
        string Encriptado(string);
        string Desencriptado(string);

        string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string rotor_i = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        string rotor_i2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotor_i3 = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        string reflect = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

        int n_rotores_pe;
        string pos_inicial;

    private:
};

#endif // ENIGMA_H
