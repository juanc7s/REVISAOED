#include <stdio.h>
#include <stdlib.h>
#include "REV.h"

void menu()
{   
    
    int op;
    while(1){
        system("clear");
        printf("Criar:\n1: Pilha\n2: Fila\n3: Lista duplamente encadeada\n4: Árvore\n5: Sair\nOpção: ");
        scanf("%d",&op);
        switch (op)
        {   
            
            case 1:
                system("clear");
                menuPilha();
                break;

            case 2:
                system("clear");
                menuFila();
                break;

            case 3:
                system("clear");
                menuLista();
                break;
            
            case 4:
                system("clear");
                menuArvore();
                break;

            case 5:
                system("clear");
                return;
            
            default:
                system("clear");
                printf("Opção inválida");
                break;
        }
    }

}
//PILHA
void menuPilha()
{   int op;
    int valor;
    pilha* stack;
    no* topasso;
    stack= criarPilha();
    while(1)
    {   
        imprimirPilha(stack);
        printf("1: Verificar se está vazia\n2: Verificar o valor do topo\n3: Adicionar valor\n4: Retirar da pilha\n5: Sair e apagar pilha\nOpção: ");
        scanf("%d",&op);
        switch (op)
        {   
            case 1:
                system("clear");

                if(vazia(stack)==1)
                {
                    printf("Pilha Vazia\n");
                    break;
                }
                printf("Pilha com  elementos\n");
                break;

            case 2:
                system("clear");
                if(vazia(stack)==1)
                {
                    printf("Pilha Vazia. Adicione elementos\n");
                    break;
                }
                topasso=topo(stack);
                printf("O valor do topo é %d\n",topasso->item);
                break;

            case 3:
                system("clear");
                printf("Valor: ");
                scanf("%d",&valor);
                push(stack,valor);
                break;
            
            case 4:
                system("clear");
                if(vazia(stack)==1)
                {
                    printf("Pilha Vazia. Adicione elementos\n");
                    break;
                }
                valor=pop(stack);
                printf("Valor retirado foi %d\n",valor);
                break;

            case 5:
                system("clear");
                liberaPilha(stack);
                return;
            
            
            default:
                system("clear");
                printf("Opção inválida\n");
                break;
        }
    }
}
pilha* criarPilha()
{
    pilha* stack = (pilha*)malloc(sizeof(pilha));
    if (stack==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }   
    stack->tam=0;
    stack->topo=NULL;
    return stack;
}

int vazia(pilha* p)
{
    return p->topo==NULL;
}

void push (pilha* p,int v)
{   
    no* elemento = (no*)malloc(sizeof(no));
    if (elemento==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }  
    elemento->item=v;
    elemento->prox=p->topo;
    p->topo=elemento;
    p->tam++;
}

void imprimirPilha(pilha *p)
{   
    if(vazia(p)==1)
    {
        return;
    }
    no* percorre=p->topo;
    while(percorre!=NULL)
    {   
        printf("%d ",percorre->item);
        percorre=percorre->prox;
    }
    printf("\n");
}

void liberaPilha(pilha* stack)
{
    while(stack->topo!=NULL)
    {
        pop(stack);
    }
    free(stack);
    stack=NULL;
    
}

int pop(pilha* stack)
{
    no* aux = topo(stack);
    int valor = aux->item;
    stack->topo=topo(stack)->prox;
    free(aux);
    aux=NULL;
    stack->tam--;
    return valor;
}

no* topo(pilha* p)
{
    return p->topo;
}
//PILHA

//FILA
void menuFila()
{
    int op;
    int valor;
    fila* bicha;
    bicha= criarFila();
    while(1)
    {   
        imprimirFila(bicha);
        printf("1: Verificar se está vazia\n2: Enfileirar valor\n3: Desenfileirar\n4: Sair e apagar fila\nOpção: ");
        scanf("%d",&op);
        switch (op)
        {   
            case 1:
                system("clear");

                if(vaziaFila(bicha)==1)
                {
                    printf("Fila Vazia\n");
                    break;
                }
                printf("Fila com elementos\n");
                break;

            case 2:
                system("clear");
                printf("Valor: ");
                scanf("%d",&valor);
                enfileirar(bicha,valor);
                break;
            
            case 3:
                system("clear");
                if(vaziaFila(bicha)==1)
                {
                    printf("Fila Vazia. Adicione elementos\n");
                    break;
                }
                valor=desenfileirar(bicha);
                printf("Valor desenfileirado foi %d\n",valor);
                break;

            case 4:
                system("clear");
                liberarFila(bicha);
                return;
            
            
            default:
                system("clear");
                printf("Opção inválida\n");
                break;
        }
    }   
}

fila* criarFila()
{
    fila* bicha = (fila*)malloc(sizeof(fila));
    if (bicha==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }   
    bicha->inicio=NULL;
    bicha->fim=NULL;
    return bicha;
}

