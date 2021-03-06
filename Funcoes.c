
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "Funcoes.h"

char* pega_palavra (const char* str,int prime,int last){

    char* palavra = calloc(sizeof(char), (size_t) (last - prime + 1));
    int i,x=0;
    for(i=prime;i<last;i++){
        palavra[x] = str[i];
        x++;
    }

    return palavra;
}

int contador(char* str, int limite){

    int i=0,contador=0;

    for(;i<limite;i++){

        if(str[i] == ';' && str[i+1] != ';'){
            contador++;
        }
        if(str[i]==NULL){
            break;
        }

    }

    return contador;

}

void formatador(char* str,int limite){

    int i;
    char token = ';';
    for(i = 0; i < limite; i++){
        if((str[i] == ' ') || str[i] == '.' || str[i] == ','
           || str[i] == '\n' || str[i] == '\0'
           || str[i] == EOF){
            (str[i] = token);
        }
        if(str[i]==NULL){
            break;
        }
    }

}

void separador(char* str,int limite){

    int i,j,k=0;
    int primeira_letra=0;
    int ultima_letra=0;
    printf("\n");
    for(i=0;i<limite;i++){

        if(str[i]==NULL){
            break;
        }
        if(str[i] == ';' && str[i+1] != ';'){

            while(str[ultima_letra-1] == ';'){
                ultima_letra--;
            }

            k++;

            primeira_letra = i+1;
            ultima_letra = primeira_letra;
        }
        ultima_letra++;
    }

}

char** lista_de_palavras (char* str,int limite){

    char** lista;
    int i,k=0;
    int primeira_letra=0,ultima_letra=0;

    lista = (char **) malloc(contador(str, limite) * sizeof(char*));

    for(i=0;i<contador(str,limite);i++){
        lista[i] = (char*) malloc(10*(sizeof(char)));
    }

    for(i=0;i<limite;i++){
        if(str[i]==NULL){
            break;
        }
        if(str[i] == ';' && str[i+1] != ';'){

            while(str[ultima_letra-1] == ';'){
                ultima_letra--;
            }
            lista[k] = pega_palavra(str,primeira_letra,ultima_letra);

            k++;

            primeira_letra = i+1;
            ultima_letra = primeira_letra;
        }
        ultima_letra++;
    }

    return lista;

}

