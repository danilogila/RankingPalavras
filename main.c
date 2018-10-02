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
    //while (fgets(str, Limite_bytes, fp) != NULL);
    fscanf(fp,"%[^\0]", str);

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

        printf("\n");
        printf("\n");
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
        printf("\n");
        printf("\n");

        int opcao,bacon;
        int indice;
         int x;
         char* termo = malloc(50*sizeof(char));;
         int* conta[1];
        char* insere = calloc(Limite_bytes,sizeof(char));

            scanf("%d",&opcao);
        switch (opcao) {

            case (1):
                for(i=0;i<mapa->total;i++){
                    printf("\nTermo : %s / Quantidade : %i",mapa->lista[i]->termo,mapa->lista[i]->conta);
                }
                printf("Digite para prosseguir\n");
                scanf("%d",&opcao);
            break;

            case 2:
                x = (mapa->total>10) ? 10 : mapa->total;
                for(i = 0; i<x;i++){
                    printf("\nTermo : %s / Quantidade : %i",mapa->lista[i]->termo,mapa->lista[i]->conta);
                }
                printf("\nDigite para prosseguir\n");
                scanf("%d",&opcao);
            break;

            case 3:

                printf("Digite uma palavra ou sentença com menos de 10000 bytes:\n");
                scanf("%s",insere);
                if(incrementa(mapa,insere) == 1){
                    printf("     Nova palavra");
                    insere_termo(mapa,insere);
                } else {
                    printf("     Ja existe palavra\n");
                }


                printf("Digite para prosseguir\n");
                scanf("%d",&opcao);
            break;

            case 4:

                printf("1:      Excluir palava por indice\n");
                printf("2:      Excluir palava inserida\n");
                scanf("%d",&opcao);

                switch (opcao){

                    case 1 :


                        printf("Digite o indice da palavra\n");
                        scanf("%d",&opcao);
                        if(opcao > 0 && opcao <= mapa->total ){

                            remove_termo(mapa,mapa->lista[opcao-1]->termo);

                        } else {

                            printf("Indice Invalido\n");

                        }

                        printf("Digite para prosseguir\n");
                        scanf("%d",&opcao);

                    break;

                    case 2 :

                        printf("Digite a palavra\n");
                        scanf("%s",insere);
                        remove_termo(mapa,insere);
                    break;

                    default:

                        printf("Opcao Invalida\n");

                    break;

                }

                printf("Digite para prosseguir\n");
                scanf("%d",&opcao);
            break;

            case 5:
                libera_mapa(mapa);
                printf("1");
                printf("Digite para prosseguir\n");
                scanf("%d",&opcao);
            break;

            case 6:
                printf("1:      Selecionar palava por indice\n");
                printf("2:      Digitar palava\n");
                scanf("%d",&opcao);

                switch (opcao){

                    case 1 :


                        printf("Digite o indice da palavra\n");
                        scanf("%d",&opcao);
                        if(opcao > 0 && opcao <= mapa->total ){

                            le_termo(mapa,opcao,termo,conta);

                        } else {

                            printf("Indice Invalido\n");

                        }
                        if(conta > 0 && opcao > 0 && opcao <= mapa->total ){
                           printf("Termo | indice :%i\n",opcao);
                            printf("     Termo: %s\n",termo);
                            printf("     Contagem: %i",conta[0]);
                        }

                    break;

                    case 2 :

                        printf("Digite a palavra\n");
                        scanf("%s",insere);
                        indice = retorna_indice(mapa,insere);

                        if(indice >= 0){
                            printf("Termo | indice :%i\n",indice);
                            printf("     Termo: %s\n",mapa->lista[indice]->termo);
                            printf("     Contagem: %i\n",mapa->lista[indice]->conta);
                        }

                    break;

                    default:

                        printf("Opcao Invalida\n");

                    break;

                }
                printf("\nDigite para prosseguir\n");
                scanf("%d",&opcao);

                break;

            case 7:
                printf("1:      Selecionar palava por indice\n");
                printf("2:      Digitar palava\n");
                scanf("%d",&opcao);

                switch (opcao){

                    case 1 :


                        printf("Digite o indice da palavra\n");
                        scanf("%d",&opcao);
                        if(opcao > 0 && opcao <= mapa->total ){

                            le_termo(mapa,opcao,termo,conta);

                            printf("Digite o novo valor para a contagem\n");
                            printf("     Termo: %s\n",termo);
                            printf("     Contagem: %i\n     ",conta[0]);
                            scanf("%d",conta);
                            escreve_cont(mapa,termo,conta[0]);

                            if(conta[0] > 0 && opcao > 0 && opcao <= mapa->total ){
                                printf("\n");
                                printf("\n");
                                printf("Novo valor\n");
                                printf("Termo | indice :%i\n",opcao);
                                printf("     Termo: %s\n",mapa->lista[opcao-1]->termo);
                                printf("     Contagem: %i\n",mapa->lista[opcao-1]->conta);
                            } else if(opcao > 0 && opcao <= mapa->total ) {

                                printf("\n");
                                printf("\n");
                                printf("Termo zerado\n");
                                printf("Apagando termo\n");
                                remove_termo(mapa,termo);

                            }

                        } else {

                            printf("Indice Invalido\n");

                        }


                    break;

                    case 2 :

                        printf("Digite a palavra\n");
                        scanf("%s",insere);
                        indice = retorna_indice(mapa,insere);

                        le_termo(mapa,indice+1,termo,conta);

                        if(indice >= 0){
                            printf("Digite o novo valor para a contagem\n");
                            printf("     Termo: %s\n",termo);
                            printf("     Contagem: %i\n",conta[0]);

                            scanf("%d",conta);

                            escreve_cont(mapa,termo,conta[0]);

                            printf("Termo | indice :%i\n",indice);
                            printf("     Termo: %s\n",termo);
                            printf("     Contagem: %i\n",conta[0]);
                        }
                        if(conta[0] > 0){
                            printf("\n");
                            printf("\n");
                            printf("Novo valor\n");
                            printf("Termo | indice :%i\n",opcao);
                            printf("     Termo: %s\n",termo);
                            printf("     Contagem: %i",conta[0]);
                        } else {

                            printf("\n");
                            printf("\n");
                            printf("Termo zerado\n");
                            printf("Apagando termo\n");
                            remove_termo(mapa,termo);

                        }

                    break;

                    default:

                        printf("Opcao Invalida\n");

                    break;

                }
                printf("Digite para prosseguir\n");
                scanf("%d",&opcao);

            break;

            case 8:
                printf("\nExistem %i blocos no mapa\n",mapa->blocos);
                printf("\nExistem %i palavras no mapa\n",mapa->total);
                if(mapa->blocos > 0)
                    printf("\nO termo %s e o mais recorrente aparecendo %.2f vezes a mais que o segundo termo\n",mapa->lista[0]->termo,(1.0*mapa->lista[0]->conta/mapa->lista[1]->conta*1.0));
                printf("Digite para prosseguir");
                scanf("\n  %d",&opcao);
            break;

            default:
                    return 0;
            break;


        }
        printf("\n");
        printf("\n");
        printf("\n");

        system("cls");
    }

    return 0;
}
