
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include "Mapa.h"

void inicia_mapa (Mapa *mp){

    int i;
    mp->blocos = 0;
    mp->total = 0;
    mp->lista = calloc(sizeof(Item*), mp->blocos);
    printf("\n===================================");
    printf("\n=====    Mapa Inicializado    =====");
    printf("\n===================================");
    printf("\n\n\n");
    system("cls");
}

void insere_termo (Mapa *mp, char *s){

    if(mp->total%10==0){
        mp->blocos++;
        mp->lista = realloc(mp->lista,((sizeof(Item*) *10 * mp->blocos)));
        printf("======== Lista cheia ========\n");
        printf("======== Redimensionando a lista ========\n");
    }

    mp->lista[mp->total] = calloc(sizeof(Item),1);
    mp->lista[mp->total]->contador = 1;

    mp->lista[mp->total]->termo = (char*) malloc(sizeof(s));
    mp->lista[mp->total]->termo = s;
    mp->total++;
    printf("\nTermo Inserido com sucesso!\n");

}

int incrementa (Mapa *mp, char *s){

    int i;
    Item* aux;

    i = retorna_indice(mp,s);

    if(i>=0){
        mp->lista[i]->contador++;

        printf("Termo %s Incrementado com sucesso\n", mp->lista[i]->termo);

        for(; i > 0 && mp->lista[i]->contador > mp->lista[i-1]->contador; i--){
            aux = mp->lista[i-1];
            mp->lista[i-1] = mp->lista[i];
            mp->lista[i] = aux;
        }

        return(0);
    }

    return(1);

}

int escreve_cont (Mapa *mp, char *s, int c){

    int i = retorna_indice(mp,s);
    Item* aux;
    if(i>=0){
        mp->lista[i]->contador = c;

        for(; i > 0 && mp->lista[i]->contador > mp->lista[i-1]->contador; i--){
            aux = mp->lista[i-1];
            mp->lista[i-1] = mp->lista[i];
            mp->lista[i] = aux;
        }
        return(0);
    }
    return(1);

}

int le_contador (Mapa *mp, char *s){

    int i;
    for( i = 0; mp->total > i ; i++){
        if(mp->lista[i]->termo == s){
            return(mp->lista[i]->contador);
        }
    }
    return(0);

}

void remove_termo (Mapa *mp, char *s){

    int i = retorna_indice(mp,s);
    if( i >= 0){
        for(; mp->total > i+1 ; i++){
            mp->lista[i] = mp->lista[i+1];
        }

        mp->total--;
        if(mp->total%10==0){
            mp->blocos--;
            mp->lista = realloc(mp->lista,((sizeof(Item*) *10 * mp->blocos)));
            printf("\nTamanho da lista redimensionado\n");
        }
        free(mp->lista[mp->total-1]->termo);
        free(mp->lista[mp->total-1]);
    }
}

void libera_mapa (Mapa * mp){
    int i;
    for(i=mp->total-1;i>0;i--){
        remove_termo(mp,mp->lista[i]->termo);
    }
    mp->total--;
    mp->blocos--;
    mp->lista = realloc(mp->lista,((sizeof(Item*) *10 * mp->blocos)));
}

int tamanho_mapa (Mapa * mp){

    printf("Tamanho atual do Mapa: %i", mp->total);
    return(mp->total);

}

void le_termo (Mapa * mp, int i, char *t, int *c){

    if( i < mp->total && i > 0){

        strcpy(t,mp->lista[i-1]->termo);
        *c = mp->lista[i-1]->contador;

    } else {

        t = '\0';
        c = 0;

    }

}
int encontra_termo (Mapa *mp, char *s){

    for(int i = 0; mp->total > i ; i++){

        if(strcmp(mp->lista[i]->termo, s)== 0){

            printf("Termo %s: \n", s);
            printf("Quantidade: %i\n", mp->lista[i]->contador);
            return(0);
        }
    }
    printf("Termo %s: \n", s);
    printf("Quantidade: 0\n");
    return(1);

}

int retorna_indice (Mapa *mp, char *s){

    for(int i = 0; mp->total > i ; i++){

        if(strcmp(mp->lista[i]->termo, s)== 0){
            return(i);
        }
    }
    printf("Termo ausente\n");
    return(-1);

}

