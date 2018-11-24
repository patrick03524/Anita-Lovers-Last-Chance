#ifndef RC4_H
#define RC4_H
#include "Func.h"

class RC4{
private:

public:
    RC4();
    int S[256];
    int K[256];
    void swap_int(int,int);
	vector<int> Generar_Aleatorio(int);
	vector<int> Numero_Grande();
};

#endif // RC4_H
