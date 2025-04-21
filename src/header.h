#ifndef MAQUINA_DE_TURING_H_
#define MAQUINA_DE_TURING_H_

typedef struct lista* Lista;
typedef struct lista Elem;

typedef struct{
    int estado_atual;
    char simbolo_lido;
    int proximo_estado;
    char simbolo_escrito;
    char direcao_fita;
}Transicoes;

struct lista{
    Transicoes info;
    struct lista* prox;
};

typedef struct{
    int num_estados;
    int* estados_finais;
    char* alfabeto;
    Lista* transicoes;
}Maquina;

Lista* criar_lista();

void inserir_transicao(Lista* l, Transicoes x);

Lista* liberar_lista(Lista* l);

void imprimir_lista(Lista* l);

Lista* inverter_lista(Lista* l1, Lista* l2);

#endif // MAQUINA_DE_TURING_H_
