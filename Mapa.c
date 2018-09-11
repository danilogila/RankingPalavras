#include "Mapa.h"

void inicia_mapa (Mapa *mp){

    mp->blocos = 0;
    mp->total = 0;
    mp->lista = malloc(sizeof(Item) * 10 * mp->blocos);
} //inicia um mapa vazio

void insere_termo (Mapa *mp, char *s){

    if(mp->total%10==0){
        mp->blocos++;
        mp->lista = (Item*) realloc(sizeof(Item), 10 * mp->blocos);
    }

    mp->lista[mp->total]->conta = 1;
    mp->lista[mp->total]->termo = (char) malloc(sizeof(s));

    mp->total++;

} // insere um item com termo s e conta=1

int incrementa (Mapa *mp, char *s){

    int i;
    for( i = 0; mp->total > i ; i++){
        if(mp->lista[i]==s){
            mp->lista[i]->conta++;
            return(0);
        }
    }
    return(1);

}//incrementa contador do termo s, retorna 1 se não encontrou o termo

int escreve_cont (Mapa *mp, char *s, int c){

    int i;
    for( i = 0; mp->total > i ; i++){
        if(mp->lista[i]==s){
            mp->lista[i]->conta = c;
            return(0);
        }
    }
    return(1);

}// escreve ´c` no contador do termo s, retorna 1 se não encontrou o termo

int le_contador (Mapa *mp, char *s){

    int i;
    for( i = 0; mp->total > i ; i++){
        if(mp->lista[i]==s){
            return(mp->lista[i]->conta);
        }
    }
    return(0);

} // retorna contador do termo s

void remove_termo (Mapa *mp, char *s){

    int i;
    for( i = 0; mp->total > i ; i++){
        if(mp->lista[i]==s){
           free(mp->lista[i]);
        }
        break;
    }
    for(; mp->total > i-1 ; i++){
        mp->lista[i] = mp->lista[i+1];
    }

} // remove o item com termo s

void libera_mapa (Mapa * mp){

    free(mp);
    inicia_mapa(mp);

} // libera o espaço ocupado pelo mapa

int tamanho_mapa (Mapa * mp){

    return(mp->total);

} // retorna número de itens no mapa

void le_termo (Mapa * mp, int i, char *t, int *c){

    if(mp->total > i){

        t = mp->lista[i]->termo;
        c = mp->lista[i]->conta;

    } else {

        t = '\0';
        c = 0;

    }

}  //retorna em ‘t’ o termo no índice ´i´ e em ´c´ o seu contador
