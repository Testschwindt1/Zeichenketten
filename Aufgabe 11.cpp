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
            cout<<"Wie lautet die Quellbasis? (>=2) ";
            cin>>qb;
            if (qb<2) {
                cout<<"Dies ist keine gueltige Basis fuer Zahlensysteme."<<endl<<endl;        /* Quellbasis muss mindestens 2 sein */
            }
        }while(qb<2);

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
            while (i < strlen(qz)) {
                c = qz[i];
                if (!(c >= '0' && c < '0'+qb)) {
                    boo = false; break;
                }
            i++;
            }
        }

        cout<<endl<<endl<<"Ihre Eingabe lautete: ";
        if (boo == true) {
/********** ZIELBASIS & -ZAHL **********/
            do{
                cout<<"Wie lautet die Zielbasis? (>=2) "; cin>>zb;
                if (qb<2) {
                    cout<<"Dies ist keine gueltige Basis für Zahlensysteme."<<endl<<endl;        /* Zielbasis muss mindestens 2 sein */
                }
            }while(qb<2);

/********** UMWANDLUNG **********/
            int len = strlen(qz)-1; int x = 0; int d0=0; int d, y; i = 0;

            while(len>=0) {                             /* Quellzahl ins 10er-System umwandeln */
                x = x + (qz[i]-'0')*pow(qb,len);        cout<<"qz: "<<qz[i]<<"\tqb: "<<qb<<"\tlen: "<<len<<"\tx:"<<x<<endl;
                i++;
                len--;
            }

            while((x/pow(zb,d0))>=1){
                d0++;                                   cout<<"x: "<<x<<"\tzb: "<<zb<<"\td: "<<d0<<"\tqb^d: "<<pow(zb,d0)<<" |_____| "<<x/pow(zb,d0)<<endl;
            }
            for (d = d0-1; d>=0; d--){                  cout<<"d: "<<d<<"\tx: "<<x<<"\tzb: "<<zb<<"\tx/zb: "<<x/zb<<"  Rest: "<<x%zb<<endl;
                zz[d] = '0' + (x%zb);                   /* Quellzahl mod Zielbasis = Wert in Zielbasis (Leserichtung von hinten nach vorne), weiter mit Ergebnis von Quellzahl/Zielbasis */
                x = x/zb;
            }
            zz[d0] = '\0';
/********** UMWANDLUNG ENDE **********/

            cout<<endl<<"Quellbasis: "<<qb<<endl<<"Quellzahl: "<<qz<<endl<<endl<<"Zeilbasis: "<<zb<<endl<<"Zielzahl: "<<zz<<endl<<endl;
        }
        else {
            cout<<qz<<endl<<"Dies ist keine gueltige Zahl des "<<qb<<"er-Systems."<<endl<<"Bitte versuchen Sie es erneut."<<endl<<endl<<endl<<endl;
        }
    }while(boo == false);
}
