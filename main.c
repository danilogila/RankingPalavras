#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapa.h"
#include "Funcoes.h"
#define Limite_bytes 10000

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
    char **lista = lista_de_palavras(str,Limite_bytes);

    for(i=0;i<contador_de_palavras(str,Limite_bytes);i++){
        printf("\n%s",lista[i]);
    }


    Mapa* mapa;

    inicia_mapa(mapa);


    for(i=0;i<contador_de_palavras(str,Limite_bytes);i++){
        printf("\nAcrescentando palavra: %s // %i",lista[i],i);
        if(incrementa(mapa,lista[i]) == 1){
            printf("     Nova palavra");
            insere_termo(mapa,lista[i]);
        } else {
            printf("     Ja existe palavra");
        }
    }
    printf("\nTamanho do mapa : %i",tamanho_mapa(mapa));

    for(i=0;i<mapa->total;i++){
       printf("\nTermo : %s / Quantidade : %i",mapa->lista[i]->termo,mapa->lista[i]->conta);
    }



    return 0;
}
