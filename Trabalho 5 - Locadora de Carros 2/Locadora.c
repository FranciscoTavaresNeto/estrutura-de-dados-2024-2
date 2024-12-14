#include <stdio.h>
#include <stdlib.h>

/*  TAREFAS PENDENTES

*/

typedef struct tarefa
{
    char descricao [30];
    int id, prioridade;
    struct tarefa *anteiror;
    struct tarefa *proximo;
}Tarefa;

typedef struct LDE
{
    Tarefa *primeiro;
    Tarefa *ultimo;
    int qtd;
}LDE;

Tarefa* criaTarefa(int id){
    Tarefa *nova = (Tarefa*)malloc(sizeof(Tarefa));
    printf("\nInforme a Tarefa:");
    scanf("%s",nova->descricao);
    nova->id = id;
    printf("Informe a Prioridade:");
    scanf("%d",&nova->prioridade);
    nova->anteiror = NULL;
    nova->proximo = NULL;
    return nova;
}

LDE* criaListaLDE(){
    LDE *nova = (LDE*)malloc(sizeof(LDE));
    nova->primeiro = NULL;
    nova->ultimo = NULL;
    nova->qtd = 0;
    return nova;
}

void mostraTarefa(Tarefa tf){
    printf("\n Tafera N° %d",tf.id);
    printf("\n\t Descricao: %s",tf.descricao);
    printf("\n\t Prioridade: %d\n",tf.prioridade);
}

void insereInicio(LDE *lt, Tarefa *tf){
    tf->anteiror = NULL;
    if(lt->primeiro == NULL){
        //ListaVazia
        tf->proximo = NULL;
        lt->ultimo = tf;
    }else{
        tf->proximo = lt->primeiro;
        lt->primeiro->anteiror = tf;
    }
    lt->primeiro = tf;
    lt->qtd++;
}

void insere(LDE *lt, Tarefa *tf, int pos){
    // tratar erro de posicao invalida na lista
    /*
    Tarefa *aux = lt.primeiro;
    if(lt->primeiro == NULL){
        tf->anterior = NULL;
        tf->proximo = NULL;
        lt->ultimo = tf;
        lt->primeiro = tf;
    }else{
        for (int i = 0; i < pos; i++)
        {
            aux = aux->proximo;
        }

        tf->proximo = lt->primeiro;
        lt->primeiro->anteiror = tf;
    }
    lt->qtd++;
    */
}

void insereFim(LDE *lt, Tarefa *tf){
    tf->proximo = NULL;
    if(lt->ultimo == NULL){
        insereInicio(lt,tf);
    }else{
        tf->anteiror = lt->ultimo;
        lt->ultimo->proximo = tf;
        lt->ultimo = tf;
        lt->qtd++;
    }
}

void removeInicio(LDE *lt, Tarefa *tf){
    tf->anteiror = NULL;
    if(lt->primeiro == NULL){
        //ListaVazia
        tf->proximo = NULL;
    }else{
        tf->proximo = lt->primeiro;
        lt->primeiro->anteiror = tf;
    }
    lt->primeiro = tf;
    lt->qtd++;
}

void mostraLista(LDE lt){
    //Mostrar Lista do inicio ao fim
    Tarefa *aux = lt.primeiro;
    if(aux == NULL)
        printf("\n    LISTA VAZIA! \n");
    while(aux != NULL){
        mostraTarefa(*aux);
        aux = aux->proximo;
    }
}

void menu(LDE *lt){
    int opcao = 0, posicao, id=1;
    Tarefa *aux;
    do{
        printf("\n 1 - Insere no Inicio");
        printf("\n 2 - Insere no Fim");
        printf("\n 3 - Insere na Posição");
        printf("\n 4 - Remove no Inicio");
        printf("\n 5 - Remove no Fim");
        printf("\n 6 - Remove na Posicao");
        printf("\n 7 - Mostrar uma Tarefa Posicao");
        printf("\n 8 - Mostra Lista ED");
        printf("\n 9 - Mostra Lista DE");
        printf("\n 10 - Apaga Lista");
        printf("\n Informe uma Opcao:");
        scanf("%d",&opcao);

        switch(opcao){
        case 1:
            insereInicio(lt,criaTarefa(id++));
        break;
        case 2:
            insereFim(lt,criaTarefa(id++));
        break;
        case 3:
            printf("\n Informe a Posicao");
            scanf("%d",&posicao);
            //inserePosicao(lt,criaTarefa(id++),posicao);
        break;
        case 4:
            //aux = removeInicio(lt);
            free(aux);
        break;
        case 5:
           // aux = removeFim(lt);
            free(aux);
        break;
        case 6:
            printf("\n Informe a Posicao");
            scanf("%d",&posicao);
            //aux = removePosicao(lt,posicao);
            free(aux);
        break;
        case 7:
            printf("\n Informe a Posicao");
            scanf("%d",&posicao);
            //navegar/ a ate a posição e mostrar
        break;
        case 8:
            mostraLista(*lt);
        break;
        case 9:
            //mostraListaDE(*lt);
        break;
        case 10:
            free(lt);
        break;
        default:
            printf("\n Opção Invalida!!");
        }
     }while(opcao!= 0);
}

int main(){

    int id = 1, opcao = 1;
    LDE *mLista;
    mLista = criaListaLDE();
    menu(mLista);
}