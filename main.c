#include "keygen.h"
#include "key.h"
#include "codifica.h"
#include "decodifica.h"

void printInfo() {
        printf("Playfair: il nome della cartella\n");
        printf("encode/decode/creaChiave in base a cosa il programma deve fare\n");
        printf("Keyfile:dove è stata salvata la chiave\n");
        printf("Outputdir: Directory dove verranno salvati i risultati\n");
        printf("<File1>:primo file da codificare\n");
        printf("<Filen>: ultimo file da codificare\n");
    }




int main(int argc, char* argv[]) {


    if (argc < 5) {
        printf("Wrong number of parameters (expected 4 are %d)!\n\n", argc);
        printInfo();
        return -1;
    }
     static chiave c;
    if (strcmp(argv[1], "encode") == 0) {
        creaMatrice(&c,argv[2]);
        for (int i = 4; i < argc; ++i) {
            getCoppieC(argv[i], &c, argv[3]);

        }
        return 0;
    }
    if (strcmp(argv[1], "decode") == 0) {
        creaMatrice(&c,argv[2]);
        for (int i = 4; i < argc; ++i) {
            getCoppieD(argv[i], &c, argv[3]);
        }

        return 0;
    }
    if (strcmp(argv[1], "creaChiave") == 0) {
        creaChiave(argv[2], argv[3], argv[4], argv[5], argv[6]);
        return 0;
    }



}




