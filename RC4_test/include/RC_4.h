#ifndef RC_4_H
#define RC_4_H
#include <vector>
#include <bitset>
#include <iostream>
///#include "Functions"

using namespace std;

class RC_4{
private:

public:
    RC_4();
    int S[256];
    int K[256];


    void swap_int(int,int);
	int Generar_Aleatorio(int);
};

#endif // RC_4_H
