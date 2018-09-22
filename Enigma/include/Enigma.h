#ifndef ENIGMA_H
#define ENIGMA_H
#include "Func.h"

class Enigma
{
    public:
        Enigma(string,int,int,int);
        Enigma(string,int,int,int,string,string);
        string Encriptado(string);
        string Desencriptado(string);
        string elegir_rotores(int);

        string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string rotor_i = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        string rotor_i2 = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        string rotor_i3 = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        string rotor_i4 = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        string rotor_i5 = "VZBRGITYUPSDNHLXAWMJQOFECK";
        string rotor_i6 = "JPGVOUMFYQBENHZRDKASXLICTW";
        string rotor_i7 = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        string rotor_i8 = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        string reflect = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

    private:
        int n_rotores_pe;
        string pos_inicial;
        int tam;
        string sk;
        string r1;
        string r2;
        string r3;
        string l1;
        string l2;
        string l3;
        string limite="RFWKAANA";

};

#endif // ENIGMA_H
