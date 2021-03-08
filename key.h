//
// Created by finn171a on 07/03/21.
//

#ifndef PLAYFAIR_KEY_H
#define PLAYFAIR_KEY_H

typedef struct chiave{
    char mancante;
    char speciale ;
    char matrice[5][5];
    char sostituto;
}chiave;
void getKey( chiave*c,char*stringa);
void getAlfabeto(chiave*c,char* stringa);
void getMancante(chiave *c);
void getSostituto(char *stringa, chiave *c);
void creaMatrice(chiave *chiave, char *pathFile);
void scorriMatrice(chiave*c,char a);
#endif //PLAYFAIR_KEY_H
