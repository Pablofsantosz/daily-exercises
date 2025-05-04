#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    int info;
    struct listNode *prox;
    struct listNOde *ant;
}ListNode;

typedef struct list{
    ListNode *inicio;
    ListNode *fim;
    int qtd;
}List;

void inicializar(List *lista){
    lista->inicio=NULL;
    lista->fim= NULL;
    lista->qtd=0;
}

int isEmpty(List lista){
    if(lista.qtd==0){
        return 0;
    }
    else{
        return 1;
    }

}

ListNode *NovoNo(int valor){
    ListNode *novo;
    novo =(ListNode*) malloc(sizeof(ListNode));
    novo->info = valor;
    novo->ant = NULL;
    novo->prox= NULL;
    return novo;
}

void Inserir_Na_Lista(int value,List *lista){
    if(isEmpty(*lista)==0){
        ListNode *No = NovoNo(value);
        lista->inicio= No;
        lista->fim=No;
        lista->qtd++;
    }
    else {
        ListNode *No = NovoNo(value);
        No->ant= lista->fim;
        lista->fim->prox = No;
        lista->fim= No;
        lista->qtd++;
    }

}
void Imprimir_Termos(List lista){
    if(isEmpty(lista)==0){
        printf("A lista está vazia \n");
    }
    else {
        ListNode * aux;
        aux = lista.inicio;
        printf("//Termos dentro da lista//\n");
        while(aux != NULL){
            printf("[%d]",aux->info);
            aux= aux->prox;
        }
    }
}

List  Somar_Listas(List *lista1,List* lista2){
    List  Lista3 ;
    inicializar(&Lista3);
    ListNode *auxl1,*auxl2;
    int aux;

    auxl1 = lista1->inicio;
    auxl2 = lista2->inicio;

    while (auxl1 != NULL && auxl2 != NULL){
        aux = auxl1->info + auxl2->info;
        Inserir_Na_Lista(aux,&Lista3);
        auxl1= auxl1->prox;
        auxl2=auxl2->prox;
    }  
    
    return Lista3;
}


int main (){
    List lista1,lista2,lista3;
    inicializar(&lista1);inicializar(&lista2);inicializar(&lista3);
    int opcao, valor;
    do {
        printf("\n====== MENU ======\n");
        printf("1. Inserir na Lista 1\n");
        printf("2. Inserir na Lista 2\n");
        printf("3. Imprimir Lista 1\n");
        printf("4. Imprimir Lista 2\n");
        printf("5. Somar Lista 1 e Lista 2 e mostrar Lista 3\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor para inserir na Lista 1: ");
                scanf("%d", &valor);
                Inserir_Na_Lista(valor, &lista1);
                break;
            case 2:
                printf("Valor para inserir na Lista 2: ");
                scanf("%d", &valor);
                Inserir_Na_Lista(valor, &lista2);
                break;
            case 3:
                printf("Lista 1: ");
                Imprimir_Termos(lista1);
                break;
            case 4:
                printf("Lista 2: ");
                Imprimir_Termos(lista2);
                break;
            case 5:
                lista3 = Somar_Listas(&lista1, &lista2);
                printf("Lista 3 (soma): ");
                Imprimir_Termos(lista3);
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);
    



    return 0;
}