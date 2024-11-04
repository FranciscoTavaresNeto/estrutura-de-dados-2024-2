#include <stdio.h>
#include <locale.h> /*alara acentuação*/
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia, mes, ano;
}Data;

typedef struct vacina{
    char nome [20];
    char fabricante [20];
    Data validade;
}Vacina;

typedef struct cao{
    char nome [15]; 
    int idade;
    Data dNascimento;
    Vacina carterinha [10];
    int qtVacinas;
}Cao;

void mostraData(Data dt){
   //imprime um data passada por valor
   printf("\n Data de Nascimento: %d/%d/%d \n", dt.dia, dt.mes,dt.ano);
}

void mostraVacina(Vacina vc){
    //imprime um vacina passada por valor
    printf("\n Nome: %d ",vc.nome);
    printf("\n Fabricante: %d ",vc.fabricante);
    mostraData(vc.validade);
}

void mostraDadosCao(Cao dog){
    //imprime dados de um cão passado por valor
    printf("\n Nome: %s ",dog.nome[0]);
    printf("\n Idade: %d ",dog.idade);
    mostraData(dog.dNascimento);
    printf("\n teste: %d", sizeof(dog.carterinha));
    sizeof(dog.carterinha);
    //loop para imprimir carteirinha
}

Data cadastraData(int d, int m, int a){
    //cadastra e retorna uma nova data, passagem por valor
}

void cadastraVacina(Vacina *vc){
    //recebe um poteiro de Vacina e preenche os campos do ponteiro "Passagem por referencia"
}

void cadastraCao(Cao *dog){
    //recebe um poteiro de cao e preenche os campos do ponteiro "Passagem por referencia"
}

void vacinacao(Cao *dog, Vacina vc){
    //representa a realização da vacina em um cao
}

Cao* cruzamento(Cao pai, Cao mae){
    //recebe dados de dois caes e retorna um ponteiro para um novo cao com os nomes dos pais

}

int main()
{
    //system("clear");
    setlocale(LC_ALL, "");    

    //implemente o controle de vacina de 4 cães da família X;
    Data Hoje = {04,10,2024};
    Cao tofu = {"Tofu", 5, {04,10,2024}};
    mostraDadosCao(tofu);    
    exit(0);
}
