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

int cti(char str[]){
    int i = 0; int x = 0; int c;
                                                                                                    //cout<<endl<<"Variante 1"<<endl<<"i: -"<<"\t\tc: -"<<"\t\tx: "<<x<<endl;
    while(i<strlen(str)-1) {
        c = str[i]-'0';
        x = (x + c)*10;                                                                             //cout<<"i: "<<i<<"\t\tc: "<<c<<"\t\tx: "<<x<<endl;
        i++;
    }
    c = str[i]-'0';
    x = x + c;                                                                                      //cout<<"i: "<<i<<"\t\tc: "<<c<<"\t\tx: "<<x<<endl;
    return x;
}

int ctii(char str[]){
    int len = strlen(str)-1; int x = 0; int i = 0; int c;
                                                                                                    cout<<endl<<endl<<"Variante 2"<<endl<<"i: -"<<"\t\tlen: "<<len<<"\t\tc: -"<<"\t\tx: "<<x<<endl;
    while(len>=0) {
        c = str[i]-'0';
        /*****************************************************************************************
        *** die untere Möglichkeit funktioniert, allerdings macht die Rundung bei pow Probleme ***
        ******** unter anderem bei 3-, 5-, 8-, 9- & 10-stelligen Zahlen. Warum auch immer ********
        ******************************************************************************************
        if (len == 2) {
            x = x + c*100;
        }
        else {x = x + (c*(pow(10,len)));}
        ******************************************************************************************/
        x = x + (c*(powa(10,len)));                                                                  cout<<"i: "<<i<<"\t\tlen: "<<len<<"\t\tc: "<<c<<"\t\tx: "<<x<<endl;
        i++;
        len--;
    }
    return x;
}



int main()
{
    char str8[50], c;
    int i, cti1, cti2;
    bool boo;

    cout<<"Fehler in Ganzzahleingabe erkennen"<<endl<<endl;

    do{
        boo = true;

        cout<<"Geben Sie eine Ganzzahl ein: ";
        for(int f=0; f<50; f++){
            c = getchar();
            if(c=='\n'){
                str8[f] = '\0'; break;
            }
            str8[f] = c;
        }

        if (strlen(str8) == 0) {
            boo = false;
        }
        else{
            i = 0;
            while (i < strlen(str8)) {
                c = str8[i];
                if (!(c >= '0' && c <= '9')) {
                    boo = false; break;
                }
                i++;
            }
        }

        cout<<endl<<endl<<"Ihre Eingabe lautete: ";
        if (boo == true) {
            cti1 = cti(str8);
            cti2 = ctii(str8);
            cout<<endl<<"> Variante 1 (hinten beginnend) <"<<endl<<cti1<<endl<<"> Variante 2 ( vorne beginnend) <"<<endl<<cti2<<endl;
        }
        else {
            cout<<str8<<endl<<"Dies ist keine Ganzzahl."<<endl<<"Bitte versuchen Sie es erneut."<<endl<<endl<<endl<<endl;
        }
    }while(boo == false);
}
