#include <iostream>
#include <string.h> //für strlen
#include <stdio.h> //für getchar
#include <math.h> //für pow

using namespace std;

int powa(int b, int p) {
    int erg = 1;
    for (p; p>0; p--) {
        erg = erg * b;
    }
    return erg;
}

float ctf(char str[]){
    int i = 0; int len = strlen(str)-1; float x = 0.0; float y = 0.0; int c;
                                                                                            cout<<endl<<"Variante 1"<<endl<<"  i: -"<<"\t\tc: -"<<"\t\tx: "<<x<<endl;
    while(!(str[i+1] == '.' xor str[i+1] == ',')) {
        c = str[i]-'0';
        x = (x + c)*10;                                                                     cout<<"  i: "<<i<<"\t\tc: "<<c<<"\t\tx: "<<x<<endl;
        i++;
    }
    c = str[i]-'0';
    x = x + c;                                                                              cout<<"  i: "<<i<<"\t\tc: "<<c<<"\t\tx: "<<x<<endl;
    i=i+2; //Komma überspringen
    while(len>=i) {
        c = str[len]-'0';
        y = (y + c)/10;                                                                     cout<<"len: "<<len<<"\t\tc: "<<c<<"\t\ty: "<<y<<endl;
        len--;
    }                                                                                       cout<<">> x: "<<x<<" -> y: "<<y<<" -> = "<<x+y<<endl;
    return x+y;
}

float ctff(char str[]){
    int p = 0; float x = 0.0; int i = 0; int c;
    while(!(str[p+1] == '.' xor str[p+1] == ',')){
        p++;
    }                                                                                       cout<<endl<<"Variante 2"<<endl<<"  i: -"<<"\t\tp: "<<p<<"\t\tc: -"<<"\t\tx: "<<x<<endl;
    while(i<strlen(str)) {
        if (str[i] == '.' || str[i] == ',') {
            i++;
        }
        c = str[i]-'0';
        x = x + (c*(powa(10,p)));                                                            cout<<"  i: "<<i<<"\t\tp: "<<p<<"\t\tc: "<<c<<"\t\tx: "<<x<<endl;
        i++;
        p--;
    }
    return x;
}



int main()
{
    char str9[101], c;
    int i, k;
    float ctf1, ctf2;
    bool boo;

    cout<<"Fehler in Gleitkommazahleingabe erkennen"<<endl<<endl;
    do{
        boo = true;

        cout<<"Geben Sie eine Gleitkommazahl ein: ";
        for(int f=0; f<101; f++){
            c = getchar();
            if(c=='\n'){
                str9[f] = '\0'; break;
            }
            str9[f] = c;
        }

        if (strlen(str9) == 0) {
            boo = false;
        }
        else {
            i = 0; k = 0;
            while (i < strlen(str9)) {
                c = str9[i];
                if (!((c >= '0' && c <= '9') || c == '.' || c == ',')) {
                    boo = false; break;
                }
                if (c == '.' || c == ',') {
                    k++;
                }
                i++;
            }
            if (k!=1 || str9[0] == '.' || str9[0] == ',') {
                boo = false;
            }
        }

        cout<<endl<<endl<<"Ihre Eingabe lautete: ";
        if (boo == true) {
            ctf1 = ctf(str9);
            ctf2 = ctff(str9);
            cout<<endl<<"> Variante 1 (hinten beginnend) <"<<endl<<ctf1<<endl<<"> Variante 2 ( vorne beginnend) <"<<endl<<ctf2<<endl;
        }
        else {
            cout<<str9<<endl<<"Dies ist keine gueltige Gleitkommazahl."<<endl<<"Bitte versuchen Sie es erneut."<<endl<<endl<<endl<<endl;
        }
    }while(boo == false);
}
