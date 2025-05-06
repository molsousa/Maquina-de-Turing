#ifndef HEADER_H_
#define HEADER_H_

// Definicao de tipo para lista encadeada
typedef struct lista* Lista;
// Definicao de tipo para manipulacao de lista encadeada
typedef struct lista Elem;

// Definicao de estrutura para especificacao de transicao
typedef struct{
    int estado_atual;
    char simbolo_lido;
    int proximo_estado;
    char simbolo_escrito;
    char direcao_fita;
}Transicoes;

// Estrutura para lista encadeada
struct lista{
    Transicoes info;
    struct lista* prox;
};

// Definicao de estrutura para Maquina de Turing
typedef struct{
    int num_estados;
    int* estados_finais;
    char* alfabeto;
    Lista* transicoes;
}Maquina;

// Funcao para criacao de lista encadeada
// Pre-condicao: ponteiro para lista criado
// Pos-condicao: cria lista vazia
Lista* criar_lista();

// Funcao para inserir elemento (transicao) na lista
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
void inserir_transicao(Lista* l, Transicoes x);

// Funcao para liberar lista encadeada
// Pre-condicao: lista criada
// Pos-condicao: retorna nulo para ponteiro para lista
Lista* liberar_lista(Lista* l);

// Funcao para imprimir lista encadeada [DEBUG]
// Pre-condicao: lista criada
// Pos-condicao: nenhuma
void imprimir_lista(Lista* l);

// Funcao para inverter lista encadeada
// Pre-condicao: lista criada
// Pos-condicao: retorna ponteiro para lista invertida
Lista* inverter_lista(Lista* l1, Lista* l2);

// Funcao de menu para usuario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void menu();

#endif // HEADER_H_
