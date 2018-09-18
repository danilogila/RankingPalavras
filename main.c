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

    while(1){
        system("cls");


        printf("Ranking de palavras");
        printf("\n");
        printf("\n");
        printf("    1 : Exibir mapa                              \n");
        printf("    2 : Exibir top 10 palavras                   \n");
        printf("    3 : Inserir palavra                          \n");
        printf("    4 : Excluir palavra                          \n");
        printf("    5 : Limpar mapa                              \n");
        printf("    6 : Selecionar termo                         \n");
        printf("    7 : Inserir quantidade em termo              \n");
        printf("    8 : Estatisticas do Ranking                  \n");

        int opcao;
            scanf("%i",&opcao);
        switch (opcao) {

            case (1):
                for(i=0;i<mapa->total;i++){
                    printf("\nTermo : %s / Quantidade : %i",mapa->lista[i]->termo,mapa->lista[i]->conta);
                }
                scanf("\n Digite para prosseguir %s");
            break;

            case 2:
                printf("1");
                scanf("\n Digite para prosseguir %s");
            break;

            case 3:
                printf("1");
                scanf("\n Digite para prosseguir %s");
            break;

            case 4:
                printf("1");
                scanf("\n Digite para prosseguir %s");
            break;

            case 5:
                printf("1");
                scanf("\n Digite para prosseguir %s");
            break;

            case 6:
                printf("1");
                scanf("\n Digite para prosseguir %s");
            break;

            case 7:
                printf("1");
                scanf("\n Digite para prosseguir %s");
            break;

            case 8:
                printf("1");
                scanf("\n Digite para prosseguir %s");
            break;

            default:
                    return 0;
            break;
        }
    }

    return 0;
}
