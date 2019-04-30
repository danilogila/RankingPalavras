            #include <stdio.h>
            #include <stdlib.h>
            #include <string.h>
            #include "Mapa.h"
            #include "Utils.h"
            #include <locale.h>
            #define Limite 10000

            int contadorLetras = 0;
            int qtd_maxima, qtd_minima = 0;
            int tmp;

            int main()
            {
                setlocale(LC_ALL, "Portuguese");
                int i=0;

                char **lista;

                char* nome_arquivo[100];
                FILE *fp;

                char *str = calloc(Limite, sizeof(char));
                char *filename = "loader.txt";
                char path[50];

                fp = fopen(filename, "r");
                if (fp == NULL){
                    printf("\nFalha ao abrir o arquivo. Tente novamente");
                    return 1;
                }

                fscanf(fp,"%[^\0]", str);

                fclose(fp);

                formatador(str,Limite);

                separador(str,Limite);
                lista = lista_de_palavras(str,Limite);


                Mapa* mapa;

                inicia_mapa(mapa);

                while(1){

                    printf("\n");
                    printf("\n===================================");
                    printf("\n====    Ranking de Palavras    ====");
                    printf("\n===================================");
                    printf("\n");
                    printf("1 - Ler arquivo txt \n");
                    printf("2 - Exibir Ranking Completo\n");
                    printf("3 - Exibir intervalo de Ranking\n");
                    printf("4 - Buscar palavra\n");
                    printf("5 - Opções\n");
                    printf("6 - Sair\n");
                    printf("\n");

                    int opcao;
                    int minimo;
                    int indice;
                    char* palavra = calloc(Limite,sizeof(char));
                    int x;
                    char* termo = malloc(50*sizeof(char));
                    int* conta[1];
                    char* insere = calloc(Limite,sizeof(char));

                    printf("\nDigite uma Opçao: ");
                    scanf("%d",&opcao);

                    switch (opcao) {

                        case (1):

                            printf("\nDigite caminho: ");
                            scanf("%s", &path);

                            printf("\n Caminho do arquivo: %s", path);

                            fp = fopen(path, "r");
                            if (fp == NULL){
                                printf("\nFalha ao abrir o arquivo. Tente novamente");
                                return 1;
                            }

                            fscanf(fp,"%[^\0]", str);

                            fclose(fp);

                            formatador(str,Limite);

                            separador(str,Limite);

                            lista = lista_de_palavras(str,Limite);

                            for(i=0;i<contador(str,Limite);i++){
                                if(incrementa(mapa,lista[i]) == 1){

                                    insere_termo(mapa,lista[i]);
                                }
                            }



                            printf("\nDigite 1 para voltar ao Menu principal\n");
                            scanf("%d",&opcao);

                        break;

                        case 2:
                            if(mapa->total == 0){
                                printf("\ nMapa está vazio");
                                break;
                            }

                            for(i = 0; i< mapa->total ;i++){
                                printf("\nTermo : %s",mapa->lista[i]->termo);
                                printf("\nQuantidade : %i", mapa->lista[i]->contador);
                            }

                            printf("\nDigite 1 para voltar ao Menu principal\n");
                            scanf("%d",&opcao);

                        break;

                        case 3:

                                if(mapa->total == 0){
                                    printf("\ nMapa está vazio");
                                    break;
                                }

                                system("cls");
                                printf("\n==================================");
                                printf("\n===    Intervalo de Ranking    ===");
                                printf("\n==================================");


                                printf("\nDigite a quantidade maxima: \n");
                                scanf("%d",&qtd_maxima);

                                printf("\nDigite a quantidade minima: \n");
                                scanf("%d",&qtd_minima);

                                for(i = 0; i< mapa->total ;i++){
                                     if(mapa->lista[i]->contador >= qtd_minima && mapa->lista[i]->contador <= qtd_maxima){
                                        printf("\nPalavra %s", mapa->lista[i]->termo);
                                        printf("\nQuantidade %i\n", mapa->lista[i]->contador);

                                     }
                                }

                                printf("\nTotal de palavras: %i", contadorLetras);
                                printf("\nDigite 1 para voltar ao Menu principal\n");
                                scanf("%d",&opcao);


                            break;

                        break;

                        case 4:

                            if(mapa->total == 0){
                                    printf("\ nMapa está vazio");
                                    break;

                            }

                            printf("\nDigite a palavra: ");
                            scanf("%s", palavra);
                            tmp = encontra_termo(mapa, palavra);

                            printf("\nDigite 1 para voltar ao Menu principal\n");
                            scanf("%d",&opcao);

                        break;

                        case 5:
                            if(mapa->total == 0){
                                    printf("\ nMapa está vazio");
                                    break;
                            }

                            system("cls");
                            printf("\n==================================");
                            printf("\n===    Intervalo de Ranking    ===");
                            printf("\n==================================");

                            printf("\nDigite minimo de caracteres a considerar:\n");
                            scanf("%d",&minimo);

                            for(i = 0; i< mapa->total ;i++){
                                 tmp = strlen(mapa->lista[i]->termo);
                                 if(minimo >= tmp){
                                    contadorLetras = contadorLetras + 1;
                                 }
                            }

                            printf("\nTotal de palavras: %i", contadorLetras);
                            printf("\nDigite 1 para voltar ao Menu principal\n");
                            scanf("%d",&opcao);

                            break;

                        break;

                        case 6:

                            return 0;


                        default:
                                return 0;
                        break;


                    }

                    printf("\n");

                    system("cls");
                }

                return 0;
            }
