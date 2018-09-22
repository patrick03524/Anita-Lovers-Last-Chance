#include "Protocolo.h"

int main()
{
    cout << "Protoculo!" << endl;
    Protocolo culo;
    /*culo.leer_txt();
    culo.escribir_txt("TE ESTOY LLAMANDO PARA EXPLOTAR CONTIGO");
    culo.leer_txt();*/
    Enigma e("ABC",1,2,3,"RFW","GH");
    string wea = e.Desencriptado("RXATTSFKVJANRFYNUEIFNOBFYSPVAQACJSF");
    cout <<wea<<endl;



    return 0;
}