void imprimirFila(fila* bicha)
{
    if(vaziaFila(bicha)==1)
    {
        return;
    }
    no* percorre=bicha->inicio;
    while(percorre!=NULL)
    {   
        printf("%d ",percorre->item);
        percorre=percorre->prox;
    }
    printf("\n");
}

int vaziaFila(fila* f)
{
    return (f->inicio==NULL && f->fim==NULL);
}

void enfileirar(fila* f,int v)
{   
    no* elemento = (no*)malloc(sizeof(no));
    if (elemento==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }  
    elemento->item=v;
    elemento->prox=NULL;
    if (vaziaFila(f)==1)
    {
        f->fim=elemento;
        f->inicio=elemento;
        return;
    }
    f->fim->prox=elemento;
    f->fim=elemento;

}

int desenfileirar(fila* f)
{
    no* aux = f->inicio;
    int valor = aux->item;
    f->inicio=aux->prox;
    free(aux);
    aux=NULL;
    if(f->inicio==NULL)
    {
        f->fim=NULL;
    }
    return valor; 
}

void liberarFila(fila* f)
{
    while(f->inicio!=NULL)
    {
        desenfileirar(f);
    }
    free(f);
    f=NULL;
}
//FILA

//LISTA DUPLAMENTE ENCADEADA
void menuLista()
{
    int op;
    int valor;
    int pos;
    lista* line;
    line = criarLista();
    while(1)
    {   
        imprimeLista(line);
        printf("1: Verificar se está vazia\n2: Inserir valor no fim\n3: Inserir no inicio\n4: Inserir numa posição\n5: Remover do inicio\n6: Remover do fim\n7: Remover de uma posição\n8: Remover Elemento\n9: Sair e apagar lista \nOpção: ");
        scanf("%d",&op);
        switch (op)
        {   
            case 1:
                system("clear");

                if(vaziaLista(line)==1)
                {
                    printf("Lista Vazia\n");
                    break;
                }
                printf("Lista com elementos\n");
                break;

            case 2:
                system("clear");
                printf("Valor: ");
                scanf("%d",&valor);
                inserirFim(line,valor);
                break;
            
            case 3:
                system("clear");
                printf("Valor: ");
                scanf("%d",&valor);
                inserirInicio(line,valor);
                break;

            case 4:
                system("clear");
                printf("Valor e posição: ");
                scanf("%d %d",&valor,&pos);
            
                if ((vaziaLista(line)!=1) && (pos>=line->tam || pos<0 ) && line->tam!=0)
                {
                    printf("Posição inválida\n");
                    break;
                }

                
                inserirPosicao(line,valor,pos);
                break;


            case 5:
                system("clear");
                if(vaziaLista(line)==1)
                {
                    printf("Lista Vazia. Adicione elementos\n");
                    break;
                }
                valor=removeInicio(line);
                printf("Valor retirado foi %d\n",valor);
                break;

            case 6:
                system("clear");
                if(vaziaLista(line)==1)
                {
                    printf("Lista Vazia. Adicione elementos\n");
                    break;
                }
                valor=removeFim(line);
                printf("Valor retirado foi %d\n",valor);
                break;

            case 7:
                system("clear");
                if(vaziaLista(line)==1)
                {
                    printf("Lista Vazia. Adicione elementos\n");
                    break;
                }
                printf("Posição: ");
                scanf("%d",&pos);
                if (pos>=line->tam || pos<0 )
                {
                    printf("Posição inválida\n");
                    break;
                }
                valor=removePosicao(line,pos);
                printf("Valor retirado foi %d\n",valor);
                break;
            
            case 8:
                system("clear");
                if(vaziaLista(line)==1)
                {
                    printf("Lista Vazia. Adicione elementos\n");
                    break;
                }
                printf("Valor a ser retirado: ");
                scanf("%d",&valor);
                valor=removeChave(line,valor);
                printf("Valor retirado foi %d\n",valor);
                break;

            case 9:
                system("clear");
                liberaLista(line);
                return; 
            
            default:
                system("clear");
                printf("Opção inválida\n");
                break;
        }
    }   
}

lista* criarLista()
{
    lista* line = (lista*)malloc(sizeof(lista));
    if (line==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }   
    line->inicio=NULL;
    line->tam=0;
    return line;
}

int vaziaLista(lista* l)
{
    return(l->inicio==NULL);
}

void inserirFim(lista* l,int valor)
{
    obj* elemento = (obj*)malloc(sizeof(obj));
    obj* percorre = l->inicio;
    if (elemento==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }  
    elemento->item=valor;
    elemento->prox=NULL;
    if (vaziaLista(l)==1)
    {
        l->inicio=elemento;
        elemento->ant=NULL;
        l->tam++;
        return;
    }
    while(percorre->prox!=NULL)
    {
        percorre=percorre->prox;
    }
    percorre->prox=elemento;
    elemento->ant=percorre;
    l->tam++;
}

