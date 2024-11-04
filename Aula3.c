#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia,mes,ano;
}Data;

const Data Hoje = {04,10,2024};

typedef struct pessoa{
    int cod;
    char nome [10];
    char sobrenome [20];
    int idade;
    char telefone [15];
    Data nascimento;
}Pessoa;

void imprimePessoa(Pessoa novaPessoa){
    printf("\n Código %d ",novaPessoa.cod);
    printf("\n Nome: %s %s",novaPessoa.nome,novaPessoa.sobrenome);
    printf("\n Idade: %d e Telefone: %s ",novaPessoa.idade,novaPessoa.telefone);
    printf("\n Data de Nascimento: %d/%d/%d \n",
         novaPessoa.nascimento.dia,novaPessoa.nascimento.mes,novaPessoa.nascimento.ano);
};

int calcularIdade(Pessoa pessoa){
    int idade = Hoje.ano - pessoa.nascimento.ano;
    if(Hoje.mes < pessoa.nascimento.mes)
        idade--;
    else{
        if(Hoje.mes == pessoa.nascimento.mes)
            if(Hoje.dia < pessoa.nascimento.dia)
                idade--;
    }
    //printf("\n Idade= %d",idade);
    
    return idade;
}

void atualizaIdade(Pessoa *pessoa){
    //ponteiro pessoa, referencia idade ->
    pessoa->idade = calcularIdade(*pessoa);
}

void atualizaTelefone(Pessoa *pessoa){
    printf("\n Informe o novo Telefone: ");
    scanf("%s",pessoa->telefone);
}

void preencheDadosPessoa(Pessoa *pessoa, int cod){
    Data dNascimento;
    pessoa->cod = cod;
    printf("\n Informe seu nome:");
    scanf("%s",pessoa->nome);
    printf("\n Informe seu sobrenome:");
    scanf("%s",pessoa->sobrenome);
    printf("\n Informe seu telefone:");
    scanf("%s",pessoa->telefone);
    printf("\n Informe seu dada nascimento:");
    scanf("%d %d %d",&dNascimento.dia,&dNascimento.mes,&dNascimento.ano);
    pessoa->nascimento = dNascimento;
    pessoa->idade = calcularIdade(*pessoa);
}

int main(){

    Data natal = {25,10,2000};
    Pessoa joao;
    joao.cod = 1;
    joao.idade = 50;
    strcpy(joao.nome,"Joao");
    strcpy(joao.sobrenome,"Farias de Souza");
    strcpy(joao.telefone,"5332324567");
    joao.nascimento = natal;


    Pessoa maria = 
        {2,"Maria","Aparecida",0,"53323244411",Hoje};
        
    imprimePessoa(joao);    
    
    atualizaIdade(&joao);
    atualizaTelefone(&joao);

    imprimePessoa(joao);

    atualizaIdade(&maria);
    imprimePessoa(maria);

    Pessoa nova;
    preencheDadosPessoa(&nova,3);
    imprimePessoa(nova);


    
}


