#include<stdio.h>
#include <dirent.h>
#include "keygen.h"
                    int creaChiave(char *file, char *alfabeto, char *sostituto, char *speciale, char *chiave) {
                        FILE *output = fopen(file, "w");
                        if (output == NULL) {
                            perror("Error while opening generated file!");
                            return -1;
                        }
                        fprintf(output, "%s\r\n", alfabeto);
                        fprintf(output, "%c\r\n", sostituto[0]);
                        fprintf(output, "%c\r\n", speciale[0]);
                        fprintf(output, "%s\r\n", chiave);
                        fclose(output);
                        return 1;
                    }






