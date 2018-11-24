#ifndef RC4_H
#define RC4_H
#include "Func.h"

class RC4{
public:
    RC4();
    vector<int> Generar_Aleatorio(int);
	vector<int> Numero_Grande();
    void swap_int(int,int);
    int S[256];
    int K[256];
};

#endif // RC4_H
