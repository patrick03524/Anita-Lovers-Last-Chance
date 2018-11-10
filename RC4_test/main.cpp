#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <bitset>
#include <string>
#include <NTL/ZZ.h>
#include "RC_4.h"

using namespace std;
using namespace NTL;


int main()
{
    cout << "Hello world!" << endl;
    RC_4 cuack;
    cuack.Generar_Aleatorio(8);
    return 0;
}
