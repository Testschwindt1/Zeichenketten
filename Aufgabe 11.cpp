#include <iostream>
#include <string.h> //für strlen
#include <stdio.h> //für getchar
#include <math.h> //für pow

using namespace std;

int countdigits(int x)
{
    int count=0;

    do{
        x = x/10;
        count++;
    }while(x>0);

    return count;
}

int powa(int b, int p) {
    int erg = 1;
    for (p; p>0; p--) {
        erg = erg * b;
    }
    return erg;
}

int main()
{
    char qz[50], c;
    char zz[50];
    int i, qb, zb;
    bool boo;

    cout<<"Umwandlung Zeichenkette: beliebige Zahlensysteme"<<endl<<endl;
    do{
        boo = true;

/****** QUELLBASIS ******/
        do{
            cout<<"Wie lautet die Quellbasis? (min 2, max 36) ";
            cin>>qb;
            if (qb<2 || qb>36) {
                cout<<"Dies ist keine gueltige Basis fuer Zahlensysteme."<<endl<<endl;        /* Quellbasis muss mindestens 2 sein */
            }
        }while(qb<2 || qb>36);

/****** QUELLZAHL ******/
        cout<<"Geben Sie Zahl im "<<qb<<"er-System ein: "; cin>>qz;
        /*for(int f=0; f<50; f++){
            c = getchar();
            if(c=='\n'){
                qz[f] = '\0'; break;
            }
            qz[f] = c;
        }*/

        if (strlen(qz) == 0) {
            boo = false;
        }
        else {
            i = 0;
            if (qb<=10) {
                while (i < strlen(qz)) {
                    c = qz[i];
                    if (!(c >= '0' && c < '0'+qb)) {
                        boo = false; break;
                    }
                i++;
                }
            }
            else {
                while (i < strlen(qz)) {
                    c = qz[i];
                    if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'A'+qb-10))) {
                        boo = false; break;
                    }
                i++;
                }
            }
        }

        if (boo == true) {
/********** ZIELBASIS & -ZAHL **********/
            do{
                cout<<"Wie lautet die Zielbasis? (min 1, max 36) "; cin>>zb;
                if (zb<1 || zb>36) {
                    cout<<"Dies ist keine hier definierte Basis fuer Zahlensysteme."<<endl<<endl;        /* Zielbasis muss mindestens 2 sein */
                }
            }while(zb<1 || zb>36);

/********** UMWANDLUNG **********/
                int len = strlen(qz)-1; int x = 0; int d0=0; int d, y; i = 0;

                while(len>=0) {                                         /* Quellzahl ins 10er-System umwandeln */
                    if (qz[i]>='0' && qz[i]<='9') {
                        x = x + (qz[i]-'0')*powa(qb,len);                cout<<"qz: "<<qz[i]<<"\tqb: "<<qb<<"\tlen: "<<len<<"\tx:"<<x<<endl;
                    }
                    else {
                        x = x + (qz[i]-'A'+10)*powa(qb,len);             cout<<"qz: "<<qz[i]<<"\tqb: "<<qb<<"\tlen: "<<len<<"\tx:"<<x<<endl;
                    }
                    i++;
                    len--;
                }

                if (zb==1) {
                    cout<<endl<<"Ihre Eingabe lautete: "<<endl<<"Quellbasis: "<<qb<<endl<<"Quellzahl: "<<qz<<endl<<endl<<"Zeilbasis: "<<zb<<endl<<"Zielzahl:";
                    if (x!=0) {
                        int e=0;
                        for (x; x>0; x--) {
                            if ((e%10)==0) {
                                cout<<endl;
                            }
                            cout<<"|";
                            e++;
                        }
                    }
                    cout<<" [Ende]"<<endl<<endl;
                }
                else {
                    while((x/powa(zb,d0))>=1){
                        d0++;                                               cout<<"x: "<<x<<"\tzb: "<<zb<<"\td: "<<d0<<"\tqb^d: "<<powa(zb,d0)<<" |_____| "<<x/powa(zb,d0)<<endl;
                    }
                    for (d = d0-1; d>=0; d--){                              cout<<"d: "<<d<<"\tx: "<<x<<"\tzb: "<<zb<<"\tx/zb: "<<x/zb<<"  Rest: "<<x%zb<<endl;
                        if ((x%zb)<10) {                                    /* Quellzahl mod Zielbasis = Wert in Zielbasis (Leserichtung von hinten nach vorne), weiter mit Ergebnis von Quellzahl/Zielbasis */
                            zz[d] = '0' + (x%zb);
                        }
                        else{
                            zz[d] = 'A' + (x%zb) - 10;

                        }
                        x = x/zb;
                    }
                    zz[d0] = '\0';
/********** UMWANDLUNG ENDE **********/

                    cout<<endl<<"Ihre Eingabe lautete: "<<endl<<"Quellbasis: "<<qb<<endl<<"Quellzahl: "<<qz<<endl<<endl<<"Zeilbasis: "<<zb<<endl<<"Zielzahl: "<<zz<<endl<<endl;
                }
        }
        else {
            cout<<"Ihre Eingabe lautete: "<<qz<<endl<<"Dies ist keine gueltige Zahl des "<<qb<<"er-Systems."<<endl<<"Bitte versuchen Sie es erneut."<<endl<<endl<<endl<<endl;
        }
    }while(boo == false);
}
