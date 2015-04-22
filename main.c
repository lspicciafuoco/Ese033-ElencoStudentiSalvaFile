#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRLEN 30
#define N 3

struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};

struct s_studente elenco[N];

int main(int argc, char** argv) {

    int i;
    FILE *puntaFile;
     
    for(i = 0; i < N; i++) {
        printf("Nome %d : ", i);
        scanf("%s", elenco[i].nome);
        printf("Cognome elemento %d : ", i);
        scanf("%s", elenco[i].cognome);
        printf("Eta' %d : ", i);
        scanf("%d", &(elenco[i].eta));
        printf("Classe %d : ", i);
        scanf("%s", elenco[i].classe);
    }
    
  
    puntaFile = fopen("elenco.dat", "wb");
    if(puntaFile != NULL) {
        fwrite(&elenco, sizeof(elenco), N, puntaFile);
        fclose(puntaFile);
    }
    else
        printf("Impossibile aprire il file\n");
    
    return (EXIT_SUCCESS);
}