#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "MT/carregar_arquivo.h"
#include "MT/verificar_palavra.h"

// Funcao estatica para liberar lista encadeada
static void liberar(Elem* l);
// Funcao estatica para inverter lista encadeada
static void inverter(Lista* l, Elem* copia);
// Funcao estatica para liberar Maquina de Turing
static void liberar_maquina(Maquina maquina);

// Funcao para criacao de lista encadeada
// Pre-condicao: ponteiro para lista criado
// Pos-condicao: cria lista vazia
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

// Funcao para inserir elemento (transicao) na lista
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
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

// Funcao para liberar lista encadeada
// Pre-condicao: lista criada
// Pos-condicao: retorna nulo para ponteiro para lista
Lista* liberar_lista(Lista* l)
{
    liberar(*l);

    return NULL;
}

// Funcao estatica para liberar lista encadeada
static void liberar(Elem* l)
{
    if(l == NULL)
        return;

    liberar(l->prox);

    free(l);
}

// Funcao para imprimir lista encadeada [DEBUG]
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
void imprimir_lista(Lista* l)
{
    Elem* aux;

    for(aux = *l; aux != NULL; aux = aux->prox)
        printf("(%d,%c = %d,%c,%c)\n", aux->info.estado_atual, aux->info.simbolo_lido, aux->info.proximo_estado,
                                        aux->info.simbolo_escrito, aux->info.direcao_fita);
}

// Funcao para inverter lista encadeada
// Pre-condicao: lista criada
// Pos-condicao: retorna ponteiro para lista invertida
Lista* inverter_lista(Lista* l1, Lista* l2)
{
    inverter(l1, *l2);

    return l1;
}

// Funcao estatica para inverter lista encadeada
static void inverter(Lista* l, Elem* copia)
{
    Elem* aux;

    for(aux = copia; aux != NULL; aux = aux->prox)
        inserir_transicao(l, aux->info);
}

// Funcao de menu para usuario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void menu()
{
    Maquina maquina;
    int opcao;
    int flag = 0;
    system("color D");

    do{
        printf("<----------MAQUINA-DE-TURING---------->\n");
        printf("|\t1 - CARREGAR ARQUIVO          |\n");
        printf("|\t2 - VERIFICAR PALAVRA         |\n");
        printf("|\t0 - SAIR                      |\n");
        printf("<------------------------------------->\n");
        printf("Insira: ");
        scanf("%d%*c", &opcao);

        system("cls");
        switch(opcao){

        case 1:
            carregar_arquivo(&maquina);
            flag = 1;
            break;

        case 2:
            verificar_palavra(maquina);
            system("pause");
            system("cls");
            break;

        case 0:
            system("cls");
            printf("Obrigado!!\n");
            break;

        default:
            printf("Opcao invalida, tente novamente\n");
        }
    }while(opcao != 0);

    if(flag)
        liberar_maquina(maquina);
}

// Funcao estatica para liberar Maquina de Turing
static void liberar_maquina(Maquina maquina)
{
    maquina.transicoes = liberar_lista(maquina.transicoes);
    free(maquina.alfabeto);
    free(maquina.estados_finais);
}

