#include "listacircular.h"
#include "listacircular.h"
int main(){
    struct listad *lista;
    struct listad *ord;
    lista = cria_listad();
    int contador= 0;

    lista = insere_inicio_listad(lista,3);
    lista = insere_inicio_listad(lista,3);
    lista = insere_inicio_listad(lista,3);
    lista = insere_inicio_listad(lista,3);
    lista = insere_inicio_listad(lista,4);
    lista = insere_inicio_listad(lista,5);
    lista = insere_inicio_listad(lista,7);
    lista = insere_inicio_listad(lista,6);
    mostra_listad(lista);
    contador = contador_elemento(lista,3);
    //contador = conta_todos(lista);
    printf("%d",contador);
    printf("\n");
    ord = lista_ord(lista);
    mostra_listad(ord);








    Noc *L1 = NULL;
    Noc *L2 = NULL;
    Noc *L3 = NULL;
    int reposta;
    int tamaho;
    L1 = insere_circular(5,L1);
    L1 = insere_circular(2,L1);
    L1 = insere_circular(3,L1);
    L1 = insere_circular(3,L1);
    L1 = insere_circular(4,L1);
    L1 = insere_circular(6,L1);
    L2 = insere_circular(8,L2);
    L2 = insere_circular(3,L2);
    L2 = insere_circular(3,L2);
    L2 = insere_circular(2,L2);
    L2 = insere_circular(8,L2);
    L2 = insere_circular(3,L2);

    printf("Lista L1:");
    mostra_listac(L1);
    printf("\n");
    printf("Lista L2:");
    mostra_listac(L2);
    printf("\n");
    reposta = localiza(L1,6);
    printf("%d",reposta);
    tamaho = tamanhp(L1);
    printf(" tamanho :%d",tamaho);
    printf("Lista L3:");
    L3 = interseccao(L1,L2);
    mostra_listac(L3);





}
