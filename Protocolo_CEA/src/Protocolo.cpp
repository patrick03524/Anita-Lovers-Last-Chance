#include "Protocolo.h"

Protocolo::Protocolo()
{
    tam = alfabeto.length();
    ///cout <<"TE ESTOY BUSCANDO PARA EXPLOTAR CONTIGO"<<endl;
}
Protocolo::Protocolo(string cod_alumno1,string nombr_iniciales,string apell_iniciales,string steckers_apell)
{
    tam = alfabeto.length();
    e1=cod_alumno1;
    e2=nombr_iniciales;
    e3=apell_iniciales;
    e4=steckers_apell;
    alea_cesar = 10+generar_Aleatorio_Max(tam);
}
string Protocolo::leer_txt()
{
    string mensaje;
    Fichero_Entrada.open("Fichero_Salida.txt");
    getline(Fichero_Entrada,mensaje);
    cout <<mensaje<<endl;
    Fichero_Entrada.close();
    return mensaje;
}
void Protocolo::escribir_txt(string mensaje_a_ingresar)
{
    Fichero_Salida.open("Fichero_Salida.txt");
    Fichero_Salida << mensaje_a_ingresar;
    Fichero_Salida.close();
    cout <<"c mamo"<<endl;
}
string Protocolo::Encriptado(string mensaje_original)
{
    ///string e1 = "123";
    string mensaje_encriptado;
    string temp;
    ///string enigma_temp1,enigma_temp2,enigma_temp3;
    string enigma_temp1,affin_temp1;
    int clave_affin_a;
    int clave_affin_b;
    stringstream i1(e1.substr(0,1));
    stringstream i2(e1.substr(1,1));
    stringstream i3(e1.substr(2,1));
    int a = 0;
    int b = 0;
    int c = 0;
    i1>>a;
    i2>>b;
    i3>>c;

    temp+=e2;
    temp+=e3;
    temp+=e4;
    temp+=mensaje_original;
    ///Cesar
    Cesar cesar(alea_cesar);
    temp=cesar.Encriptado(temp);


    Enigma enigma(temp.substr(0,3),a,b,c,temp.substr(3,3),temp.substr(6,2));
    enigma_temp1 = temp.substr(8,100);
    enigma_temp1=enigma.Encriptado(enigma_temp1);
    Affin affin;
    clave_affin_a = affin.get_clave_a();
    clave_affin_b = affin.get_clave_b();
    affin_temp1 = affin.Affin_Encriptacion(enigma_temp1);



    return mensaje_encriptado;
}
string Protocolo::Desencriptado(string mensaje_Encriptado)
{
    string exit,s;
    ifstream infile;
	infile.open ("Fichero_Salida.txt");
    while(!infile.eof())
    {
        getline(infile,s);
        exit+=s;
    }
    cout <<exit<<endl;
	infile.close();
	string affin;
	affin = exit.substr(0,4);
	cout <<affin<<endl;
	string enigma;
	enigma = exit.substr(4,11);
	cout <<enigma<<endl;
	string cesar;
	cesar = exit.substr(15,2);
	cout <<cesar<<endl;
	string mensaje;
	mensaje = exit.substr(17,100);
	cout <<mensaje<<endl;
	cout <<mensaje.size()<<endl;

    return "ELLA";
}
