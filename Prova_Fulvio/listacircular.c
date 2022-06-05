#include "listacircular.h"

Noc* cria_noc(int valor)
{
    return (Noc*) cria_no(valor);
}

Noc* insere_circular(int valor, Noc *L)
{
    Noc *novo = cria_noc(valor);
    Noc * aux;
    if(L == NULL)
    {
        L = novo;
        L->prox = novo;
    }
    else
    {
        aux = L;
        while (aux->prox != L)
            aux = aux->prox;

        aux->prox = novo;
        novo->prox = L;
        L = novo;
    }
    return L;
}

Noc* remove_circular(int valor, Noc *L)
{
    Noc *aux = L, *ant=NULL, *aux2;

    if (L != NULL)
    {
        while (aux->prox != L && aux->info != valor)
        {
            ant = aux;
            aux=aux->prox;
        }
        if(aux->info == valor)
        {
            if(aux == aux->prox)
                L=NULL;
            else if (ant != NULL)
                ant->prox = aux->prox;
            else
            {
                aux2=L;
                while (aux2->prox != L)
                    aux2 = aux2->prox;
                //ultimo elemento aponta para o novo primeiro elemento
                aux2->prox = L->prox;
                //
                L = aux->prox;
            }

        }
        free(aux);
    }
    return L;
}


Noc* libera_listac(Noc *L)
{
    Noc *aux = L;
    Noc *aux2 = aux->prox;

    while (aux2 != L)
    {
        aux = aux2;
        aux2 = aux2->prox;
        free(aux);
    }
    free(L);
    return NULL;
}

void mostra_listac(Noc* L)
{
    Noc* aux = L;
    do
    {
        printf(" %i ", aux->info);
        aux = aux->prox;
    }
    while (aux!=L);
}

int tamanhp(Noc *L1){
    Noc* aux = L1;
    int tam = 1;
    if(L1 != NULL){
        while(aux->prox != L1){
            aux = aux->prox;
            tam ++;
        }
    }
    return tam;

}
int localiza(Noc *L1,int valor){
    Noc *aux = L1;
    int resposta = -1;
    if(L1 != NULL){
        while(aux->prox != L1 && aux->info != valor){
            aux = aux->prox;
        }
        if(aux->info == valor){
            resposta = 1;
        }

    }
    return resposta;
}
Noc *interseccao(Noc *L1, Noc *L2){
    Noc *aux1 = L1;
    Noc *aux2 = L2;
    Noc *aux3 = L1;
    Noc *aux4 = L1;
    Noc *aux5 = L2;
    int achei = -1;
    int tamanho_L1 = tamanhp(L1);
    int tamanho_Geral = 1;
    Noc *lista_inter = NULL;
    //verifica primeiro caso
    if(L1 != NULL && L2 != NULL){
        if(L1->info == L2->info){
                lista_inter = insere_circular(L1->info,lista_inter);
        }
    //caso no meio
        while(aux2->prox != L2){
            while(aux1->prox != L1 && aux1->info != aux2->info){
                aux1 = aux1->prox;
            }
            if(aux1->prox != L1 && aux1->info == aux2->info){
                //garante a não repet
                achei = localiza(lista_inter,aux2->info);
                if(achei != 1){
                    lista_inter = insere_circular(aux2->info,lista_inter);
                }

            }
            aux1 = aux3;
            aux2 = aux2->prox;
        }
        while(aux4->prox != L1){
            aux4 = aux4->prox;
        }
         while(aux5->prox != L2){
            aux5 = aux5->prox;
        }
        if(aux4->info == aux5->info){
            achei = localiza(lista_inter,aux5->info);
            if(achei != 1){
                lista_inter = insere_circular(aux5->info,lista_inter);
            }

        }


    }
    return lista_inter;
}









