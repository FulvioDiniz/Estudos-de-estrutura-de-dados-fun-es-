#include "listadupla.h"

Listad* cria_listad()
{
    Listad* novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Nod* cria_nod(int valor)
{
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->info = valor;
    return novo;
}


Listad* insere_inicio_listad(Listad *L, int valor)
{
    Nod *novo= cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;

    }
    else
    {
        if (L->ini == NULL)
            L->ini = L->fim = novo;
        else
        {
            novo->prox = L->ini;
            L->ini->ant = novo;
            L->ini = novo;
        }
    }
    return L;

}



void mostra_listad(Listad* L)
{
    Nod* aux = L->ini;

    while(aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n ");
}

Listad* insere_fim_listad(Listad* L, int valor)
{
    Nod *novo = cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;
    }
    else
    {


        if(L->ini == NULL)
        {
            L->ini = L->fim = novo;
        }
        else
        {
            novo->ant = L->fim;
            L->fim->prox = novo;
            L->fim = novo;
        }
    }
    return L;
}

Nod* localiza_elemento(Listad *L, int valor)
{

    Nod* aux = L->ini;

    while(aux!=NULL && aux->info != valor)
        aux = aux->prox;

    return aux;
}


void insere_apos_elemento(Listad* L, int valor, int elemento)
{
    Nod* novo =cria_nod(valor);

    Nod *aux2, *aux = localiza_elemento(L, elemento);

    if (aux != NULL)
    {
        aux2 = aux->prox;
        novo->prox = aux2;
        aux2->ant = novo;
        novo->ant = aux;
        aux->prox = novo;
        if (aux == L->fim)
            L->fim = novo;
    }
    else
        printf("elemento nao encontrado");
}

int remove_inicio_listad(Listad *L)
{
    Nod* aux;
    int resposta = -1;//quando nao tem nada pra remover
    if (L!=NULL)
        if (L->ini != NULL)
        {
            aux = L->ini;

            if (L->ini != L->fim)
            {
                L->ini->prox->ant = NULL;
                L->ini = L->ini->prox;
            }
            else
                L->ini = L->fim = NULL;

            resposta = aux->info;
            free(aux);
        }
    return resposta;
}

int remove_fim_listad(Listad *L)
{
    Nod* aux;
    int resposta = -1;

    if(L != NULL && L->fim != NULL)
    {
        aux = L->fim;
        if(L->ini != L->fim)//mais de um elemento na lista
        {
            L->fim->ant->prox = NULL;
            L->fim = L->fim->ant;
        }
        else//só tem um elemento na lista
            L->ini = L->fim = NULL;

        resposta = aux->info;
        free(aux);
    }
    return resposta;
}

int remove_elemento_listad(Listad *L, int valor)
{
    Nod *aux = localiza_elemento(L,valor);
    int resposta = -1;

    if (aux != NULL)
    {
        if (aux == L->ini)
            resposta = remove_inicio_listad(L);
        else if(aux == L->fim)
            resposta = remove_fim_listad(L);
        else
        {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            resposta = aux->info;
            free(aux);
        }
    }
    return resposta;
}

Listad* libera_listad(Listad *L)
{
    Nod *aux = L->ini;

    while (aux != NULL)
    {
        L->ini = L->ini->prox;
        free(aux);
        aux = L;
    }

    free(L);
    return NULL;

}


int contador_elemento(Listad *lista,int elemento){
    Nod *aux = lista->ini;
    int valor = elemento;
    int verdade = -1;
    int cont = 0;
    if(lista != NULL){
        //while(verdade = 1){
            while(aux != NULL){
                if(aux->info == valor){
                    cont++;
                    aux = aux->prox;
                }
                else{
                    aux = aux->prox;
                }
            }
        //}
    }
    return cont;
}

/*int conta_todos(Listad *lista){
    Nod *aux = lista->ini;
    Listad *lista1 = lista;
    int cont;
    int x;
    if(lista != NULL){
        while(aux != NULL){
            x = contador_elemento(lista);
            if(x != 1){
                lista1 = remove_inicio_listad(lista);
            }

        }
        cont = tamanhp(lista1);
        return cont;
    }

}*/
int tamanho (Listad *lista){
    Nod *aux = lista->ini;
    int tam = 1;
    if(lista != NULL){
        while(aux != NULL){
            aux = aux->prox;
            tam++;
        }

    }
    return tam;



}

Listad *lista_ord(Listad *lista){
    Nod *aux = lista->ini;
    Listad *ord = NULL;
    int tam1, tam2;
    tam1 = tamanho(lista);
    int maior = lista->ini->info;
    if(lista != NULL){
        while(tam1 != tam2){
            while(aux != NULL){
               if(aux->info > maior){
                    ord = insere_inicio_listad(ord,aux->info);
                    maior = aux->info;
                }
                else{
                    ord = insere_fim_listad(ord,aux->info);
                }
                tam2 = tamanho(ord);
                aux = aux->prox;
            }

        }
        return ord;
    }






}






