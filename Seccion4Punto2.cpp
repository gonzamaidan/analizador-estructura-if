#include <iostream>

using namespace std;
#define ERROR 18

bool esCaracterBlanco(char c);
bool esIf(char c);
bool esElse(char c);
bool esCondicion(char c);

int main() {

    char caracter;
    int estado = 0;

    while(cin >> caracter) {



        switch(estado) {

        case 0:
            if(esIf(caracter))
                estado = 1;
            else
                estado = ERROR; //Estado de error
            break;

        case 1:
            if(caracter == '(')
                estado = 2;
            else
                estado = ERROR;
            break;

        case 2:
            if(esCondicion(caracter))
                estado = 3;
            else
                estado = ERROR;
            break;

        case 3:
            if(caracter == ')')
                estado = 4;
            else
                estado = ERROR;
            break;
        case 4:
            if(caracter == '{')
                estado = 10;
            else if(caracter == 's')
                estado = 5;
            else
                estado = ERROR;
            break;
        case 5:
            if(caracter == ';')
                estado = 6;
            else
                estado = ERROR;
            break;
        case 6:
            if(esElse(caracter))
                estado = 7;
            else
                estado = ERROR;
            break;
        case 7:
            if(esIf(caracter))
                estado = 1;
            else if(caracter == '{')
                estado = 14;
            else if(caracter == 's')
                estado = 8;
            else
                estado = ERROR;
            break;
        case 8:
            if(caracter == ';')
                estado = 9;
            else
                estado = ERROR;
            break;
        case 9:
            if(esCaracterBlanco(caracter))
                estado = 9;
            else
                estado = ERROR;
            break;
        case 10:
            if(caracter == 's')
                estado = 11;
            else
                estado = ERROR;
            break;
        case 11:
            if(caracter == ';')
                estado = 12;
            else
                estado = ERROR;
            break;
        case 12:
            if(caracter == '}')
                estado = 13;
            else if(caracter == 's')
                estado = 11;
            else
                estado = ERROR;
            break;
        case 13:
            if(esElse(caracter))
                estado = 7;
            else
                estado = ERROR;
            break;
        case 14:
            if(caracter == 's')
                estado = 15;
            else
                estado = ERROR;
            break;
        case 15:
            if(caracter == ';')
                estado = 16;
            else
                estado = ERROR;
            break;
        case 16:
            if(caracter == '}')
                estado = 17;
            else if(caracter == 's')
                estado = 15;
            else
                estado = ERROR;
            break;
        case 17:
            if(esCaracterBlanco(caracter))
                estado = 17;
            else
                estado = ERROR;
            break;

        }

    }

    if(estado == 6 or estado == 9 or estado == 13 or estado == 17)
        cout << "La estructura es CORRECTA";
    else cout << "La estructura es INCORRECTA";

}


bool esCaracterBlanco(char c) {
    return (c == '\n' or c == '\t' or c == ' ');
}
bool esIf(char c) {
    if(c == 'i') {
        c = cin.get();
        return c == 'f';
    } else return false;
}
bool esElse(char c) {
    if( c == 'e'){
        c = cin.get();
        if( c == 'l') {
            c = cin.get();
            if( c == 's' ) {
                c = cin.get();
                if( c == 'e' ) {
                    c = cin.get();
                    return esCaracterBlanco(c);
                }
            }
        }
    }
    return false;
}
bool esCondicion(char c) {
    if( c == 'c')
        return true;
    else if(c == 'a'){
        cin >> c;
        if( c == '=') {
            c = cin.get();
            if(c == '=') {
                cin >>  c;
                return c == 'a';
            }
        } else if( c == '<' or c == '>' ) {
            c = cin.get();
            if( c == '=') {
                cin >>  c;
                return c == 'a';
            } else if(esCaracterBlanco(c))
                cin >> c;
            return c == 'a';
        }
    }

    return false;
}

