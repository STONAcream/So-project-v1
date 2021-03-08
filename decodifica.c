#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "key.h"
#include "decodifica.h"
#include "keygen.h"
#include "playfair_utils.h"
#include "readfile.h"


void getCoppieD(char *pathI, chiave * c, char *pathO) {
    char *stringa = readFile(pathI);
    char *directory = creaDirectoryD(pathI, pathO);
    FILE *ph = fopen(directory, "w");
    free(directory);
    directory=NULL;
    char coppie[3];
    for (int i = 0; i < strlen(stringa);) {
       creaCoppie(stringa,coppie,c,&i);
        decodifica(coppie, c);
        fprintf(ph, "%s ", coppie);
        fflush(ph);
    }
    free(stringa);
    stringa = NULL;
    fclose(ph);
}


void decodifica(char *coppie, chiave*c) {
    int riga1, colonna1, riga2, colonna2;
    trovaPosizione(c,coppie,&riga1,&riga2,&colonna1,&colonna2);
    if (riga1 == riga2) {
        if (colonna1 == 0) {
            coppie[0] = c->matrice[riga1][4];
            coppie[1] = c->matrice[riga2][colonna2 - 1];
        } else if (colonna2 == 0) {
            coppie[0] = c->matrice[riga1][colonna1 - 1];
            coppie[1] = c->matrice[riga2][4];
        } else {
            coppie[0] = c->matrice[riga1][colonna1 - 1];
            coppie[1] = c->matrice[riga2][colonna2 - 1];
        }
    } else if (colonna1 == colonna2) {
        if (riga1 == 0) {
            coppie[0] = c->matrice[4][colonna1];
            coppie[1] = c->matrice[riga2 - 1][colonna2];
        } else if (riga2 == 0) {
            coppie[0] = c->matrice[riga1 - 1][colonna1];
            coppie[1] = c->matrice[4][colonna2];
        } else {
            coppie[0] = c->matrice[riga1 - 1][colonna1];
            coppie[1] = c->matrice[riga2 - 1][colonna2];
        }
    } else {
        coppie[0] = c->matrice[riga1][colonna2];
        coppie[1] = c->matrice[riga2][colonna1];
    }


}
char *creaDirectoryD(char *pathI, char *pathO){
    char *percorsoI = malloc((strlen(basename(pathI))+5) * sizeof(char));
    strcpy(percorsoI, basename(pathI));
    for (int i = 0; i < strlen(percorsoI); ++i) {
        if (percorsoI[i] == '.') {
            for (int j = strlen(percorsoI) - 1; j >= i; j--) {
                percorsoI[j] = '\0';
            }
            break;
        }
    }
    strcat(percorsoI, ".dec");
    char *finale = malloc((strlen(pathO) + 1) * sizeof(char) + sizeof(percorsoI));
    strcpy(finale, pathO);
    strcat(finale, "/");
    strcat(finale, percorsoI);
    free(percorsoI);
    percorsoI = NULL;
    return finale;
}

