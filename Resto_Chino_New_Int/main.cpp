#include <iostream>
using namespace std;
int arInv[20];
int modulo(int a , int mod1){
	int q = a / mod1;
	int r = a - (mod1*q);

	if (r < 0){
		r = mod1 + r;
	}
	return r;
}


void inversa_modular(int a, int mod, int iter){
	for (int i = 1; i<mod; i++){
		int b = a * i;
		if (modulo(b,mod) == 1){
			arInv[iter] = i;
			break;
		}
	}
}

int main() {

	///cout <<"it's a desastah :v"<<endl;
	int cantSen;
	int n1,mod,modTotal=1;
	cout << "Ingrese la cantidad de sentencias : ";
	cin >> cantSen;
	while (cantSen <= 0){
		cout <<"No se puede realizar el Teorema"<<endl;
		cout << "Ingresar denuevo : "<<endl;
		cin >> cantSen;
	}
	int arNum[20];
	int arMod[20];
	int arms[20];
	for (int i = 0; i < cantSen; i++){
		cout << "Ingresar el número ";
		cin >> n1;
		arNum[i]=n1;
		cout << "Ingresar el módulo de ambos numeros: ";
		cin >> mod;
		while (mod <= 0){
			cout <<"No se puede realizar el Modulo"<<endl;
			cout << "Ingresar denuevo el módulo : "<<endl;
			cin >> mod;
		}
		arMod[i]=mod;
	}
	if(cantSen == 1){
		cout <<"No es necesario el Teorema Chino"<<endl;
		cout << arNum[0] <<" mod "<<arMod[0]<<endl;
		cout << "La respuesta es "<<modulo(arNum[0],arMod[0])<<endl;
	}
	else{
		for (int i = 0; i < cantSen; i++){
			cout << "x = " <<arNum[i] <<" mod "<<arMod[i]<<endl;
			modTotal *= arMod[i];
			inversa_modular(arNum[i],arMod[i],i);
		}
		for (int i = 0; i < cantSen; i++){
			cout << "M"<<i+1<<" = "<<modTotal<<" / "<<arMod[i]<<" = "<<modTotal/arMod[i]<<endl;
			arms[i] = modTotal/arMod[i];
		}
		//cout << "M1 = "<<modTotal/m1<<endl;
		cout <<"x = ";
		int res = 0;
		for (int i = 0; i < cantSen; i++){
			cout <<arNum[i]<<" * "<<arms[i]<<" * "<<arInv[i]<<" + ";
			res += (arNum[i] * arms[i] * arInv[i]);
		}
		cout <<arNum[cantSen]<<" * "<<arms[cantSen]<<" * "<<arInv[cantSen]<<endl;
		res += (arNum[cantSen] * arms[cantSen] * arInv[cantSen]);
		cout <<res<<endl;;
		res = modulo(res,modTotal);
		cout << "El resultado es "<<res<<endl;

	}

	//cout <<"----- INVERSA -----"<<endl;
	//inversa_modular(n1,mod1);

	return 0;
}
