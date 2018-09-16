#include "Funcoes.h"

int contador_de_palavras (char* str, int limite){

    int i=0,contador=0;

    for(;i<limite;i++){

        if(str[i] == ';' && str[i+1] != ';'){
            contador++;
        }

    }

    return contador;

}

void formatador_de_texto (char* str,int limite){

    int i;
    char virg = ';';
    for(i = 0; i < limite; i++){
        if((str[i] == ' ') || str[i] == '.' || str[i] == ','){
            (str[i] = virg);
        }
    }

}

void separador_de_palavras(char* str,int limite){

    int i,j;
    int primeira_letra=0,ultima_letra=0,reserva=0;
    printf("\n");
    for(i=0;i<limite;i++){

        if(str[i] == ';' && str[i+1] != ';'){

            while(str[ultima_letra-1] == ';'){
                ultima_letra--;
            }

            for(j=primeira_letra;j<ultima_letra;j++){
                printf("%c",str[j]);
            }
            printf("\n");
            primeira_letra = i+1;
            ultima_letra = primeira_letra;
        }
        ultima_letra++;
    }

}