void imprimeLista(lista* l)
{
    if(vaziaLista(l)==1)
    {
        return;
    }
    obj* percorre=l->inicio;
    while(percorre!=NULL)
    {   
        printf("%d ",percorre->item);
        percorre=percorre->prox;
    }
    printf("\n");
}

void inserirInicio(lista* l, int valor)
{
    obj* elemento = (obj*)malloc(sizeof(obj));
    if (elemento==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }
    l->tam++;
    elemento->ant=NULL;
    elemento->item=valor;
    if (vaziaLista(l)!=1)
    {
        l->inicio->ant = elemento; 
        elemento->item=valor;
        elemento->prox=l->inicio;
        l->inicio=elemento;
        return;
        
    }
    l->inicio=elemento;
    elemento->prox=NULL;
    
}

void liberaLista(lista* l)
{
    while(l->inicio!=NULL)
    {
        removeInicio(l);
    }
    free(l);
    l=NULL;
}

int removeInicio(lista* l)
{
    obj* aux = l->inicio;
    int valor = aux->item;
    l->inicio=aux->prox;
    free(aux);
    aux=NULL;
    l->tam--;
    return valor;  
}

void inserirPosicao(lista* l,int valor,int pos)
{
    if (pos==0 || vaziaLista(l)==1)
    {
        inserirInicio(l,valor);
        return;
    }

    if(pos==(l->tam-1))
    {
        inserirFim(l,valor);
        return;
    }

    obj* novo=(obj*)malloc(sizeof(obj));
    obj* aux;
    novo->item=valor;
    obj* percorre=l->inicio;
    for (int i = 0; i < pos+1; i++)
    {
        percorre=percorre->prox;
    }
    aux=percorre->ant->ant;
    percorre->ant->ant=novo;
    novo->prox=percorre->ant;
    novo->ant=aux;
    aux->prox=novo;
    
    l->tam++;
}

int removeFim(lista* l)
{
    obj *item = l->inicio;
    obj * anterior;
    while(item->prox!=NULL)
    {   
        anterior=item;
        item=item->prox;
    }
    anterior->prox=NULL;
    int valor = item->item;
    free(item);
    l->tam--;
    return valor;
}

int removePosicao(lista* l,int pos)
{
    obj *item = l->inicio;
    obj * anterior;
    int valor;
    
    if(pos==(l->tam-1))
    {
        valor=removeFim(l);
        return valor;
    }
    for (int i = 0; i < pos; i++)
    {   
        anterior=item;
        item=item->prox;
    }
    anterior->prox=item->prox;
    item->prox->ant=anterior;
    valor=item->item;
    l->tam--;
    free(item);

    return valor;
}

int removeChave(lista* l,int valor)
{
    obj* aux = l->inicio;
    obj* anterior;
    int cont=0;
    while(aux!=NULL && aux->item!=valor)
    {   
        anterior=aux;
        aux=aux->prox;
        cont++;
    }

    if(cont==0)
    {
        valor=removeInicio(l);
        return valor;
    }
    
    if(aux->item==valor && aux->prox==NULL) 
    {
        valor=removeFim(l);
        return valor;
    }

    if(aux->prox!=NULL)
    {   
        anterior->prox=aux->prox;
        aux->prox->ant=anterior;
        free(aux);
        l->tam--;
        return valor;

    }
    printf("Valor não encontrado\n");
    return 3550;
}
//LISTA DUPLAMENTE ENCADEADA

//ÁRVORE
void menuArvore()
{
    int op;
    int valor;
    no2* raizi = (no2*)malloc(sizeof(no2));
    arvore* tree;
    tree = criarArvore();
    while(1)
    {   
        //dfs(tree);
        //bfs(tree);
        printf("1: Verificar se está vazia\n2: Inserir\n3: retirar\n4: Sair e apagar Árvore\nOpção: ");
        scanf("%d",&op);
        switch (op)
        {   
            case 1:
                system("clear");

                if(vaziaArvore(tree)==1)
                {
                    printf("Árvore Vazia\n");
                    break;
                }
                printf("Árvore com elementos\n");
                break;

            case 2:
                system("clear");
                printf("Valor: ");
                scanf("%d",&valor);
                if(vaziaArvore(tree)==1)
                {
                    raizi;
                    break;
                }
                
                break;
            
            case 3:
                system("clear");
                if(vaziaArvore(tree)==1)
                {
                    printf("Arvore Vazia. Adicione elementos\n");
                    break;
                }
                
                printf("Valor desenfileirado foi %d\n",valor);
                break;

            case 4:
                system("clear");
                
                return;
            
            
            default:
                system("clear");
                printf("Opção inválida\n");
                break;
        }
    }   
}

arvore* criarArvore()
{
    arvore* tree = (arvore*)malloc(sizeof(arvore));
    if (tree==NULL)
    {
        printf("Sem memória\n");
        exit(1);
    }   
    tree->raiz=NULL;
    return tree;
    
}

int vaziaArvore(arvore* a)
{
    return (a->raiz==NULL);
}

//ÁRVORE
