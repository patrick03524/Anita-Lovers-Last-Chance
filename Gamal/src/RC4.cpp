#include "RC4.h"

RC4::RC4(){

}
void RC4::swap_int(int a, int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
vector<int> RC4::Numero_Grande(){
    vector<int> numero,temp,temp1;
    cout<<endl;
    while(numero.size()<=1024){
        temp=Generar_Aleatorio(1024);
        temp1=temp;
        cout<<"TEMP: ";
        for(int i=0;i<8;i++){
            cout<<temp1[i]<<" ";
            numero.push_back(temp1[i]);
        }
        cout<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<"NUMERO: ";
    for(int i=0;i<1024;i++){
        cout<<numero[i]<<" ";
    }
    return numero;
}
vector<int> RC4::Generar_Aleatorio(int n_bits){
    vector<int> total;
    int K[n_bits],S[n_bits];
    /*Image img;
    if(img.loadFromFile("image.jpg")) {
        //cout << "Image is loaded"
    } else {
        cout << "couldn't load image";
    }
    Vector2u imageSize = img.getSize();
    int xSize = imageSize.x;
    int ySize = imageSize.y;
    Color tempColor;
    int red,green,blue;
    vector<int> cuack;
    for(int i1 = 0; i1 < ySize ; i1++) {
        for(int j = 0; j < xSize; j++) {
            tempColor = img.getPixel(j, i1);
            red = tempColor.r;
            green = tempColor.g;
            blue = tempColor.b;
            cuack.push_back(green);
        }
        /// cout<<"RED: "<<red<<" GREEN: "<<green<<" BLUE: "<<blue<<endl;
    }
    for(int i=0;i<n_bits;i++){
        S[i]=cuack[i];
    }*/
    for(int i=0;i<n_bits;i++){
        S[i]=i;
    }
    int f=0;
    for(int i=0;i<n_bits;i++){
        f=modulo_int(f+S[i]+K[i],n_bits);
        swap_int(S[i],K[i]);
    }
    int i=0;
    int const numero_de_bits_necesarios=8;
    bitset<numero_de_bits_necesarios> index;
    for(int n=0;n<n_bits;n++){
        i=modulo_int(i+1,n_bits);
        f=modulo_int(f+S[n],n_bits);
        swap_int(S[i],S[f]);
        index=modulo_int(S[i]+S[f],n_bits);
    }
    cout<<"INDEX: ";
    for(int m=0;m<8;m++){
        total.push_back(index[m]);
        cout<<total[m]<<" ";
    }
    cout<<endl;
    return total;
}
/*
vector<int> RC_4::Generar_Aleatorio(int n_bits){
    vector<int> total;
    int K[n_bits],S[n_bits];
    for(int i=0;i<n_bits;i++){
        S[i]=i;
    }
    int f=0;
    for(int i=0;i<n_bits;i++){
        f=modulo_int(f+S[i]+K[i],n_bits);
        swap_int(S[i],K[i]);
    }
    int i=0;
    int const numero_de_bits_necesarios=8;
    bitset<numero_de_bits_necesarios> index;
    for(int n=0;n<n_bits;n++){
        i=modulo_int(i+1,n_bits);
        f=modulo_int(f+S[n],n_bits);
        swap_int(S[i],S[f]);
        index=modulo_int(S[i]+S[f],n_bits);
    }
    cout<<"INDEX: ";
    for(int m=0;m<8;m++){
        total.push_back(index[m]);
        cout<<total[m]<<" ";
    }
    cout<<endl;
    return total;
}*/
