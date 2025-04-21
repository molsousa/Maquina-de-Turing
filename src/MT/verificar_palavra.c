#include <stdio.h>
#include <stdlib.h>
#include "../header.h"
#include "verificar_palavra.h"

static char* inserir_entrada();

void verificar_palavra(Maquina maquina)
{
    char* entrada = inserir_entrada();

    printf("%s\n", entrada);
}

static char* inserir_entrada()
{
    char *entrada = NULL;
    register int n = 1;
    char c;

    while((c = getchar()) != '\n' && c != EOF){
        entrada = (char*) realloc(entrada, n * sizeof(char));
        if(entrada == NULL){
            printf("Nao foi possivel alocar memoria!\n");
            exit(1);
        }
        entrada[n-1] = c;
        n++;
    }
    entrada = (char*) realloc(entrada, n * sizeof(char));

    if(entrada == NULL){
        printf("Nao foi possivel alocar memoria!\n");
        exit(1);
    }
    entrada[n-1] = '\0';

    return entrada;
}
