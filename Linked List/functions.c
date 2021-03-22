#include "LinkedList.h"

struct list{
        int value;
        int size;
        struct list *next;
};

struct list *head;
struct list *tail;

struct list *start()
{
        struct list *new = malloc(sizeof(struct list));

        new->value = 0;
        new->size = 0;
        new->next = NULL;

        return new;
}

void insert(int *value)
{
        struct list *new = malloc(sizeof(struct list));

        new->value = *value;
        if(head->size == 0){
                head = new;
                tail = new;
        }else{
                tail->next = new;
                tail = new;
        }
        new->next = NULL;
        head->size++;
}

void delete(int *value)
{
        struct list *aux = head;
        struct list *before = head;
        int cont = 0;
        int length = head->size;

        while(aux->value != *value){
                aux = aux->next;
                if(cont>=1){
                        before = before->next;
                }
                cont++;
        }

        if(cont == 0){
                head = head->next;
                free(aux);
                length--;
        }else if(cont == length-1){
                tail = before;
                before->next = NULL;
                free(aux);
                length--;

        }else{
                before->next = aux->next;
                free(aux);
                length--;

        }
        head->size = length;
}

void update(int *out, int *in)
{
        struct list *aux = head;
        int flag = 0;
        
        while(aux!=NULL){
                if(aux->value == *out){
                        aux->value = *in;
                        flag = 1;
                        break;
                }
                aux = aux->next;
        }
        if(flag == 0){
                printf("O número não existe na lista\n");
        }

}

void printar()
{
        struct list *aux = head;
        int count=1;
        printf("--------- LISTA ---------\n");
        
        while(aux!=NULL){
                printf("|      %d. %d           |\n",count,aux->value);
                aux = aux->next;
                count++;
        }
        printf("------------------------\n");
        printf("Size: %d\n",head->size);
}

void init()
{
        head = start();
        int choice = 1;
        while(choice!=5){
                choice = menu();
                direct(&choice);
        }
}

int menu()
{
        int choice;
        printf("--------- MENU ---------\n");
        printf("| 1. Adicionar a lista |\n");
        printf("| 2. Retirar da lista  |\n");
        printf("| 3. Atualizar a lista |\n");
        printf("| 4. Mostrar a lista   |\n");
        printf("| 5. Sair do programa  |\n");
        printf("------------------------\n");
        printf("O que você deseja fazer? ");
        scanf("%d",&choice);
        getchar();

        return choice;
}

void direct(int *choice)
{
        int valor;
        int in;
        switch (*choice){
        case 1:
                printf("Digite o valor para inserção: ");
                scanf("%d",&valor);
                getchar();

                insert(&valor);
                break;
        case 2:
                printf("Digite o valor para deletar: ");
                scanf("%d",&valor);
                getchar();

                delete(&valor);
                break;
        case 3:
                printf("Digite o valor que deseja retirar: ");
                scanf("%d",&valor);
                getchar();

                printf("Digite o valor que deseja inserir: ");
                scanf("%d",&in);
                getchar();

                update(&valor, &in);
                break;
        case 4:
                printf("\n");
                printar();
                printf("\n");
                break;
        default:
                if(*choice!=5){
                        printf("tente novamente, valor invalido!\n");
                }
                break;
        }
}