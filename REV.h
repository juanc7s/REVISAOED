#ifndef REV_H
#define REV_H

void menu();


//PILHA
typedef struct _no{
    int item;
    struct _no *prox;
} no;

typedef struct _pilha{
    int tam;
    no *topo;
}pilha;

pilha* criarPilha();
int vazia(pilha* p);
no* topo(pilha* p);
void push (pilha* p,int v);
int pop(pilha* p);
void imprimirPilha(pilha *p);

void liberaPilha(pilha* stack);
void menuPilha();

//PILHA

//FILA
//FILA OBJETO É IGUAL AO DA PILHA
typedef struct{
    no* inicio;
    no* fim;
}fila;

fila* criarFila();
int vaziaFila(fila* f);
void enfileirar(fila* f,int v);
int desenfileirar(fila* f);
void liberarFila(fila* f);

void imprimirFila(fila* bicha);
void menuFila();
//FILA

//LISTA DUPLAMENTE ENCADEADA
typedef struct _obj{
    int item;
    struct _obj *prox;
    struct _obj *ant;
}obj;

typedef struct _lista{
    int tam;
    obj* inicio;
}lista;

lista* criarLista();
int vaziaLista(lista* l);
void inserirInicio(lista* l, int valor);
void inserirFim(lista* l,int valor);
void inserirPosicao(lista* l,int valor,int pos);
int removeInicio(lista* l);
int removeFim(lista* l);
int removePosicao(lista* l,int pos);
int removeChave(lista* l,int valor);
void imprimeLista(lista* l);
void liberaLista(lista* l);

void menuLista();
//LISTA DUPLAMENTE ENCADEADA

//ÁRVORE
typedef struct _no2{
    int item;
    struct _no2 *esq;
    struct _no2 *dir;
}no2;

typedef struct _arvore{
    no2 *raiz;
}arvore;

arvore* criarArvore();
void criarRaiz(arvore* a);
int vaziaArvore(arvore* a);
void inserirEsquerda(no* n, int valor);
void inserirDireita(no* n, int valor);
void liberaArvore(arvore *a);
void bfs(arvore* a);
void dfs(arvore* a);

void menuArvore();

//Árvore

#endif