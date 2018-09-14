#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mapa.h"

int main()
{
    int i = 0;
    FILE *fp;
    char *str = calloc(1000, sizeof(char));
    char* filename = "lorem.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, 1000, fp) != NULL){
        i++;

    }
    fclose(fp);

    for(i = 0; i < 600; i++){
        if(!strcmp(&str[i], " ")){
            strcpy(&str[i] , ";");
        }
        if(!strcmp(&str[i], ".")){
                strcpy(&str[i] , "");
        }
        if(!strcmp(&str[i], ",")){
                strcpy(&str[i] , "");
        }
    }
printf("%s", str);
    return 0;
}
