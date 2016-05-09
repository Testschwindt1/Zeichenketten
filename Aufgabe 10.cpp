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
        ++count;
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
    char bin[50], c;
    char oct[50], dec[50], hex[50];
    int i;
    bool boo;

    cout<<"Umwandlung Zeichenkette: Binaer in Oktal/Dezimal/Hexadezimal"<<endl<<endl;
    do{
        boo = true;

        cout<<"Geben Sie eine Binaerzahl ein: ";
        for(int f=0; f<50; f++){
            c = getchar();
            if(c=='\n'){
                bin[f] = '\0'; break;
            }
            bin[f] = c;
        }

        if (strlen(bin) == 0) {
            boo = false;
        }
        else {
            i = 0;
            while (i < strlen(bin)) {
                c = bin[i];
                if (!(c == '0' || c == '1')) {
                    boo = false; break;
                }
            i++;
            }
        }

        cout<<endl<<endl<<"Ihre Eingabe lautete: ";
        if (boo == true) {

/********** UMWANDLUNG Binär->Oktal **********/
            //2^3 = 8 -> drei Binärstellen = eine Oktalstelle -> von rechts nach links
            int len = strlen(bin)-1; char octh[4]; int x;
                                                        cout<<endl<<"Oktal"<<endl;
            do{
                x=0;
                octh[3] = '\0';                         /* Hilfsstring mit \0 beenden */
                for (i=0; i<3; i++) {                   /* hinterer Dreierblock der Binärzahl abtrennen und ggf mit 0 auffüllen */
                    if ((len-i)<0){
                        octh[2-i] = '0';
                    }
                    else{
                        octh[2-i] = bin[len-i];
                    }
                }                                       cout << octh << endl;

                for (i=0; i<3; i++) {                   /* Berechnung des Dezimalwerts des Dreierblocks */
                    if (octh[i] == '1') {
                        x = x + powa(2,(2-i));
                    }                                   cout<<"i: "<<i<<"\tx: "<<x<<endl;
                }
                oct[(len/3)] = '0' + x;                 /* x hat einen Wert zwischen 0&7 und kann so direkt an die entsprechende Stelle als Zeichen eingesetzt werden */
                len = len-3;
            }while(len>=0);
            oct[((strlen(bin)-1)/3+1)] = '\0';          /* Oktalstring mit \0 beenden - muss scheinbar als letztes passieren oO *//* -1 und später +1, weil es sonst bei Fall mod3=0 zu Fehler kommt */

/********** UMWANDLUNG Binär->Dezimal **********/
            len = strlen(bin)-1; x = 0; int d, d0, y; i = 0;
                                                        cout<<endl<<endl<<"Dezimal"<<endl;
            while(len>=0) {
                if (bin[i] == '1') {
                    x = x + powa(2,len);                 /* Binärzahl per 2^len in Dezimalzahl umwandeln */
                }                                       cout<<"bin: "<<bin[i]<<"\tpow: 2^"<<len<<"\tx: "<<x<<endl;
                i++;
                len--;
            }
            d0 = countdigits(x);                        /*Anzahl der Stellen der Dezimalzahl errechnen*/
            i = 0;
            for (d=d0-1; d>=0; d--) {
                y = x/10;   y = y*10;                   /* y = x mit der letzten Ziffer 0 -> x:2756, y:2750 | x:841, y:840 usw. */   cout<<"d: "<<d<<"\tx: "<<x<<"\ty: "<<y<<"\tx-y: "<<x-y<<endl;
                dec[d] = '0' + (x-y);                   /* Ziffer an Stelle d zurück in Zeichen an Stelle d umwandeln */
                x = x/10;
            }
            dec[d0] = '\0';                             /* Dezimalstring mit \0 abschließen */

/********** UMWANDLUNG Binär->Hexadezimal **********/
            //2^4 = 16 -> vier Binärstellen = eine Hexadezimalstelle -> von rechts nach links
            len = strlen(bin)-1; char hexh[5];
                                                        cout<<endl<<endl<<"Hexadezimal"<<endl;
            do{
                x=0;
                hexh[4] = '\0';                         /* Hilfsstring mit \0 beenden */
                for (i=0; i<4; i++) {                   /* hinterer Dreierblock der Binärzahl abtrennen und ggf mit 0 auffüllen */
                    if ((len-i)<0){
                        hexh[3-i] = '0';
                    }
                    else{
                        hexh[3-i] = bin[len-i];
                    }
                }                                       cout << hexh << endl;

                for (i=0; i<4; i++) {                   /* Berechnung des Dezimalwerts des Viererblocks */
                    if (hexh[i] == '1') {
                        x = x + powa(2,(3-i));
                    }                                   cout<<"i: "<<i<<"\tx: "<<x<<endl;
                }
                if (x<10) {
                    hex[(len/4)] = '0' + x;             /* Hat x einen Wert zwischen 0&9, kann die Zahl so als Zeichen übernommen werden */
                }
                else {
                    hex[(len/4)] = 'A' + (x-10);        /* Hat x einen Wert zwischen 10&15, muss sie in einen Buchstaben zwischen A&F umgewandelt werden */
                }
                len = len-4;
            }while(len>=0);
            hex[((strlen(bin)-1)/4+1)] = '\0';          /* Oktalstring mit \0 beenden - muss scheinbar als letztes passieren oO *//* -1 und später +1, weil es sonst bei Fall mod3=0 zu Fehler kommt */

/********** UMWANDLUNG ENDE **********/

            cout<<endl<<"     Binaer: "<<bin<<endl<<"      Oktal: "<<oct<<endl<<"    Dezimal: "<<dec<<endl<<"Hexadezimal: "<<hex<<endl<<endl;
        }
        else {
            cout<<bin<<endl<<"Dies ist keine gueltige Binaerzahl."<<endl<<"Bitte versuchen Sie es erneut."<<endl<<endl<<endl<<endl;
        }
    }while(boo == false);
}
