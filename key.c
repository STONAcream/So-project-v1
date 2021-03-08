#include <stdio.h>
#include <stdlib.h>
#include "key.h"
#include "readfile.h"
#include <stdbool.h>


void getKey( chiave*c,char*stringa) {
    c->speciale= stringa[30];
    for (int i = 33; stringa[i] != '\r'; ++i) {
        scorriMatrice(c,stringa[i]);
    }
}
void getAlfabeto(chiave*c,char* stringa) {
    for (int i = 0; i < 25; ++i) {
        scorriMatrice(c,stringa[i]);
    }
}


void getMancante(chiave *c) {
    bool val = false;
    for (char a = 'A'; a <= 'Z'; ++a) {
        for (int x = 0; x < 5 && val == false; ++x) {
            for (int y = 0; y < 5 && val == false; ++y) {
                if (c->matrice[x][y] == a) {
                    val = true;
                }
            }
        }
        if (val == false) {
            c->mancante = a;
            break;
        }
    }
}

void getSostituto(char *stringa, chiave *c) {
    c->sostituto = stringa[27];
}
void creaMatrice(chiave *chiave, char *pathFile) {
    char *buffer = readFile(pathFile);
    getKey(chiave, buffer);
    getAlfabeto(chiave, buffer);
    getMancante(chiave);
    getSostituto(buffer, chiave);
    free(buffer);
    buffer = NULL;

}

void scorriMatrice(chiave*c,char a){
    int contatore = 0;
    for (int x = 0; (x < 5   && contatore == 0); ++x) {
        for (int y = 0; (y < 5  && contatore == 0); ++y) {
            if (c->matrice[x][y] == a) {
                contatore++;
            }
            if (c->matrice[x][y] == 0 && contatore==0) {
                c->matrice[x][y]= a;
                contatore++;
            }

        }
    }
}

