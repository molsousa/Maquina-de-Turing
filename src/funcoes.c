#include <stdio.h>
#include <stdlib.h>
#include "header.h"

static void liberar(Elem* l);
static void inverter(Lista* l, Elem* copia);

Lista* criar_lista()
{
    Lista* novo = (Lista*) (malloc(sizeof(Lista)));
    if(!novo){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    *novo = NULL;

    return novo;
}

void inserir_transicao(Lista* l, Transicoes x)
{
    Elem* novo = (Elem*) malloc(sizeof(Elem));
    if(!novo){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    novo->info = x;
    novo->prox = *l;

    *l = novo;
}

Lista* liberar_lista(Lista* l)
{
    liberar(*l);

    return NULL;
}

static void liberar(Elem* l)
{
    if(l == NULL)
        return;

    liberar(l->prox);

    free(l);
}

void imprimir_lista(Lista* l)
{
    Elem* aux;

    for(aux = *l; aux != NULL; aux = aux->prox)
        printf("(%d,%c = %d,%c,%c)\n", aux->info.estado_atual, aux->info.simbolo_lido, aux->info.proximo_estado,
                                        aux->info.simbolo_escrito, aux->info.direcao_fita);
}

Lista* inverter_lista(Lista* l1, Lista* l2)
{
    inverter(l1, *l2);

    return l1;
}

static void inverter(Lista* l, Elem* copia)
{
    Elem* aux;

    for(aux = copia; aux != NULL; aux = aux->prox)
        inserir_transicao(l, aux->info);
}
