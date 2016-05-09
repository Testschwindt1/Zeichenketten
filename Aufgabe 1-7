#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

using namespace std;

int main()
{
    int Aufg;
    char str1[11]; char str2[11]; char str3[11]; //char str4[11];
    int i; int q, w, e;
    char c;
    bool boo;


Start:
    cout<<"Zum Beenden druecken Sie die 0!"<<endl<<"Aufgabe (1-7): ";cin>>Aufg;
    switch (Aufg) {

case 0:
    cout << endl << endl;
    cout << "Danke!" << endl << endl;
break;

case 1:
    cout<<"Komma zu Punkt!"<<endl<<endl;

    cout<<"Bitte Kommazahl (max. 9 Ziffern) eingeben: "; cin>>str1;
    for (i = 0; i <= 10; i++)
    {
        if (str1[i] == ',')
            str1[i] = '.';
    }
    cout<<endl<<endl<<str1;
break;


case 2:
    cout<<"Stringlaenge!"<<endl<<endl;

    i = 0;
    cout<<"Bitte 1 Wort (max 10 Zeichen) eingeben: "; cin>>str2;
    while(str2[i]!='\0') {
        i++;
    }
    cout<<endl<<endl<<"while: " << i << "\t strlen: " << strlen(str2);
break;


case 3:
    cout<<"Klein- zu Grossschreibung! (1)"<<endl<<endl;

    cout<<"Bitte 1 Wort (max. 10 Zeichen) eingeben: "; cin>>str3;
    if (str3[0] >= 97 && str3[0] <= 122)
        str3[0] = str3[0] - 32;
    cout<<endl<<endl<<str3;
break;


/*case 4:
    cout<<"Zeichen kuerzen! (1)"<<endl<<endl;

    cout<<"Wort (max. 10 Zeichen) eingeben: "; cin>>str4;
    str4[5] = '\0';

    cout<<endl<<endl<<str4;
break;*/
//case 4 mit getchar/putchar. Index i hochzählen für while-Schleife?
case 4:
    cout << "Zeichen beschraenken!"<<endl<<endl;
    i = 0;

    cout<<"Wort eingeben (max. 5 Zeichen gueltig): ";
    while (i<=5) {
        c = getchar();
        putchar(c);
        i++;
    }
    cout<<endl<<endl;
break;

case 5:
    cout<<"Klein- zu Grossschreibung! (2)"<<endl<<endl;

    boo = true;
    cout<<"Satz eingeben und mit . beenden:";
    do
    {
        c = getchar();
        if (boo == true) {
            if (c >= 97 && c <= 122) {
                c = c - 32;
            }
            boo = false;
        }
        if (c == ' ') {
            boo = true;
        }
        putchar(c);
    }while(c != '.');

    cout<<endl<<endl;
break;


case 6:
    cout<<"Zaehlen"<<endl<<endl;

    q=0; w=0; e=-1;
    cout<<"Satz eingeben und mit . beenden:";
    while(c != '.') {
        c = getchar();
        if (c >= 48 && c <= 57) {
            q++;
        }
        else {
            if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
                w++;
            }
            else {
                e++;
            }
        }
        putchar(c);
    }

    cout<<endl<<endl;
    cout<<"numerische Zeichen: "<<q<<endl;
    cout<<"alphabetische Zeichen: "<<w<<endl;
    cout<<"Sonderzeichen (+Space): "<<e<<endl;
break;


case 7:
    cout<<"Woerter Zaehlen"<<endl<<endl;

    w=0;
    boo=true;
    cout<<"Satz eingeben und mit . beenden:";
    while(c != '.') {
        c = getchar();
        if (c==' ') {
            boo = true;
        }
        if (c!=' ' && boo==true) {
            w++;
            boo=false;
        }
        putchar(c);
    }

    cout<<endl<<endl;
    cout<<"Anzahl Woerter: "<<w<<endl;
break;


default:
    cout << endl << endl;
    cerr << "Die Loesung zu einer solchen Aufgabe existiert in diesem Programm nicht..." << endl << "damn ._." << endl << endl << endl << endl;
    goto Start;
break;
    }
}
