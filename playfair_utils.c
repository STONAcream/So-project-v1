#include"key.h"

void trovaPosizione(chiave *c,char *coppie,int *riga1,int *riga2,int *colonna1,int *colonna2){
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            if (coppie[0] == c->matrice[x][y]) {
                *riga1 = x;
                *colonna1 = y;
            }
            if (coppie[1] == c->matrice[x][y]) {
                *riga2 = x;
                *colonna2 = y;
            }
        }
    }
}


void creaCoppie(char *stringa,char*coppie,chiave*c,int*i) {

        if (stringa[*i] == c->mancante) {
            stringa[*i] = c->sostituto;
        }
        if (stringa[*i + 1] == c->mancante) {
            stringa[*i + 1] = c->sostituto;
        }
        coppie[0] = stringa[*i];
        coppie[1] = stringa[*i+1];
        if (coppie[0]== coppie[1]) {
            coppie[1] = c->speciale;
            *i += 1;
        } else {
            if (coppie[1] == '\0') {
                coppie[1] = c->speciale;
                *i += 1;
            } else {
                *i = *i + 2;
            }
        }
}