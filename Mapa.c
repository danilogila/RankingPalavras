
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "Mapa.h"

void inicia_mapa (Mapa *mp){

    int i;
    mp->blocos = 0;
    mp->total = 0;
    mp->lista = calloc(sizeof(Item*), mp->blocos);
    for (i = 0; i < 10; ++i) {

    }
    printf("\nmapa iniciado");
} //inicia um mapa vazio

void insere_termo (Mapa *mp, char *s){

    if(mp->total%10==0){
        mp->blocos++;
        mp->lista = realloc(mp->lista,((sizeof(Item*) *10 * mp->blocos)));
        printf("Tamanho da lista redimensionado\n");
    }

    mp->lista[mp->total] = calloc(sizeof(Item),1);
    mp->lista[mp->total]->conta = 1;
    mp->lista[mp->total]->termo = (char*) malloc(sizeof(s));
    mp->lista[mp->total]->termo = s;
    mp->total++;
    printf("     Termo Inserido");

} // insere um item com termo s e conta=1

int incrementa (Mapa *mp, char *s){

    int i,trava=0;
    Item* aux;
    int conta_termo=le_contador(mp,s),ultimo = 0;


    for( i = 0; mp->total > i ; i++){

        if(strcmp(mp->lista[i]->termo, s)== 0){

            mp->lista[i]->conta++;

            printf("     Termo Incrementado");
            return(0);
        }
    }
    return(1);

}//incrementa contador do termo s, retorna 1 se não encontrou o termo

int escreve_cont (Mapa *mp, char *s, int c){

    int i = retorna_indice(mp,s);

    if(i>=0){
        mp->lista[i]->conta = c;
        return(0);
    }
    return(1);

}// escreve ´c` no contador do termo s, retorna 1 se não encontrou o termo

int le_contador (Mapa *mp, char *s){

    int i;
    for( i = 0; mp->total > i ; i++){
        if(mp->lista[i]->termo == s){
            return(mp->lista[i]->conta);
        }
    }
    return(0);

} // retorna contador do termo s

void remove_termo (Mapa *mp, char *s){

    int i = retorna_indice(mp,s);
    if( i >= 0){
        for(; mp->total > i-1 ; i++){
            mp->lista[i] = mp->lista[i+1];

        }

        mp->total--;
        if(mp->total%10==0){
            mp->blocos--;
            mp->lista = realloc(mp->lista,((sizeof(Item*) *10 * mp->blocos)));
            printf("\nTamanho da lista redimensionado\n");
        }
        free(mp->lista[mp->total]->termo);
        free(mp->lista[mp->total]);
    }
} // remove o item com termo s

void libera_mapa (Mapa * mp){
    int i;
    for(i=mp->total-1;i>0;i--){
        free(mp->lista[i]->termo);
        free(mp->lista[i]);
    }
    free(mp->lista);
    inicia_mapa(mp);

} // libera o espaço ocupado pelo mapa

int tamanho_mapa (Mapa * mp){

    return(mp->total);

} // retorna número de itens no mapa

void le_termo (Mapa * mp, int i, char *t, int *c){

    if( i < mp->total && i > 0){

        strcpy(t,mp->lista[i-1]->termo);
        *c = mp->lista[i-1]->conta;

    } else {

        t = '\0';
        c = 0;

    }

}  //retorna em ‘t’ o termo no índice ´i´ e em ´c´ o seu contador

int encontra_termo (Mapa *mp, char *s){

    int i,trava=0;
    Item* aux;
    int conta_termo=le_contador(mp,s),ultimo = 0;


    for( i = 0; mp->total > i ; i++){

        if(strcmp(mp->lista[i]->termo, s)== 0){

            printf("     Termo encontrado\n");
            return(0);
        }
    }
    printf("     Termo ausente\n");
    return(1);

}//Retorna 0 se encontra termo e 1 se não

int retorna_indice (Mapa *mp, char *s){

    int i,trava=0;
    Item* aux;
    int conta_termo=le_contador(mp,s),ultimo = 0;


    for( i = 0; mp->total > i ; i++){

        if(strcmp(mp->lista[i]->termo, s)== 0){

            printf("     Termo encontrado\n");
            return(i);
        }
    }
    printf("     Termo ausente\n");
    return(-1);

}//Retorna indice de termo e -1 se não for encontrado termo especificado
