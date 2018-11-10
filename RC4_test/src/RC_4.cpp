#include "RC_4.h"

RC_4::RC_4(){

}
int modulo_int(int a, int b){
    int q=a/b;
    int r=a-q*b;
    if(r<0){
        r+=b;
    }
    return r;
}
void RC_4::swap_int(int a, int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int RC_4::Generar_Aleatorio(int n_bits){
    int const numero_de_bits_necesarios=9;
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
    bitset<numero_de_bits_necesarios> index;
    for(int n=0;n<n_bits;n++){
        i=modulo_int(i+1,n_bits);
        f=modulo_int(f+S[n],n_bits);
        swap_int(S[i],S[f]);
        index=modulo_int(S[i]+S[f],n_bits);
    }
    int aleatorio;
    for(int m=0;m<numero_de_bits_necesarios;m++){
        cout<<index[m]<<" ";
    }
    cout<<endl;
    int temp=0;
    if(index[0]==1){
        temp=temp+256;
    }
    if(index[1]==1){
        temp=temp+128;
    }
    if(index[2]==1){
        temp=temp+64;
    }
    if(index[3]==1){
        temp=temp+32;
    }
    if(index[4]==1){
        temp=temp+16;
    }
    if(index[5]==1){
        temp=temp+8;
    }
    if(index[6]==1){
        temp=temp+4;
    }
    if(index[7]==1){
        temp=temp+2;
    }
    if(index[8]==1){
        temp=temp+1;
    }
    aleatorio=temp;
    cout<<aleatorio<<endl;
    return aleatorio;
}
/*
string bitset_string(bitset<8> n){
    stringstream b;
    b<<n;
    return b.str();
}

ZZ string_number(string s) {
	long len = s.size()-1;
	int i=0, x;
	ZZ num;
	for(x=len; x>=0; x--) {
		if(s[x]=='1') {
			num += power_ZZ(2,i);
		}
		i++;
	}
	return num;
}

string PasoA(int bits) {//TRNG Semilla
	string s;
	int t;
	for(int i=0; i<bits/8; i++) {
        t = (rand()+(unsigned)time(NULL))%256;
        bitset<8> nb(t);
        s+=bitset_string(nb);
	}
    return s;
}

string PasoB(string s) {
	int t1, t2, r, r1;
	string r2;
	string ns = s;
	for(int i=0; i<s.size()-1; i++) {
		t1 = s[i]-48;
		t2 = s[i+1]-48;
		r = t1 + t2;
		r1 = mod1(r,2);
		r2 = r1+'0';
		ns+=r2;
	}
	return ns;
}

string PasoCDE(string s) {
	int len = s.size();
	int q = len-3;
	int p = (rand()+(unsigned)time(NULL))%q+2;
	int v = len-p;
	string s1 = s.substr(0,p);
	string s2 = s.substr(p,v);

	int len1 = s1.size();
	int len2 = s2.size();
	string s3;
	string s4;
	for(int i=0; i<len1; i++) {s3+="-";}
	for(int i=0; i<len2; i++) {s4+="-";}
	int l1 = len1-1;
	int l2 = len2-1;
	int t1, t2, r1, r2, a1, a2;
	string b1, b2;

	for(int i=0; i<l1; i++) {
		s3[i]=s1[i+1];
	}
	t1 = s[p]-48;
	r1 = t1+1;
	a1 = mod1(r1,2);
	b1 = a1+'0';
	s3[l1] = b1[0];

	for(int i=1; i<l2; i++) {
		s4[i] = s2[i-1];
	}
	t2 = s[len-1]-48;
	r2 = t2+1;
	a2 = mod1(r2,2);
	b2 = a2+'0';
	s4[0] = b2[0];
	s4[l2] = '1';

	string ns = s3+s4;
	return ns;
}

ZZ LFSR(int bits) {
	int rb = bits/2;
	string s = PasoA(rb);
	string s1 = PasoB(s);
	string s2 = PasoCDE(s1);
	ZZ Random = string_number(s2);
	return Random;
}*/
