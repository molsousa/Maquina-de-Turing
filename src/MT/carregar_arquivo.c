#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header.h"
#include "carregar_arquivo.h"

static void* manipular_string(char* texto, int opcao, int n);

void carregar_arquivo(Maquina* maquina)
{
    FILE* fr = fopen("MT.txt", "r");
    char* texto = (char*) malloc(30 * sizeof(char));
    Lista* l = criar_lista();
    Transicoes aux;
    register int i;

    if(!fr || !texto){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    fscanf(fr, "%[^\n]%*c", texto);
    sscanf(texto, "Q=%d", &maquina->num_estados);
    // printf("%d\n", maquina->num_estados); // [DEBUG]

    fscanf(fr, "%[^\n]%*c", texto);
    maquina->estados_finais = (int*) manipular_string(texto, 1, maquina->num_estados);
    for(i = 0; maquina->estados_finais[i] != -1; i++)
        // printf("%d\n", maquina->estados_finais[i]); // [DEBUG]

    fscanf(fr, "%[^\n]%*c", texto);
    maquina->alfabeto = (char*) manipular_string(texto, 2, strlen(texto));
    // printf("%s\n", maquina->alfabeto); // [DEBUG]

    maquina->transicoes = criar_lista();

    while(fgets(texto, 30, fr) != NULL){
        sscanf(texto, "(q%d,%c)=(q%d,%c,%c)\n", &aux.estado_atual, &aux.simbolo_lido, &aux.proximo_estado,
                                            &aux.simbolo_escrito, &aux.direcao_fita);
        inserir_transicao(l, aux);
    }
    // imprimir_lista(l); // [DEBUG]
    inverter_lista(maquina->transicoes, l);

    l = liberar_lista(l);
    free(texto);
    texto = NULL;
    fclose(fr);

    imprimir_lista(maquina->transicoes); // [DEBUG]
}

static void* manipular_string(char* texto, int opcao, int n)
{
    int* aux;
    char* ptr;
    register int i = 0;

    while(*texto != '=')
            ++texto;

    switch(opcao){
    case 1:
        aux = (int*) malloc(n * sizeof(int));

        while(*texto != '\0'){
            if(*texto < '0' || *texto > '9'){
                ++texto;
                continue;
            }
            aux[i] = *texto - 48;
            i++;

            ++texto;
        }
        aux[i] = -1;
        break;

    case 2:
        ptr = (char*) malloc(n * sizeof(char));

        while(*texto != '\0'){
            if((*texto < 'A' || *texto > 'Z') && (*texto < 'a' || *texto > 'z')){
                ++texto;
                continue;
            }
            ptr[i] = *texto;
            i++;

            ++texto;
        }
        ptr[i] = 0;

        return ptr;
    }

    return aux;
}
