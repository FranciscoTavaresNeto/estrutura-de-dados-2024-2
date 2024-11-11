#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{   //dados do cliente bancário
    char nome [20];
    int operacao;
    float valor;
    int id;
    struct cliente *proximo;
}Cliente;


typedef struct fila{   //atributos de Fila
    Cliente *inicio; //inicio
    Cliente *fim;
    int qtd;
}Fila;



Fila * criaFila(){
    Fila *fl  = (Fila *)malloc(sizeof(Fila));
    fl->inicio = NULL; //inicialização da fila
    fl->fim = NULL;
    fl->qtd = 0;
    return fl;
}

Cliente* cadastraNovoCliente(char nome [] , int op, double vl, int id ){
    Cliente *novo = (Cliente *)malloc (sizeof(Cliente));
    strcpy(novo->nome,nome);
    novo->operacao = op;
    novo->valor = vl;
    novo->proximo = NULL;
    novo->id = id;
    return novo;
}

void enfileirar(Fila *fl, Cliente *cl){
    if(fl->inicio == NULL){ //Fila Vazia
        fl->inicio = cl;
    }else{          //Fila com elementos
        fl->fim->proximo = cl;
    }
    cl->proximo = NULL;
    fl->fim = cl;
    fl->qtd++;
}

Cliente* desenfileirar(Fila *fl){
    Cliente *aux = fl->inicio;
    if(aux == NULL)   //Fila vazia
        printf("\nErro - Fila Vazia\n");
    else{       //Lista com elementos
        fl->inicio = aux->proximo;
        fl->qtd--;
        aux->proximo = NULL;
        if(fl->inicio == NULL)
            fl->fim = NULL;
    }
    return aux;
}

void mostraCliente(Cliente cl){
    printf("\n Id:%d \n\t Nome: %s \n\t Operacao %d \n\t Valor=%.2f \n",cl.id,cl.nome,cl.operacao,cl.valor);
}

void mostraFila(Fila *fl){
    printf("\nInício da Fila\n");
    Cliente *aux = fl->inicio;
    while(aux != NULL){
        mostraCliente(*aux);
        aux = aux->proximo;
    }
    printf("\nFim da Fila\n");
}

void apagaCliente(Cliente *cl){
    """Apaga um elemento da Fila""";
    printf("\n Apagado!");
    free(cl);
}

void apagaFila(Fila *fl){
    Cliente *aux = desenfileirar(fl);
    while(aux!= NULL){
        aux = desenfileirar(fl);
        apagaCliente(aux);
    }
    printf("\nFila Vazia - Qtd = %d\n",fl->qtd);
}



void menuCaixa(Fila *fG, Fila *fP, Fila *fGG, Fila *fGP, int sG, int sP, Fila *logC, Fila *logG){
    int op, pr;
    Cliente *cl;
    char nome[20];
    float vl;
    do{
        printf("\n\nInforme uma Opção:");
        printf("\n -- 1 - para Atendimento no Caixa:");
        printf("\n -- 2 - para Atendimento com o Gerente:");
        printf("\n -- 3 - Chamar Cliente:");
        printf("\n -- 4 - Quadro de Atendimento:");
        printf("\n -- 5 - Log Dump:");
        printf("\n -- 0 - para Sair do Programa:\n");
        printf("\nInforme sua Opçao:");
        scanf("%d",&op);
        fflush(stdin);

        switch(op){
            case 1:{
                printf("\n Atendimento Caixa \n");
                printf("Informe o seu nome:");
                scanf("%s",nome);
                printf("Informe a operacao 1-saque | 2-deposito:");
                scanf("%d",&op);
                if (op != 1 && op != 2)
                {
                    printf("\n Opcao Inválida!");
                    break;
                }
                printf("Informe o Valor:");
                scanf("%f",&vl);
                printf("Cliente Prioritário? 1-sim | 0-nao");
                scanf("%d",&pr);
                switch (pr)
                {
                case 1:
                    enfileirar(fP,cadastraNovoCliente(nome,op,vl,sG++));
                    break;
                case 0:
                    enfileirar(fG,cadastraNovoCliente(nome,op,vl,sG++));
                    break;
                default:
                    printf("\n Opcao Inválida!");
                    break;
                }
                printf("\n Senha Gerada com Sucesso");}
            break;
            case 2:{
                printf("\n Atendimento Gerente \n");
                op = 0;
                vl = 0;
                printf("Informe o seu nome:");
                scanf("%s",nome);
                printf("Cliente Prioritário? 1-sim | 0-nao");
                scanf("%d",&pr);
                switch (pr)
                {
                case 1:
                    enfileirar(fGP,cadastraNovoCliente(nome,op,vl,sG++));
                    break;
                case 0:
                    enfileirar(fGG,cadastraNovoCliente(nome,op,vl,sG++));
                    break;
                default:
                    printf("\n Opcao Inválida!");
                    break;
                }
                printf("\n Senha Gerada com Sucesso");}
            break;
            case 3:{
                printf("\n Chamar cliente (1-caixa 2-gerencia)\n");
                scanf("%d",&op);
                int count = 0;
                if (op == 1) {
                    if (count < 2)
                    {
                        cl = desenfileirar(fP);
                        if(cl!=NULL){
                            mostraCliente(*cl);
                            enfileirar(logC, cl);
                            apagaCliente(cl);
                            count++;
                        }
                    } else {
                        cl = desenfileirar(fG);
                        if(cl!=NULL){
                            mostraCliente(*cl);
                            enfileirar(logC, cl);
                            apagaCliente(cl);
                            count = 0;
                        }
                    }
                }else {
                    if (count < 2)
                    {
                        cl = desenfileirar(fGP);
                        if(cl!=NULL){
                            mostraCliente(*cl);
                            enfileirar(logG, cl);
                            apagaCliente(cl);
                            count++;
                        }
                    } else {
                        cl = desenfileirar(fGG);
                        if(cl!=NULL){
                            mostraCliente(*cl);
                            enfileirar(logG, cl);
                            apagaCliente(cl);
                            count = 0;
                        }
                    }
                }
            }
            break;
            case 4:{
                printf("Últimos Clientes Atendidos: \n");
                Cliente *ultimoC = logC->inicio;
                Cliente *ultimoG = logG->inicio;
                Cliente *auxC = logC->inicio;
                Cliente *auxG = logG->inicio;
                while(auxC->operacao == ultimoC->operacao){
                    auxC = auxC->proximo;
                }
                while(auxG->operacao == ultimoG->operacao){
                    auxG = auxG->proximo;
                }
                mostraCliente(*ultimoC);
                mostraCliente(*auxC);
                mostraCliente(*ultimoG);
                mostraCliente(*auxG);
            }
            break;
            case 5:
                printf("Log Dump: \n");
                mostraFila(logC);
                mostraFila(logG);
            break;
            default:
                printf("\nOpção Inválida!!\n");
        }
    }while(op>0);
}

int main(){
    int sGeral = 1, sPrio = 1;
    Fila *fCaixaGeral, *fCaixaPrio, *fGerenteGeral, *fGerentePrio, *logCaixa, *logGerente;
    logCaixa = criaFila();
    logGerente = criaFila();
    fCaixaGeral = criaFila();
    fCaixaPrio = criaFila();
    fGerenteGeral = criaFila();
    fGerentePrio = criaFila();
    menuCaixa(fCaixaGeral,fCaixaPrio, fGerenteGeral, fGerentePrio, sGeral, sPrio, logCaixa, logGerente);
    return 1;
}