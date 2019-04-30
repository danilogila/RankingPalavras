typedef struct _item {
    int contador;
    char *termo;
} Item;


typedef struct _mapa {
    int total;
    int blocos;
    Item **lista;
} Mapa;

void inicia_mapa (Mapa *mp);

void insere_termo (Mapa *mp, char *s);

int incrementa (Mapa *mp, char *s);

int escreve_cont (Mapa *mp, char *s, int c);

int le_contador (Mapa *mp, char *s);

void remove_termo (Mapa *mp, char *s);

void libera_mapa (Mapa * mp);

int tamanho_mapa (Mapa * mp);

void le_termo (Mapa * mp, int i, char *t, int *c);

int encontra_termo (Mapa *mp, char *s);

int retorna_indice (Mapa *mp, char *s);
