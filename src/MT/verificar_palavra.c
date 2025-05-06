#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header.h"
#include "verificar_palavra.h"

// Funcao estatica para inserir entrada de palavra
static char* inserir_entrada();
// Funcao estatica para expandir fita em caso da fita voltar a esquerda (preenche com branco)
static void expandir_fita_esquerda(char** fita, int* pos);
// Funcao estatica para encontrar transicao valida
// Retorno: retorna a transicao valida ou nulo se invalida
static Elem* encontrar_transicao(Elem* l, char caractere, int estado_atual);
// Funcao estatica para verificar se um determinado estado eh final
// Retorno: 1 se for final, 0 se nao
static int eh_estado_final(Maquina maquina, int estado);
// Funcao estatica para imprimir a fita atual
static void imprimir_configuracao(char* fita, int pos, int estado);

// Funcao para verificar palavras
// Pre-condicao: arquivo valido carregado
// Pos-condicao: nenhuma
void verificar_palavra(Maquina maquina)
{
    printf("Insira a palavra: ");

    char* entrada = inserir_entrada();
    const int tamanho = strlen(entrada) + 2;
    char* fita = malloc(tamanho * sizeof(char));

    strcpy(fita, entrada);
    strcat(fita, "$");
    free(entrada);

    int pos = 0;
    int estado_atual = 0;
    Elem* transicao = NULL;

    while(1){
        imprimir_configuracao(fita, pos, estado_atual);

        if(pos == strlen(fita)){
            fita = realloc(fita, strlen(fita) + 2);
            strcat(fita, "_");
        }

        transicao = encontrar_transicao(*maquina.transicoes, fita[pos], estado_atual);

        if(transicao == NULL)
            transicao = encontrar_transicao(*maquina.transicoes, '*', estado_atual);

        if(transicao == NULL){
            printf("REJEITA\n");
            free(fita);
            return;
        }

        fita[pos] = transicao->info.simbolo_escrito;
        estado_atual = transicao->info.proximo_estado;

        if(transicao->info.direcao_fita == 'D')
            pos++;

        else if(transicao->info.direcao_fita == 'E'){
            pos--;
            if(pos < 0)
                expandir_fita_esquerda(&fita, &pos);
        }

        if(eh_estado_final(maquina, estado_atual)){
            imprimir_configuracao(fita, pos, estado_atual);
            printf("ACEITA\n");
            free(fita);
            return;
        }
    }
}

// Funcao estatica para inserir entrada de palavra
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

// Funcao estatica para expandir fita em caso da fita voltar a esquerda (preenche com branco)
static void expandir_fita_esquerda(char** fita, int* pos)
{
    int comprimento = strlen(*fita);
    char* nova = malloc((comprimento + 2) * sizeof(char));

    nova[0] = '_';
    strcpy(nova + 1, *fita);

    free(*fita);
    *fita = nova;
    *pos = 0;
}

// Funcao estatica para encontrar transicao valida
// Retorno: retorna a transicao valida ou nulo se invalida
static Elem* encontrar_transicao(Elem* l, char caractere, int estado_atual)
{
    while(l != NULL){
        if(l->info.estado_atual == estado_atual && l->info.simbolo_lido == caractere)
            return l;

        l = l->prox;
    }
    return NULL;
}

// Funcao estatica para verificar se um determinado estado eh final
// Retorno: 1 se for final, 0 se nao
static int eh_estado_final(Maquina maquina, int estado)
{
    register int i;

    for(i = 0; maquina.estados_finais[i] != -1; i++){
        if(maquina.estados_finais[i] == estado)
            return 1;
    }
    return 0;
}

// Funcao estatica para imprimir a fita atual
static void imprimir_configuracao(char* fita, int pos, int estado)
{
    register int i;

    printf("*");
    for(i = 0; i < pos; i++){
        printf("%c", fita[i]);
    }
    printf("[q%d]", estado);

    for(i = pos; i < strlen(fita); i++){
        printf("%c", fita[i]);
    }
    printf("\n");
}


