#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapa.h"
#include "Funcoes.h"
#define Limite_bytes 1000

int main()
{
    int i=0;

    FILE *fp;
    char *str = calloc(Limite_bytes, sizeof(char));
    char* filename = "lorem.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Deu Ruim no %s",filename);
        return 1;
    }
    while (fgets(str, Limite_bytes, fp) != NULL);

    fclose(fp);

    formatador_de_texto(str,Limite_bytes);

    printf("%s\n", str);
    printf("total de palavras : %i", contador_de_palavras(str,Limite_bytes));

    separador_de_palavras(str,Limite_bytes);

    return 0;
}
