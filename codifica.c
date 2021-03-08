#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include "key.h"
#include "readfile.h"
#include "codifica.h"
#include "keygen.h"
#include "playfair_utils.h"

void getCoppieC(char *pathI, chiave *c, char *pathO) {
    char *stringa = readFile(pathI);
    char*directory =  creaDirectoryC(pathI, pathO);
    FILE *ph = fopen(directory, "w");
    free(directory);
    directory= NULL;
    static char coppie[3];
    for (int i = 0; i < strlen(stringa);) {
    creaCoppie(stringa,coppie,c,&i);
    codifica(coppie, c);
    fprintf(ph,"%s ",coppie);
        fflush(ph);
    }
    free(stringa);
    stringa = NULL;
    fclose(ph);
}


void codifica(char *coppie, chiave *c) {
    int riga1, colonna1, riga2, colonna2;
    trovaPosizione(c,coppie,&riga1,&riga2,&colonna1,&colonna2);
    if (riga1 == riga2) {
        if (colonna1 == 4) {
            coppie[0] = c->matrice[riga1][0];
            coppie[1] = c->matrice[riga2][colonna2 + 1];
        } else if (colonna2 == 4) {
            coppie[0] = c->matrice[riga1][colonna1 + 1];
            coppie[1] = c->matrice[riga2][0];
        } else {
            coppie[0] = c->matrice[riga1][colonna1 + 1];
            coppie[1] = c->matrice[riga2][colonna2 + 1];
        }
    } else if (colonna1 == colonna2) {
        if (riga1 == 4) {
            coppie[0] = c->matrice[0][colonna1];
            coppie[1] = c->matrice[riga2 + 1][colonna2];
        } else if (riga2 == 4) {
            coppie[0] = c->matrice[riga1 + 1][colonna1];
            coppie[1] = c->matrice[0][colonna2];
        } else {
            coppie[0] = c->matrice[riga1 + 1][colonna1];
            coppie[1] = c->matrice[riga2 + 1][colonna2];
        }
    } else {
        coppie[0] = c->matrice[riga1][colonna2];
        coppie[1] = c->matrice[riga2][colonna1];
    }
}
char *creaDirectoryC(char *pathI, char *pathO) {
    char *percorsoI = malloc((strlen(basename(pathI))+4) * sizeof(char));
    strcpy(percorsoI, basename(pathI));
    for (int i = 0; i < strlen(percorsoI); ++i) {
        if (percorsoI[i] == '.') {
            for (int j = strlen(percorsoI) - 1; j >= i; j--) {
                percorsoI[j] = '\0';
            }
            break;
        }
    }
    strcat(percorsoI, ".pf");
    char *finale = malloc((strlen(pathO) + 1) * sizeof(char) + sizeof(percorsoI));
    strcpy(finale, pathO);
    strcat(finale, "/");
    strcat(finale, percorsoI);
    free(percorsoI);
    percorsoI = NULL;
    return finale;
}

