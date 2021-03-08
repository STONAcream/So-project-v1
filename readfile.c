#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"


int size(char* path){
    FILE *ph= fopen(path,"r");
    fseek(ph,0,SEEK_END);
    int fileSize = ftell(ph);
    rewind(ph);
    fclose(ph);
    return fileSize;
}

char* readFile(char *path){
    char*buf= malloc(sizeof(char)*(size(path)+1));
    FILE *ph = fopen(path, "r");
    if (ph) {
        int i = 0;
        while (!feof(ph)) {
            char a  = fgetc(ph);
            if( a >=65 &&  a <=90){
                buf[i] = a;
                i++;
            }else if( a >=97 &&  a <=122 ){
                buf[i] = a - 32;
                i++;
            }else if( a == '\r' ||  a=='\n'){
                buf[i] = a;
                i++;
            }
        }
        buf[i]='\0';
    }else {
        ferror(ph);
    }
    fclose(ph);
    return buf;
}